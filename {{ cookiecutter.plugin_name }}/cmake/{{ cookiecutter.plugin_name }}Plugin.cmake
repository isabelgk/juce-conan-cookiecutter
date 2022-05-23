# build VST3 for all platforms, add AU on MacOS
set(PLUGIN_FORMATS VST3)
if (CMAKE_SYSTEM_NAME STREQUAL Darwin)
    LIST(APPEND PLUGIN_FORMATS AU)
endif()

juce_add_plugin({{ cookiecutter.plugin_name.capitalize()}}Plugin
    COMPANY_NAME "{{ cookiecutter.author_name }}"
    IS_SYNTH {% if cookiecutter.is_instrument %} TRUE {% else %} FALSE {% endif %}
    NEEDS_MIDI_INPUT {% if cookiecutter.is_instrument or cookiecutter.is_midi_effect %} TRUE {% else %} FALSE {% endif %}
    NEEDS_MIDI_OUTPUT {% if cookiecutter.is_midi_effect %} TRUE {% else %} FALSE {% endif %}
    IS_MIDI_EFFECT {% if cookiecutter.is_midi_effect %} TRUE {% else %} FALSE {% endif %}
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD FALSE
    PLUGIN_MANUFACTURER_CODE "{{ cookiecutter.manufacturer_code }}"  # A four-character manufacturer id with at least one upper-case character
    PLUGIN_CODE "{{ cookiecutter.plugin_code }}"
    FORMATS ${PLUGIN_FORMATS}  # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
    PRODUCT_NAME "{{ cookiecutter.plugin_name }}"
    )

# `juce_generate_juce_header` will create a JuceHeader.h for a given target, which will be generated
# into your build tree. This should be included with `#include <JuceHeader.h>`. The include path for
# this header will be automatically added to the target. The main function of the JuceHeader is to
# include all your JUCE module headers; if you're happy to include module headers directly, you
# probably don't need to call this.

{% if cookiecutter.uses_juce_header %}
juce_generate_juce_header({{ cookiecutter.plugin_name.capitalize() }}Plugin)
{% endif %}


target_sources({{ cookiecutter.plugin_name.capitalize() }}Plugin
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../src/PluginEditor.cpp
        ${CMAKE_CURRENT_LIST_DIR}/../src/PluginEditor.h
        ${CMAKE_CURRENT_LIST_DIR}/../src/PluginProcessor.cpp
        ${CMAKE_CURRENT_LIST_DIR}/../src/PluginProcessor.h
    )

# include_directories()


# `target_compile_definitions` adds some preprocessor definitions to our target. In a Projucer
# project, these might be passed in the 'Preprocessor Definitions' field. JUCE modules also make use
# of compile definitions to switch certain features on/off, so if there's a particular feature you
# need that's not on by default, check the module header for the correct flag to set here. These
# definitions will be visible both to your code, and also the JUCE module code, so for new
# definitions, pick unique names that are unlikely to collide! This is a standard CMake command.

target_compile_definitions({{ cookiecutter.plugin_name.capitalize() }}Plugin
    PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0
    )

# `target_link_libraries` links libraries and JUCE modules to other libraries or executables. Here,
# we're linking our executable target to the `juce::juce_audio_utils` module. Inter-module
# dependencies are resolved automatically, so `juce_core`, `juce_events` and so on will also be
# linked automatically. If we'd generated a binary data target above, we would need to link to it
# here too. This is a standard CMake command.

target_link_libraries({{ cookiecutter.plugin_name.capitalize() }}Plugin
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
    )

# Samples and/or presets
if(HAS_BINARY_RESOURCES)
    target_link_libraries({{ cookiecutter.plugin_name.capitalize() }}Plugin PRIVATE BinaryResources)
endif()


#include "PluginProcessor.h"

class {{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor : public juce::AudioProcessorEditor {
public:
    {{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor({{ cookiecutter.plugin_name.capitalize() }}Processor&);
    ~{{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor() override;
	
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    {{ cookiecutter.plugin_name.capitalize() }}Processor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR({{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor)
};

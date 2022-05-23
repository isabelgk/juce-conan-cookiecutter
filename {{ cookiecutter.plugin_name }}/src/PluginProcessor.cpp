#include "PluginProcessor.h"
#include "PluginEditor.h"


{{ cookiecutter.plugin_name.capitalize() }}Processor::{{ cookiecutter.plugin_name.capitalize() }}Processor()
    : AudioProcessor(BusesProperties()
            {% if cookiecutter.is_audio_effect %}
                         .withInput("Input", juce::AudioChannelSet::stereo())
            {% endif %}
            {% if cookiecutter.is_audio_effect or cookiecutter.is_instrument %}
                         .withOutput("Output", juce::AudioChannelSet::stereo())
            {% endif %}
            {% if cookiecutter.has_sidechain %}
                         .withInput("Sidechain", juce::AudioChannelSet::stereo()))
            {% endif %}
{}

{{ cookiecutter.plugin_name.capitalize() }}Processor::~{{ cookiecutter.plugin_name.capitalize() }}Processor() {}

const juce::String {{ cookiecutter.plugin_name.capitalize() }}Processor::getName() const {
    return Jucecookiecutter.plugin_name;
}

bool {{ cookiecutter.plugin_name.capitalize() }}Processor::acceptsMidi() const {
    {% if cookiecutter.is_midi_effect or cookiecutter.is_instrument %}
    return true;
    {% else %}
    return false;
    {% endif %}
}

bool {{ cookiecutter.plugin_name.capitalize() }}Processor::producesMidi() const {
    {% if cookiecutter.is_midi_effect%}
    return true;
    {% else %}
    return false;
    {% endif %}
}

bool {{ cookiecutter.plugin_name.capitalize() }}Processor::isMidiEffect() const {
    {% if cookiecutter.is_midi_effect%}
    return true;
    {% else %}
    return false;
    {% endif %}
}

double {{ cookiecutter.plugin_name.capitalize() }}Processor::getTailLengthSeconds() const {
    return 0.0;
}

int {{ cookiecutter.plugin_name.capitalize() }}Processor::getNumPrograms() {
    return 1;
}

int {{ cookiecutter.plugin_name.capitalize() }}Processor::getCurrentProgram() {
    return 0;
}

void {{ cookiecutter.plugin_name.capitalize() }}Processor::setCurrentProgram(int index) {}

const juce::String {{ cookiecutter.plugin_name.capitalize() }}Processor::getProgramName(int index) {
    return {};
}

void {{ cookiecutter.plugin_name.capitalize() }}Processor::changeProgramName(int index, const juce::String &newName) {}

void {{ cookiecutter.plugin_name.capitalize() }}Processor::prepareToPlay(double sampleRate, int samplesPerBlock) {}

void {{ cookiecutter.plugin_name.capitalize() }}Processor::releaseResources() {}


bool {{ cookiecutter.plugin_name.capitalize() }}Processor::isBusesLayoutSupported(const BusesLayout &layouts) const {
    return layouts.getMainInputChannelSet() == layouts.getMainOutputChannelSet()
           && !layouts.getMainInputChannelSet().isDisabled();
}


void {{ cookiecutter.plugin_name.capitalize() }}Processor::processBlock(juce::AudioBuffer<float> &buffer,
    juce::MidiBuffer& midiMessages) {
    }

juce::AudioProcessorEditor *{{ cookiecutter.plugin_name.capitalize() }}Processor::createEditor() {
    return new {{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor(*this);
    // return new juce::GenericAudioProcessorEditor(*this);
}

bool {{ cookiecutter.plugin_name.capitalize() }}Processor::hasEditor() const {
    return true;
}

void {{ cookiecutter.plugin_name.capitalize() }}Processor::getStateInformation(juce::MemoryBlock &destData) {}

void {{ cookiecutter.plugin_name.capitalize() }}Processor::setStateInformation(const void *data, int sizeInBytes) {}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new {{ cookiecutter.plugin_name.capitalize() }}Processor();
}

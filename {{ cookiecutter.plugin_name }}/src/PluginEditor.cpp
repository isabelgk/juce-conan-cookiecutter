#include "PluginEditor.h"
#include "PluginProcessor.h"

{{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor::{{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor({{ cookiecutter.plugin_name.capitalize() }}Processor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 300);
}

{{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor::~{{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor() {}

void {{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor::paint(juce::Graphics &g) {
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("Hello!", getLocalBounds(), juce::Justification::centred, 1);
}

void {{ cookiecutter.plugin_name.capitalize() }}ProcessorEditor::resized() {
}

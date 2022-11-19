/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyFirstPluginAudioProcessorEditor::MyFirstPluginAudioProcessorEditor (MyFirstPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 600);

    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical);
    gainSlider.setRange(-60.0f, 0.0f, 0.01f);
    gainSlider.setValue(0.0f);
    gainSlider.addListener(this); //pointing AudioProcessorEditorClass

    addAndMakeVisible(&gainSlider);
}

MyFirstPluginAudioProcessorEditor::~MyFirstPluginAudioProcessorEditor()
{
}

//==============================================================================
void MyFirstPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // fill the whole window white
    g.fillAll(juce::Colours::black);

    // set the current drawing colour to black
    g.setColour(juce::Colours::white);

    // set the font size and draw text to the screen
    g.setFont(15.0f);

    g.drawFittedText("Nick's Gain Slider", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
    g.drawFittedText("this does exactly what it says it does...", 0, 20, getWidth(), 30, juce::Justification::centred, 1);
     
}

void MyFirstPluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 200, 100, 400);
}

void MyFirstPluginAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &gainSlider) {
        audioProcessor.gain = gainSlider.getValue();
    }
}
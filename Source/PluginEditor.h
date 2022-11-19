/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MyFirstPluginAudioProcessorEditor  : public juce::AudioProcessorEditor, 
                                           public juce::Slider::Listener
{
public:
    MyFirstPluginAudioProcessorEditor (MyFirstPluginAudioProcessor&);
    ~MyFirstPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;

private:
    juce::Slider gainSlider;

    MyFirstPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyFirstPluginAudioProcessorEditor)
};

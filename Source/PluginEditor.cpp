/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ReverbAudioProcessorEditor::ReverbAudioProcessorEditor (ReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    loadIRButton.setButtonText ("Load Impulse Response");
    loadIRButton.onClick = [this] { loadImpulseResponse(); };
    addAndMakeVisible (&loadIRButton);

    /*
    addAndMakeVisible(bypassButton);
    bypassButton.setButtonText("Bypass");
    bypassButton.onClick = [this]
    {
        audioProcessor.bypassParameter->setValueNotifyingHost(bypassButton.getToggleState() ? 1.0f : 0.0f);
    };
    
    //bypassButton.onClick = [this] { audioProcessor.bypassParameter->setValue(bypassButton.getToggleState()); };

    // Set the initial state of the bypass button to match the processor's parameter
    bypassButton.setToggleState(p.bypassParameter->get(), juce::dontSendNotification);
     */
    setSize (400, 300);
}

ReverbAudioProcessorEditor::~ReverbAudioProcessorEditor()
{
}

//==============================================================================
void ReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void ReverbAudioProcessorEditor::resized()
{
    loadIRButton.setBounds (10, 10, getWidth() - 20, 30);
    // Position the bypass button
    bypassButton.setBounds(10, 10, 100, 30);
}

void ReverbAudioProcessorEditor::loadImpulseResponse()
{
    //juce::FileChooser chooser ("Select an Impulse Response file...", juce::File::getSpecialLocation(juce::File::userDesktopDirectory), "*.wav;*.aif;*.aiff");
    
    juce::FileChooser chooser ("Select an Impulse Response file...", {}, "*.wav;*.aif;*.aiff");
       if (chooser.browseForFileToOpen())
       {
           juce::File irFile = chooser.getResult();
           audioProcessor.loadImpulseResponse(irFile);
       }
    
}

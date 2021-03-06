/*
 ==============================================================================
 
 This file contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#pragma once
#include    "../JuceLibraryCode/JuceHeader.h"

#include <juce_audio_processors/juce_audio_processors.h>
#include "OJDParameters.h"


//==============================================================================
/**
 */
class DrumMapperAudioProcessor : public jb::PluginAudioProcessorBase<OJDParameters>, public juce::AudioProcessorValueTreeState::Listener
{
public:
    //==============================================================================
    DrumMapperAudioProcessor();
    
    //==============================================================================
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void prepareResources (bool sampleRateChanged, bool maxBlockSizeChanged, bool numChannelsChanged) override;
    void parameterChanged (const juce::String &parameterID, float newValue) override;
    
    
#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported(const BusesLayout &layouts) const override;
#endif
    
    void processBlock(juce::dsp::AudioBlock<float> &, juce::MidiBuffer &);
    void processBlock(juce::dsp::AudioBlock<float> &) override;
    
    //==============================================================================
    juce::AudioProcessorEditor *createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const juce::String getName() const override;
    
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    
    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String &newName) override;
    
    //==============================================================================
    void getStateInformation(juce::MemoryBlock &destData) override;
    void setStateInformation(const void *data, int sizeInBytes) override;
    
private:
    //    juce::AudioParameterInt *noteInNumber;
    //    juce::AudioParameterInt *noteVelocityThreshold;
    //    juce::AudioParameterInt *noteOutNumber;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DrumMapperAudioProcessor)
};

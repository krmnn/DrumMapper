/*
 
 This file is part of the Schrammel OJD audio plugin.
 Copyright (C) 2020  Janos Buttgereit
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software Foundation,
 Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "OJDLookAndFeel.h"

class OJDAudioProcessorEditor;

/** Some constants derived from the GUI design */
struct OJDEditorConstants
{
    static constexpr int   presetManagerComponentHeight = 20;
    static constexpr int   contentMinHeight             = 568;
    static constexpr int   overallMinHeight             = presetManagerComponentHeight + contentMinHeight;
    static constexpr int   contentMinWidth              = 310;
    static constexpr float contentAspectRatio           = 0.5876168224f;
};

class ProcessorEditor  : public jb::PluginEditorBase<OJDEditorConstants::contentMinWidth, OJDEditorConstants::overallMinHeight>,
public OJDEditorConstants
{
public:
    ProcessorEditor (DrumMapperAudioProcessor&);
    ~ProcessorEditor() override;
    
    //==============================================================================
    void constrainedResized() override;
    void checkBounds (juce::Rectangle<int>& bounds, const juce::Rectangle<int>&, const juce::Rectangle<int>&, bool, bool, bool, bool) override;
    void paint (juce::Graphics& g) override;
    
private:
    void addPresetManager (DrumMapperAudioProcessor& processorToControl);
    void setupAndAddMessageOfTheDayComponents();
    
    void checkMessageOfTheDay (DrumMapperAudioProcessor& processor);
    void setMessage (const juce::String& text, const juce::URL url);
    
    //jb::SVGComponent background;
    
    bool isInMessageState;
    juce::TextEditor messageEditor;
    juce::TextButton messageOkButton;
    juce::TextButton messageLearnMoreButton;
    
    //const std::unique_ptr<juce::Drawable> knobDrawable;
    
    //OJDLookAndFeel ojdLookAndFeel;
    
    std::unique_ptr<jb::PresetManagerComponent> presetManagerComponent;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ProcessorEditor)
};

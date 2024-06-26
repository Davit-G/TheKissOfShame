#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUIUtilities/BacklightComponent.h"
#include "GUIUtilities/CustomButton.h"
#include "GUIUtilities/CustomKnob.h"
#include "GUIUtilities/EnvironmentsComponent.h"
#include "GUIUtilities/ImageInteractor.h"
#include "GUIUtilities/ImageAnimationComponent.h"
#include "Parameters.h"

class KissOfShameAudioProcessorEditor : public juce::AudioProcessorEditor,
                                        public juce::Timer,
                                        public juce::Slider::Listener,
                                        public juce::Button::Listener
{
public:
    KissOfShameAudioProcessorEditor(KissOfShameAudioProcessor&);
    ~KissOfShameAudioProcessorEditor() override;

    void timerCallback() override;

    void sliderValueChanged(juce::Slider*) override;
    void buttonClicked(juce::Button* b) override;

    void mouseDoubleClick(const juce::MouseEvent &event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;
    void mouseDrag(const juce::MouseEvent& event) override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    void setReelMode(bool showReels);
    void setBypassButtonValue(float newValue);
    void setShowReelsValue(float newValue);
    void setLinkButtonValue(float newValue);

    KissOfShameAudioProcessor& audioProcessor;

    // Images
    BacklightComponent backlight;
    ImageInteractor faceImage;

    // Knobs
    CustomKnob inputSaturationKnob;
    CustomKnob shameKnob;
    CustomKnob hissKnob;
    CustomKnob blendKnob;
    CustomKnob outputKnob;
    CustomKnob ageKnob;

    // Buttons
    CustomButton bypassButton;
    CustomButton tapeTypeButton;
    CustomButton printThroughButton;
    CustomButton linkIOButtonL;
    CustomButton linkIOButtonR;

    // Used strictly to post messages for debugging
    //juce::Label debugLabel;

    // Components
    EnvironmentsComponent environmentsComponent;

    // Animation
    ImageAnimationComponent reelAnimation;
    ImageInteractor vuMeterL;
    ImageInteractor vuMeterR;
    ImageInteractor shameKnobImage;

    int priorProcessorTime;

    juce::AudioProcessorValueTreeState::SliderAttachment inputAttachment {
        audioProcessor.apvts, ParameterIDs::input.getParamID(), inputSaturationKnob
    };
    juce::AudioProcessorValueTreeState::SliderAttachment shameAttachment {
        audioProcessor.apvts, ParameterIDs::shame.getParamID(), shameKnob
    };
    juce::AudioProcessorValueTreeState::SliderAttachment hissAttachment {
        audioProcessor.apvts, ParameterIDs::hiss.getParamID(), hissKnob
    };
    juce::AudioProcessorValueTreeState::SliderAttachment blendAttachment {
        audioProcessor.apvts, ParameterIDs::blend.getParamID(), blendKnob
    };
    juce::AudioProcessorValueTreeState::SliderAttachment ageAttachment {
        audioProcessor.apvts, ParameterIDs::age.getParamID(), ageKnob
    };
    juce::AudioProcessorValueTreeState::SliderAttachment outputAttachment {
        audioProcessor.apvts, ParameterIDs::output.getParamID(), outputKnob
    };

    bool ignoreCallbacks = false;
    juce::ParameterAttachment bypassButtonAttachment;
    juce::ParameterAttachment showReelsAttachment;
    juce::ParameterAttachment linkButtonAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KissOfShameAudioProcessorEditor)
};

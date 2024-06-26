#pragma once

#include "../shameConfig.h"
#include "../Parameters.h"
#include "ImageInteractor.h"

class EnvironmentsComponent : public ImageInteractor
{
public:
    EnvironmentsComponent(juce::AudioParameterChoice& param) :
        parameter(param),
        attachment(
            param,
            [this](float value){ updateImageWithValue(value); },
            nullptr
        )
    {
        setNumFrames(6);
        setMinMaxValues(0, 5);

        setAnimationImage(BinaryData::Environments_png, BinaryData::Environments_pngSize);

        setDimensions(0, 0, 183, 32);
        setSize(183, 32);

        attachment.sendInitialUpdate();
    }

    void setCurrentEnvironment(int index)
    {
        attachment.setValueAsCompleteGesture(float(index));
    }

    void mouseUp(const juce::MouseEvent&) override
    {
        setCurrentEnvironment((parameter.getIndex() + 1) % eNumEnvironments);
    }

private:
    juce::AudioParameterChoice& parameter;
    juce::ParameterAttachment attachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EnvironmentsComponent)
};

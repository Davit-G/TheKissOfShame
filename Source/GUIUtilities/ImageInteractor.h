#pragma once

#include "../shameConfig.h"

class ImageInteractor : public juce::Component
{
public:
    ImageInteractor();

    void paint(juce::Graphics& g) override;

//TODO: I don't think these are used anywhere, so remove them
//    void updateImageWithValue(float value)
//    {
//        if (value > maxValue) {
//            curValue = maxValue;
//        } else if (value < minValue) {
//            curValue = minValue;
//        } else {
//            curValue = value;
//        }
//
//        repaint();
//    }
//
//    void setCurrentValue(float value)
//    {
//        if (value > maxValue) {
//            curValue = maxValue;
//        } else if (value < minValue){
//            curValue = minValue;
//        } else {
//            curValue = value;
//        }
//    }
//
//    void setMinMaxValues(float min, float max)
//    {
//        minValue = min;
//        maxValue = max;
//    }
//
//    void setDesaturate(bool _desaturate)
//    {
//        desaturate = _desaturate;
//
//        if (desaturate) {
//            image = desatImage;
//        } else {
//            image = satImage;
//        }
//
//        repaint();
//    }

    void setNumFrames(int numFrames);
    void setAnimationImage(const juce::String& filePath);
    void setDimensions(int topLeftX, int topLeftY, int w, int h);

private:
    bool desaturate;
    juce::String imagePath;
    juce::Image image;
    juce::Image satImage;
    juce::Image desatImage;
    int frameWidth;
    int frameHeight;
    int numFrames;

    float maxValue, minValue, curValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImageInteractor)
};

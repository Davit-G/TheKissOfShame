/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
KissOfShameAudioProcessor::KissOfShameAudioProcessor() : masterBypass(false)
{
    inputSaturation = 1.0;
    shame = 0.0;
    hiss = 0.0;
    
    
    aGraph = new AudioGraph(getNumInputChannels());
    
}

KissOfShameAudioProcessor::~KissOfShameAudioProcessor()
{
}

//==============================================================================
const String KissOfShameAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int KissOfShameAudioProcessor::getNumParameters()
{
    return 0;
}

float KissOfShameAudioProcessor::getParameter (int index)
{
    // This method will be called by the host, probably on the audio thread, so
    // it's absolutely time-critical. Don't use critical sections or anything
    // UI-related, or anything at all that may block in any way!
    switch (index)
    {
        case inputSaturationParam:     return inputSaturation;
        case shameParam:               return shame;
        case hissParam:                return hiss;
        case blendParam:               return blend;
        case bypassParam:              return masterBypass;
        case outputParam:              return output;
            
        default:                       return 0.0f;
    }

    return 0.0f;
}

void KissOfShameAudioProcessor::setParameter (int index, float newValue)
{
    // This method will be called by the host, probably on the audio thread, so
    // it's absolutely time-critical. Don't use critical sections or anything
    // UI-related, or anything at all that may block in any way!
    switch (index)
    {
        case inputSaturationParam:     inputSaturation = newValue;  break;
        case shameParam:               shame = newValue;  break;
        case hissParam:                hiss = newValue;  break;
        case blendParam:               blend = newValue; break;
        case bypassParam:              masterBypass = newValue; break;
        case outputParam:              output = newValue; break;
            
        default:            break;
    }
}

const String KissOfShameAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String KissOfShameAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String KissOfShameAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String KissOfShameAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool KissOfShameAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool KissOfShameAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool KissOfShameAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool KissOfShameAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool KissOfShameAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double KissOfShameAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int KissOfShameAudioProcessor::getNumPrograms()
{
    return 0;
}

int KissOfShameAudioProcessor::getCurrentProgram()
{
    return 0;
}

void KissOfShameAudioProcessor::setCurrentProgram (int index)
{
}

const String KissOfShameAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void KissOfShameAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void KissOfShameAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void KissOfShameAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void KissOfShameAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    
    aGraph->processGraph(buffer, getNumInputChannels());
    
    
    //Need to send the RMS below to the animation components for VU meters...
    //use juce's messaging system to keep the audio thread safe.
    //audioBuffer.getRMSLevel(0, 0, audioBuffer.getNumSamples());


    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool KissOfShameAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* KissOfShameAudioProcessor::createEditor()
{
    return new KissOfShameAudioProcessorEditor (this);
}

//==============================================================================
void KissOfShameAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void KissOfShameAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new KissOfShameAudioProcessor();
}
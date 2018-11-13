/*
  ==============================================================================

    SynthVoice.h
    Created: 13 Nov 2018 4:10:03pm
    Author:  think

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice
{
public:
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast <SynthSound*>(sound) != nullptr;
    }

    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override
    {
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        level = velocity;
    }

    void stopNote (float velocity, bool allowTailOff) override
    {
        allowTailOff = true;

        if (velocity == 0)
            clearCurrentNote();
    }

    void pitchWheelMoved (int newPitchWheelValue) override
    {

    }

    void controllerMoved (int controllerNumber, int newControllerValue) override
    {

    }

    void renderNextBlock (AudioBuffer <float> &outputBuffer, int startSample, int numSamples) override
    {
        for (int sample = 0; sample < numSamples; ++sample)
        {
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, 1);
            }
            ++startSample;
        }
    }
private:
    double level;
    double frequency;
    int theWave;

    int filterChoice;
    float cutoff;
    float resonance;
};
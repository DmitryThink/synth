/*
  ==============================================================================

    SynthSound.h
    Created: 13 Nov 2018 4:04:57pm
    Author:  think

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber) override
    {
        return true;
    }

    bool appliesToChannel (int midiNoteNumber) override
    {
        return true;
    }
};
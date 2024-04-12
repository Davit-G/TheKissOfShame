# The Kiss of Shame – Tape Desecration Processor

“Something so wrong never sounded so right.”

The Kiss of Shame, debuted at the Audio Engineering Society Convention 2014 in Los Angeles, was a pioneering DAW plugin that leveraged commercial UX/UI design principles to shape its magnetic tape + circuitry emulation algorithms.

![](Docs/blurb.jpg)

To differentiate itself in the competitive pro-audio plugin market, The Kiss of Shame introduced groundbreaking features including an interactive, multi-touch-ready GUI and analog tape degradation simulation for distinctive audio effects.

The Kiss of Shame was the worlds first (and perhaps only) tape / analog circuitry emulation plugin that realistically models the effects of magnetic particle instability, lubricant loss, substrate deformation, drift, scrape-flutter, print-through and reel expansion/contraction into a suite of FX processing tools for sound design and music production.

It was also the first to leverage machine learning to account for the vast nonlinearities inherent in magnetic tape and analog circuitry. Last but not least, it's the only analog tape emulation that has fully-interactive reels that support touch and can write flange automation on-the-fly akin to a real analog tape deck.

![Demo video](Unused/Promotional/TKOS_demo.mp4)

The Kiss of Shame was never released. The source code was graciously donated to the open source community by its owner in 2024. The original code was written for JUCE 3.1. It has been updated to compile with JUCE 7.

> **NOTE:** This repo is currently work-in-progress. There may be issues with the plug-in!

## Installation instructions

TODO

## How to use this plug-in

![](Docs/screenshot.jpg)

**Choose between two distinct tape types:**

**S-111** – A superior reel format popular from the 50s to 70s, was the preferred reference tape for many engineers. The Kiss of Shame introduces its first digital emulation, bringing this legendary format to the digital world.

**A-456** – This classic, high-output/low-noise format is a recording staple used in countless productions. While many software emulations exist, none recreate it quite like this. Unique digital recreation tactics were employed to capture its essence.

**From Weathered to *Weather***:

**Age** – This knob allows the user to legislate the amount of hypothetical time the selected tape type has been subjected to the chosen "Environment" to manipulate the severity of the corresponding effects.

**Environment** – Choose between several simulated storage conditions to inflict the sonic ramifications of factors such as magnetic particle instability, oxidation, lubricant loss, tape pack expansion/contraction, "vinegar syndrome" and more upon the source material. Users can even choose a "Hurricane Sandy" setting to access processing modeled from tape immersed and then recovered from the storm's flood waters.

**A real-world obstacle:**

**Shame** – The Kiss of Shame recreates the full spectrum of these factors like Drift, Wow, Flutter and Scrape-Flutter which the user can impart with the center knob. It can take your source signal from mildly colored to totally mangled.

**Print-Through** – Also known as "bleed-through", this emulation captures the mechanical speed fluctuations present in analog recordings. While they posed challenges for engineers in the past, they became a hallmark of classic records.

**Reach out and touch tape:**

The Kiss of Shame is the first tape plug-in to feature animated, interactive reels that can be manipulated with a simple click or touch. This allows users to access authentic analogue tape flange in real-time, without the need for two physical tape decks, and in a fraction of the time. All parameters, including reel movements, are fully automatable, and for screen real estate optimization, the reels are collapsible and fully customizable.

## Building from source code

Brief instructions:

- Install JUCE 7.
- Open **KissOfShame.jucer** in Projucer and export to your IDE.
- Select the **VST3** or **AU** target and build.

TODO

## TO-DO list

The plug-in was never completely finished. The goal of this open source project is:

1. To finish the plug-in and make binary releases available.
2. Figure out how it works and document the code for eductional purposes.
3. Potentially, clean up and improve the code.

The information about missing features and bugs that I received is as follows:

> As far as the emulations for each Tape Type, Shame knob, storage conditions, those should all be locked, loaded and ready to go. Same with the flange via the automatible reels.
>
> I think we were polishing off the “Print-Through” effect. Just making it usable.
>
> From what I recall, it just had some minor GUI bugs and where we stopped, it’s the parameters would randomly resort to default.

Bugs I found:

- When you drag to apply flanging, I would expect a mouse up to reset the flanging depth. The animation does return to normal speed.

Other things that can be improved in the code:

- Use APVTS for the parameters so they can be automated.
  - Currently the parameters are set from the editor, but there's no guarantee there will be an editor. Closing and reopening the editor will reset all parameters.
  - There are two sets of parameters: 1) the ones used in `AudioGraph::setAudioUnitParameters()`, and 2) copies of these in the processor. None of this is thread-safe. Instead, we should use `AudioParameterFloat` objects and read them in `processBlock`.
  - Implement state saving and loading.
- Embed the external image and sound files as binary data in the plug-in, to simplify the installation (no need to manually copy these resources).
- Remove most of the compiler warnings. (I set the warning level high on purpose.)
- Replace deprecated JUCE APIs with modern equivalents.
- Replace the Biquads with TPT filters.
  - Moving the Age knob from max to min can cause the low-pass filter to give a massive gain boost. Probably because at 0% this uses (close to) 22050 Hz as the cutoff freq. Or just because it's a biquad.
- Explicitly use `juce::` and `std::` namespaces.
- Remove any files that aren't being used (source files, images, audio).
- Don't use `rand()` and `srand()`. Replace with `juce::Random`.
- General code cleanup.
- Making independent of sample rate.
- Use CMake instead of Projucer.

### What is missing

Features this plug-in was supposed to have but that did not appear to be implemented:

- The only environment that's implemented is Hurricane Sandy.
- The print-through button doesn't do anything.
- The tape type selection button has no effect.

Other features to add:

- Parameter smoothing.
- Maybe the flange depth should be skewed so that shorter delays are easier to dial in. (For example by doing `targetDepth = depth * depth * 1000.0f`.)
- Oversampling. The saturation stage can easily add aliases.

## How it works

TODO

## Credits & license

Copyright (C) 2014-2015 Eros Marcello

Original developers:

- [Eros Marcello](https://www.github.com/erosmarcello) — Founder, Chief Product Architect

- [Brian Hansen](https://brianhansen.sonimmersion.com/) — DSP Engineering / Algorithm Development

- [Yannick Bonnefoy](https://nanopsy.tv/) — GUI

Updates and improvements by [Matthijs Hollemans](https://audiodev.blog).

This program is free software: you can redistribute it and/or modify it under the terms of the [GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.en.html) as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

JUCE is copyright © Raw Material Software.

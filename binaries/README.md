# sáb 18 sep 2021 18:36:15 CEST

* switched from stereo freeverb to Eric's adjusted mono reverb. Doesn't have damping but sounds a lot better.

# lun 03 may 2021 22:29:35 CEST

* added an average for beat_ms because slight changes in detected incoming sync would change delay size by a few ms, leading to unwanted
audio artifacts
* slightly increased max noise value
* fixed un-updated freeverb effect with local one

# dom 02 may 2021 14:32:25 CEST

* Added delay sync mode. This uses multiples of the synced BPM to generate the delay times.
* The 2 delay knobs now set between 1 and 16 multiples of the beat time.
* Mode is enabled by default.
* Press and hold 'set to 1' key to toggle on and off.
* Max delay is limited to MAX_DELAY (currently 1200ms).

* Delayed white noise level was too loud so reduced noise amount to half what it was.


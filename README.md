# Teensy FX

* A Teensy 4 based FX box with Pocket Operator style and playability.
* Currently a combination of reverb, ping pong filtered delay and a noise source.
* Playing with settings with [control.py](control.py) as I work on the hardware
* Each knob can be automated (a bit like punch in effects on the Pocket Operators)

# Software

[control.py](control.py) is a PyQT program that was developed in order to make an MVP
interface that could later be translated to hardware in the form of a PCB.

![gui](gui.png)

# Hardware

![board](hardware/board.png)

[schematic](hardware/schematic.pdf)

[gerbers](hardware/teensy-fx-2020-01-11-fab.zip)

## Hardware Resources

Based off the teensy 4 audio board and the [teensy beats shield](https://hackaday.io/project/161127-teensy-beats-shield)

* teensy 4 audio board schematic https://www.pjrc.com/store/schematic_audio4.png
* [SGTL5000 datasheet](https://static6.arrow.com/aropdfconversion/d5e3ddfdb01ac7d0ee29dd23626c23e0eb18a14a/1931605559406471sgtl5000.pdf)
* TLC5947 24 channel PWM LED driver
* 4067 multiplexer for the knobs
* pot RK09K1130AP5

## Hardware todo

* print and check footprints
 * regulator fp comes in 2 varients - check
 * smt sockets for teensy - done
 * pots - done
 * 4067 - done
 * tlc5947 - done
 * sgtl5000 - done
* test some parts? or at least check on the scope the pins are wiggling while fx are happening
* add up 3.3v & 1.8v current and check < 250ma (leds on 5v supply) - done
    - pots: 4mA
    - audio codec: 5mA
* caps for audio, what parts - done
* extra caps for led driver and led circuit - done
* find suppliers - done

## Back graphic

100 x 60mm == 3.94 x 2.36" == 1182 x 708 pix
# FW

Try to fulfil what the [control.py](control.py) program can do.

## Top Level

* each knob controls one of the parameters (see config in control.py)
* each knob has a number of steps of recordable automation (160 in control.py)
* knob's leds brightness shows current value of parameter
* record time is based on bpm tap tempo and number of steps (4 bars in control.py)
* buttons are: tap tempo, record, wipe and start automation loop from beginning
* press record and move a knob to record its movement
* moving a knob without pressing record will wipe the pattern and set it all to the current knob value
* leds for buttons are tempo, if recording, and if wiping
* 4 leds on top right show progression through the bar

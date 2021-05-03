/*
https://forum.pjrc.com/threads/25679-Audio-adapter-schematic

https://www.pjrc.com/teensy/gui/index.html

https://github.com/PaulStoffregen/Audio/tree/master/examples
*/

#include <LEDS.h>
#include <Pots.h>
#include <Button.h>
#include <Control.h>
#include <BarTimer.h>

//16 -> 69 auto generated from audio tool
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoisePink      pink2; //xy=60.000030517578125,799
AudioInputI2S            i2s2;           //xy=63,319
AudioSynthNoisePink      pink1;          //xy=63.000030517578125,744
AudioFilterStateVariable filter_noise_l;        //xy=206.00003051757812,749
AudioFilterStateVariable filter_noise_r; //xy=209.00003051757812,807
AudioAnalyzePeak         peak1;          //xy=227,127
AudioMixer4              mix_del_l;      //xy=312,424
AudioMixer4              mix_del_r;      //xy=320,619
AudioMixer4              mix_rev;         //xy=363.1999969482422,237.1999969482422
AudioFilterStateVariable filter_del_r;   //xy=429,744
AudioFilterStateVariable filter_del_l;   //xy=495,488
AudioFilterStateVariable filter_rev;        //xy=555,183
AudioEffectDelay         delay_r;        //xy=614,867
AudioEffectDelay         delay_l;        //xy=630,571
AudioEffectFreeverbStereo freeverbs1;     //xy=642,279
AudioMixer4              mix_op_l;       //xy=949,382
AudioMixer4              mix_op_r;       //xy=952,475
AudioOutputI2S           i2s1;           //xy=1179,417
AudioConnection          patchCord1(pink2, 0, filter_noise_r, 0);
AudioConnection          patchCord2(i2s2, 0, peak1, 0);
AudioConnection          patchCord3(i2s2, 1, mix_op_r, 0);
AudioConnection          patchCord4(i2s2, 1, mix_del_r, 0);
AudioConnection          patchCord5(i2s2, 1, mix_rev, 1);
AudioConnection          patchCord6(i2s2, 1, mix_op_l, 0);
AudioConnection          patchCord7(i2s2, 1, mix_del_l, 0);
AudioConnection          patchCord8(pink1, 0, filter_noise_l, 0);
AudioConnection          patchCord9(filter_noise_l, 1, mix_del_l, 2);
AudioConnection          patchCord10(filter_noise_r, 1, mix_del_r, 2);
AudioConnection          patchCord11(mix_del_l, 0, filter_del_l, 0);
AudioConnection          patchCord12(mix_del_r, 0, filter_del_r, 0);
AudioConnection          patchCord13(mix_rev, 0, filter_rev, 0);
AudioConnection          patchCord14(filter_del_r, 2, delay_r, 0);
AudioConnection          patchCord15(filter_del_l, 2, delay_l, 0);
AudioConnection          patchCord16(filter_rev, 2, freeverbs1, 0);
AudioConnection          patchCord17(delay_r, 0, mix_op_r, 2);
AudioConnection          patchCord18(delay_r, 0, mix_del_l, 1);
AudioConnection          patchCord19(delay_l, 0, mix_op_l, 2);
AudioConnection          patchCord20(delay_l, 0, mix_del_r, 1);
AudioConnection          patchCord21(freeverbs1, 0, mix_op_l, 1);
AudioConnection          patchCord22(freeverbs1, 1, mix_op_r, 1);
AudioConnection          patchCord23(mix_op_l, 0, i2s1, 0);
AudioConnection          patchCord24(mix_op_r, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=292,903
// GUItool: end automatically generated code

// GUItool: end automatically generated code

#define MAX_DELAY 1200 // should be 2000ms with combined delay of 4000ms (2 delays).
// Combined delays of more than 2400 currently lead to audio distortion, so set to 1200

//#define SERIAL_CONTROL
#define BOARD_CONTROL

#define NUM_BUTTONS 4

// led indexing, first 12 pots, then 4 buttons, then 4 (reversed) bars
#define NUM_POT_LEDS 12
#define NUM_BUT_LEDS 4
#define NUM_BAR_LEDS 4

Control controls[NUM_POTS];
// data_p, clk_p, latch_p, blank_p
LEDS leds(11, 13, 16, 9);
Button buttons[NUM_BUTTONS] = { Button(0), Button(1), Button(17), Button(22) };
Pots pots(5, 4, 2, 3, 14); // 14 for teensy fx pcb, 15 for audio pcb
BarTimer bar_timer;

// globals
int last_step = 0;
float peak;
bool in_peak;
bool delay_mode = true; // beat based delay


enum ButtonType {
    TAP_TEMPO,
    SET_TO_ONE,
    ERASE,
    WRITE,
    };

enum Cmd {
    MIX_SIG,
    MIX_NOISE,
   
    DEL_FB_FILT_RES,
    DEL_FB_FILT_FREQ,

    REV_FILT,
    REV_DAMP,
    REV_SIZE,
    MIX_REV_IN,

    DEL_FB,
    DEL_R_TIME,
    DEL_L_TIME,
    MIX_DEL,
    };

void setup() {
    Serial.begin(9600);
    #ifdef SERIAL_CONTROL
    #endif


    #ifdef BOARD_CONTROL
    for(int j = 0; j < MAX_LED; j ++)
    {
        for(int i = 0; i < 24; i ++)
        {
            leds.set_data(i, j);
        }
        leds.send();
        delayMicroseconds(50);
    }
    for(int j = MAX_LED; j > 0; j --)
    {
        for(int i = 0; i < 24; i ++)
        {
            leds.set_data(i, j);
        }
        leds.send();
        delayMicroseconds(50);
    }
    #endif

    // delays requires 1 block per 3ms. 
    AudioMemory(1300);

    // enable i2s audio chip
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.6);
    sgtl5000_1.lineOutLevel(5);
    sgtl5000_1.lineInLevel(5);

    sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
    
    // pink noise output
    pink1.amplitude(0.5);
    pink2.amplitude(0.5);

    // max gain for fx modules outputs. Only control the inputs
    mix_op_l.gain(1, 1.0); // reverb
    mix_op_l.gain(2, 1.0); // delay
    mix_op_r.gain(1, 1.0); // reverb
    mix_op_r.gain(2, 1.0); // delay

    // turn off unused delays - makes any difference?
    for(int i = 1; i < 7; i ++) {
        delay_l.disable(i);
        delay_r.disable(i);
    }

    // init bar timer
    bar_timer.set_bpm(120);
}

unsigned long last_update = 0;

void loop()
{
    #ifdef SERIAL_CONTROL
    check_serial();
    #endif

    #ifdef BOARD_CONTROL
//    check_pot();

    if(millis() - last_update > 5) {
        last_update = millis();
        check_board();
    }

    // look for sync signal
    if (peak1.available()) {
        if(peak1.read() > 0.7 && in_peak == false) {
            bar_timer.sync_tempo();
            in_peak = true;
        }
        else if(peak < 0.5)
            in_peak = false;
    } 
    #endif
}

void check_pot()
{
    delay(20);
    pots.update();
    for(int p = 0; p < NUM_POTS; p ++)
    {
        Serial.print(pots.get_value(p));
        Serial.print(" ");
    }
    Serial.println("");
}

void check_board()
{
    if(buttons[TAP_TEMPO].long_hold())
        bar_timer.inc_sync_mode();

    if(buttons[SET_TO_ONE].long_hold())
        delay_mode = !delay_mode;


    // bar_timer buttons
    if(buttons[TAP_TEMPO].was_pressed())
        bar_timer.tap_tempo();
    if(buttons[SET_TO_ONE].was_pressed())
        bar_timer.set_to_one();

    // update automation timer
    bar_timer.update();
    
    // debugging info
    if(bar_timer.get_step() != last_step) {
        last_step  = bar_timer.get_step();
        //Serial.println(bar_timer.get_step_millis());
        //Serial.print("step ");
        //Serial.println(bar_timer.get_step());
        //Serial.print("audio cpu max: "); Serial.println(AudioProcessorUsageMax());
        //Serial.print("audio mem max: "); Serial.println(AudioMemoryUsageMax());
    }

    // update pots & buttons
    pots.update();

    for(int button = 0; button < NUM_BUTTONS; button ++)
        buttons[button].update();

    // led for tempo
    leds.set_data(NUM_POT_LEDS + TAP_TEMPO, bar_timer.get_led());

    // led for write & erase & set to one
    leds.set_data(NUM_POT_LEDS + WRITE, buttons[WRITE].pressed() ? MAX_LED : 0);
    leds.set_data(NUM_POT_LEDS + SET_TO_ONE, delay_mode ? MAX_LED : 0);
    leds.set_data(NUM_POT_LEDS + ERASE, buttons[ERASE].pressed() ? MAX_LED : 0);

    for(int bar = 0; bar < NUM_BAR_LEDS; bar ++)
        leds.set_data(NUM_POT_LEDS + NUM_BUT_LEDS + bar, bar_timer.bar_led(bar) ? MAX_LED : 0); // leds are right to left 

    for(int pot = 0; pot < NUM_POTS; pot ++) {
        // update controls
        controls[pot].set_val(pots.get_value(pot), bar_timer.get_step(), pots.changed(pot), buttons[WRITE].pressed(), buttons[ERASE].pressed());

        // update leds
        leds.set_data(pot, controls[pot].get_led_val(bar_timer.get_step()));
        
        // update sound parameters
        float val = controls[pot].get_val(bar_timer.get_step());

        // beat based delay calcs
        float delay_val = bar_timer.get_beat_ms() * int(val * 16 + 1);
        if(delay_val > MAX_DELAY)
            delay_val = MAX_DELAY;

        switch(pot) {
            case REV_SIZE: freeverbs1.roomsize(val); break;
            case REV_DAMP: freeverbs1.damping(val); break;
            case MIX_SIG:
                mix_op_l.gain(0, val); // dry
                mix_op_r.gain(0, val); // dry
                break;
            case MIX_DEL:
                mix_del_l.gain(0, val); // delay
                mix_del_r.gain(0, val); // delay
                break;
            // delay value is in milliseconds
            case DEL_L_TIME: 
                if(delay_mode) {
                    //Serial.println(delay_val);
                    delay_l.delay(0, delay_val); 
                    }
                else
                    delay_l.delay(0, val * MAX_DELAY); 
                break;
            case DEL_R_TIME:
                if(delay_mode)
                    delay_r.delay(0, delay_val); 
                else
                    delay_r.delay(0, val * MAX_DELAY); 
                break;
            case DEL_FB:
                mix_del_r.gain(1, val);
                mix_del_l.gain(1, val);
                break;
            case DEL_FB_FILT_FREQ:
                filter_del_l.frequency(5000*val);
                filter_del_r.frequency(5000*val);
                filter_noise_l.frequency(5000*val);
                filter_noise_r.frequency(5000*val);
                break;
            case REV_FILT:
                filter_rev.frequency(5000*val);
                break;
            case DEL_FB_FILT_RES:
                filter_del_l.resonance(val*4);
                filter_del_r.resonance(val*4);
                filter_noise_l.resonance(val*4);
                filter_noise_r.resonance(val*4);
                break;
            case MIX_REV_IN:
                mix_rev.gain(1, val);    // right to rev
                break;
            case MIX_NOISE:
                mix_del_l.gain(2, val*0.75); // noise
                mix_del_r.gain(2, val*0.75); // noise
                break;
        }
    }

    // send the led data out
    leds.send();
}

void check_serial()
{
    if(Serial.available() == 2)
    {
        char cmd = Serial.read();
        uint8_t val = Serial.read();
        float val_0_to_1 = float(val) / 255;
        float val_0_to_05 = float(val) / 127;
        switch(cmd) {
            case REV_SIZE: 
                freeverbs1.roomsize(val_0_to_1);
                Serial.print("roomsize: "); Serial.println(val);
                break;
            case REV_DAMP:
                freeverbs1.damping(val_0_to_1);
                Serial.print("damping: "); Serial.println(val);
                break;
            case MIX_DEL:
                mix_del_l.gain(0, val_0_to_1); // delay
                mix_del_r.gain(0, val_0_to_1); // delay
                Serial.print("mix delay: "); Serial.println(val);
                break;
            case MIX_NOISE:
                mix_del_l.gain(2, val_0_to_05); // noise to delay input
                mix_del_r.gain(2, val_0_to_05); // noise to delay input
                Serial.print("mix noise: "); Serial.println(val);
                break;
            case MIX_SIG:
                mix_op_l.gain(0, val_0_to_1); // reverb
                mix_op_r.gain(0, val_0_to_1); // reverb
                Serial.print("mix wet: "); Serial.println(val);
                break;
            case DEL_L_TIME:
            {
                int dtime = map(val, 0, 255, 0, 2000); 
                delay_l.delay(0, dtime);
                Serial.print("del l: "); Serial.println(dtime);
                break;
            }
            case DEL_R_TIME:
            {
                int dtime = map(val, 0, 255, 0, 2000); 
                delay_r.delay(0, dtime);
                Serial.print("del r: "); Serial.println(dtime);
                break;
            }
            case DEL_FB:
                mix_del_r.gain(1, val_0_to_1);  // fb
                mix_del_l.gain(1, val_0_to_1);  // fb
                Serial.print("del fb: "); Serial.println(val_0_to_1);
                break;

            case DEL_FB_FILT_FREQ:
            {
                float freq = map(val, 0, 255, 0, 5000); 
                filter_del_l.frequency(freq);  // fb
                filter_del_r.frequency(freq);  // fb
                filter_noise_l.frequency(freq);  // fb
                filter_noise_r.frequency(freq);  // fb
                filter_rev.frequency(freq);
                Serial.print("del fb, noise & rev filt freq: "); Serial.println(freq);
                break;
            }

            case DEL_FB_FILT_RES:
            {
                float resonance = map(val, 0, 255, 0, 500) / 100.0; 
                filter_del_l.resonance(resonance);  // fb
                filter_del_r.resonance(resonance);  // fb
                filter_noise_l.resonance(resonance);  // fb
                filter_noise_r.resonance(resonance);  // fb
                Serial.print("del fb, noise & rev res: "); Serial.println(resonance);
                break;
            }

            case MIX_REV_IN:
                mix_rev.gain(0, val_0_to_1/2);    // left to rev
                mix_rev.gain(1, val_0_to_1/2);    // right to rev
                Serial.print("rev mix in: "); Serial.println(val_0_to_1/2);
                break;

            /*
            case AUDIO_PROC:
                Serial.print("audio cpu max: "); Serial.println(AudioProcessorUsageMax());
                break;

            case AUDIO_MEM:
                Serial.print("audio cpu max: "); Serial.println(AudioProcessorUsageMax());
                Serial.print("audio mem max: "); Serial.println(AudioMemoryUsageMax());
                break;
            */

            default:
                 Serial.print("got cmd: "); Serial.print(cmd);
                 Serial.print("with val: "); Serial.println(val);
                 break;
        }
    }
}

/*
https://forum.pjrc.com/threads/25679-Audio-adapter-schematic

https://www.pjrc.com/teensy/gui/index.html?info=AudioEffectFreeverbStereo

https://github.com/PaulStoffregen/Audio/tree/master/examples
*/

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=69,326
AudioMixer4              mix_del_l;      //xy=312,424
AudioMixer4              mix_del_r;      //xy=320,619
AudioFilterStateVariable filter_del_r;   //xy=429,744
AudioMixer4              mix_rev;        //xy=471,294
AudioFilterStateVariable filter_del_l;   //xy=495,488
AudioEffectDelay         delay_r;        //xy=614,867
AudioEffectDelay         delay_l;        //xy=630,571
AudioEffectFreeverbStereo freeverbs1;     //xy=642,279
AudioSynthNoisePink      pink1;          //xy=839,783
AudioFilterStateVariable filter_noise;        //xy=840,673
AudioMixer4              mix_op_l;       //xy=949,382
AudioMixer4              mix_op_r;       //xy=952,475
AudioOutputI2S           i2s1;           //xy=1133,428
AudioConnection          patchCord1(i2s2, 0, mix_del_l, 0);
AudioConnection          patchCord2(i2s2, 0, mix_op_l, 0);
AudioConnection          patchCord3(i2s2, 0, mix_rev, 0);
AudioConnection          patchCord4(i2s2, 1, mix_op_r, 0);
AudioConnection          patchCord5(i2s2, 1, mix_rev, 1);
AudioConnection          patchCord6(i2s2, 1, mix_del_r, 0);
AudioConnection          patchCord7(mix_del_l, 0, filter_del_l, 0);
AudioConnection          patchCord8(mix_del_r, 0, filter_del_r, 0);
AudioConnection          patchCord9(filter_del_r, 2, delay_r, 0);
AudioConnection          patchCord10(mix_rev, freeverbs1);
AudioConnection          patchCord11(filter_del_l, 2, delay_l, 0);
AudioConnection          patchCord12(delay_r, 0, mix_op_r, 2);
AudioConnection          patchCord13(delay_r, 0, mix_del_l, 1);
AudioConnection          patchCord14(delay_l, 0, mix_op_l, 2);
AudioConnection          patchCord15(delay_l, 0, mix_del_r, 1);
AudioConnection          patchCord16(freeverbs1, 0, mix_op_l, 1);
AudioConnection          patchCord17(freeverbs1, 1, mix_op_r, 1);
AudioConnection          patchCord18(pink1, 0, filter_noise, 0);
AudioConnection          patchCord19(filter_noise, 1, mix_op_l, 3);
AudioConnection          patchCord20(filter_noise, 2, mix_op_r, 3);
AudioConnection          patchCord21(mix_op_l, 0, i2s1, 0);
AudioConnection          patchCord22(mix_op_r, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=292,903
// GUItool: end automatically generated code

// Use these with the Teensy Audio Shield
/*
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14
*/

// Use these with the Teensy 3.5 & 3.6 SD card
//#define SDCARD_CS_PIN    BUILTIN_SDCARD
//#define SDCARD_MOSI_PIN  11  // not actually used
//#define SDCARD_SCK_PIN   13  // not actually used

// Use these for the SD+Wiz820 or other adaptors
//#define SDCARD_CS_PIN    4
//#define SDCARD_MOSI_PIN  11
//#define SDCARD_SCK_PIN   13

void setup() {
  Serial.begin(9600);
  //usbMIDI.setHandleControlChange(myControlChange);

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example 
  // delays requires 1 block per 3ms. 2000 blocks = 6000ms = 6s
  AudioMemory(2000);

  // Comment these out if not using the audio adaptor board.
  // This may wait forever if the SDA & SCL pins lack
  // pullup resistors
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);

/*
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
*/

  pink1.amplitude(0.5);
  // turn down input to reverb, over saturates
  mix_rev.gain(0, 0.0);    // left to rev
  mix_rev.gain(1, 0.0);    // right to rev

  mix_del_l.gain(0, 1);  // in
  mix_del_l.gain(1, 0);  // fb
  mix_del_l.gain(2, 0);  // noise

  mix_del_r.gain(0, 1);  // in
  mix_del_r.gain(1, 0);  // fb
  mix_del_r.gain(2, 0);  // noise

  mix_op_l.gain(0, 1.0); // wet
  mix_op_l.gain(1, 1.0); // reverb
  mix_op_l.gain(2, 1.0); // delay
  mix_op_l.gain(3, 0.0); // noise
  
  mix_op_r.gain(0, 1.0); // wet
  mix_op_r.gain(1, 1.0); // reverb
  mix_op_r.gain(2, 1.0); // delay
  mix_op_r.gain(3, 0.0); // noise

  delay_l.delay(0, 500);
  delay_r.delay(0, 750);

  freeverbs1.roomsize(0.7);
  freeverbs1.damping(0.8);
}

enum Cmd {
    REV_SIZE,
    REV_DAMP,
    MIX_DEL,
    MIX_SIG,
    MIX_REV,
    DEL_L_TIME,
    DEL_R_TIME,
    DEL_FB,
    DEL_FB_FILT_FREQ,
    DEL_FB_FILT_RES,
    MIX_REV_IN,
    MIX_NOISE,
    AUDIO_PROC,
    AUDIO_MEM,
    };
void loop()
{
   if(Serial.available() == 2)
   {
       char cmd = Serial.read();
       uint8_t val = Serial.read();
       float val_0_to_1 = float(val) / 255;
       switch(cmd) {
          case REV_SIZE: 
               freeverbs1.roomsize(val_0_to_1);
               Serial.print("roomsize: "); Serial.println(val);
              break;
          case REV_DAMP:
               freeverbs1.damping(val_0_to_1);
               Serial.print("damping: "); Serial.println(val);
              break;
          case MIX_REV:
              mix_op_l.gain(1, val_0_to_1); // reverb
              mix_op_r.gain(1, val_0_to_1); // reverb
              Serial.print("mix reverb: "); Serial.println(val);
              break;
          case MIX_DEL:
              mix_del_l.gain(0, val_0_to_1); // delay
              mix_del_r.gain(0, val_0_to_1); // delay
              Serial.print("mix delay: "); Serial.println(val);
              break;
          case MIX_NOISE:
              mix_op_l.gain(3, val_0_to_1); // noise
              mix_op_r.gain(3, val_0_to_1); // noise
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
              filter_noise.frequency(freq);  // fb
              Serial.print("del fb & noise filt freq: "); Serial.println(freq);
              break;
          }

          case DEL_FB_FILT_RES:
          {
              float resonance = map(val, 0, 255, 0, 500) / 100.0; 
              filter_del_l.resonance(resonance);  // fb
              filter_del_r.resonance(resonance);  // fb
              filter_noise.resonance(resonance);  // fb
              Serial.print("del fb & noise res: "); Serial.println(resonance);
              break;
          }

          case MIX_REV_IN:
              mix_rev.gain(0, val_0_to_1/2);    // left to rev
              mix_rev.gain(1, val_0_to_1/2);    // right to rev
              Serial.print("rev mix in: "); Serial.println(val_0_to_1/2);
              break;

          case AUDIO_PROC:
              Serial.print("audio cpu max: "); Serial.println(AudioProcessorUsageMax());
              break;

          case AUDIO_MEM:
              Serial.print("audio mem max: "); Serial.println(AudioMemoryUsageMax());
              break;

          default:
               Serial.print("got cmd: "); Serial.print(cmd);
               Serial.print("with val: "); Serial.println(val);
               break;
       }
   }
      /*
      mixer2.gain(0, knob_A1);
      mixer2.gain(1, 1.0 - knob_A1);
      mixer3.gain(0, knob_A1);
      mixer3.gain(1, 1.0 - knob_A1);
      */
// usbMIDI.read();
      
/*
  Serial.print("all=");
  Serial.print(AudioProcessorUsage());
  Serial.print(",");
  Serial.print("    ");
  Serial.print("Memory: ");
  Serial.print(AudioMemoryUsage());
  Serial.print(",");
  delay(50);
*/
}
void myControlChange(byte channel, byte control, byte value) {
  float val_0_to_1 = value / 127;
  switch (control) {
    case 100:
      freeverbs1.roomsize(val_0_to_1);
      break;

    case 101:
      freeverbs1.damping(val_0_to_1);
      break;
  }
}


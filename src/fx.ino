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
AudioInputI2S            i2s2;           //xy=234,341
AudioMixer4              mix_del_r;  //xy=292,649
AudioMixer4              mix_del_l;         //xy=293,439
AudioFilterStateVariable filter_del_r; //xy=406,735
AudioFilterStateVariable filter_del_l;        //xy=411,529
AudioMixer4              mix_rev;         //xy=512,286
AudioEffectDelay         delay_l;         //xy=639,500
AudioEffectDelay         delay_r; //xy=641,664
AudioEffectFreeverbStereo freeverbs1;     //xy=683,271
AudioMixer4              mix_op_l;         //xy=990,374
AudioMixer4              mix_op_r;         //xy=993,467
AudioOutputI2S           i2s1;           //xy=1174,420
AudioConnection          patchCord1(i2s2, 0, mix_del_l, 0);
AudioConnection          patchCord2(i2s2, 0, mix_op_l, 0);
AudioConnection          patchCord3(i2s2, 0, mix_rev, 0);
AudioConnection          patchCord4(i2s2, 1, mix_op_r, 0);
AudioConnection          patchCord5(i2s2, 1, mix_rev, 1);
AudioConnection          patchCord6(i2s2, 1, mix_del_r, 0);
AudioConnection          patchCord7(mix_del_r, delay_r);
AudioConnection          patchCord8(mix_del_l, delay_l);
AudioConnection          patchCord9(filter_del_r, 2, mix_del_l, 1);
AudioConnection          patchCord10(filter_del_l, 2, mix_del_r, 1);
AudioConnection          patchCord11(mix_rev, freeverbs1);
AudioConnection          patchCord12(delay_l, 0, mix_op_l, 2);
AudioConnection          patchCord13(delay_l, 0, filter_del_l, 0);
AudioConnection          patchCord14(delay_r, 0, filter_del_r, 0);
AudioConnection          patchCord15(delay_r, 0, mix_op_r, 2);
AudioConnection          patchCord16(freeverbs1, 0, mix_op_l, 1);
AudioConnection          patchCord17(freeverbs1, 1, mix_op_r, 1);
AudioConnection          patchCord18(mix_op_l, 0, i2s1, 0);
AudioConnection          patchCord19(mix_op_r, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=232,287
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
  mix_rev.gain(0, 1);    // left to rev
  mix_rev.gain(1, 1);    // right to rev

  mix_del_l.gain(0, 1);  // in
  mix_del_l.gain(1, 0.6);  // fb

  mix_del_r.gain(0, 1);  // in
  mix_del_r.gain(1, 0.6);  // fb

  mix_op_l.gain(0, 1.0); // wet
  mix_op_l.gain(1, 0.3); // reverb
  mix_op_l.gain(2, 1.0); // delay
  
  mix_op_r.gain(0, 1.0); // wet
  mix_op_r.gain(1, 0.3); // reverb
  mix_op_r.gain(2, 1.0); // delay

//      120 / 60 = 2bps

  delay_l.delay(0, 500);
  delay_r.delay(0, 750);

  freeverbs1.roomsize(0.7);
  freeverbs1.damping(0.8);
}

void loop()
{
      /*
      mixer2.gain(0, knob_A1);
      mixer2.gain(1, 1.0 - knob_A1);
      mixer3.gain(0, knob_A1);
      mixer3.gain(1, 1.0 - knob_A1);
      */

      
  Serial.print("all=");
  Serial.print(AudioProcessorUsage());
  Serial.print(",");
  Serial.print(AudioProcessorUsageMax());
  Serial.print("    ");
  Serial.print("Memory: ");
  Serial.print(AudioMemoryUsage());
  Serial.print(",");
  Serial.println(AudioMemoryUsageMax());
  delay(50);
}


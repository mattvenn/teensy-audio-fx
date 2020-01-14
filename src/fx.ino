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
AudioFilterStateVariable filter_rev;        //xy=555,183
AudioEffectDelay         delay_r;        //xy=614,867
AudioEffectDelay         delay_l;        //xy=630,571
AudioEffectFreeverbStereo freeverbs1;     //xy=642,279
AudioSynthNoisePink      pink2; //xy=812,732
AudioSynthNoisePink      pink1;          //xy=815,677
AudioMixer4              mix_op_l;       //xy=949,382
AudioMixer4              mix_op_r;       //xy=952,475
AudioFilterStateVariable filter_noise_l;        //xy=958,682
AudioFilterStateVariable filter_noise_r; //xy=961,740
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
AudioConnection          patchCord10(mix_rev, 0, filter_rev, 0);
AudioConnection          patchCord11(filter_del_l, 2, delay_l, 0);
AudioConnection          patchCord12(filter_rev, 2, freeverbs1, 0);
AudioConnection          patchCord13(delay_r, 0, mix_op_r, 2);
AudioConnection          patchCord14(delay_r, 0, mix_del_l, 1);
AudioConnection          patchCord15(delay_l, 0, mix_op_l, 2);
AudioConnection          patchCord16(delay_l, 0, mix_del_r, 1);
AudioConnection          patchCord17(freeverbs1, 0, mix_op_l, 1);
AudioConnection          patchCord18(freeverbs1, 1, mix_op_r, 1);
AudioConnection          patchCord19(pink2, 0, filter_noise_r, 0);
AudioConnection          patchCord20(pink1, 0, filter_noise_l, 0);
AudioConnection          patchCord21(mix_op_l, 0, i2s1, 0);
AudioConnection          patchCord22(mix_op_r, 0, i2s1, 1);
AudioConnection          patchCord23(filter_noise_l, 1, mix_op_l, 3);
AudioConnection          patchCord24(filter_noise_r, 1, mix_op_r, 3);
AudioControlSGTL5000     sgtl5000_1;     //xy=292,903
// GUItool: end automatically generated code


#define SERIAL_CONTROL
#define BOARD_CONTROL

#define NUM_KNOBS 12
#define NUM_BUTTONS 4
#define NUM_LEDS 20

// pin defs
#define POT_MUX_PINS 4
#define BUTTON_PINS 4
int pot_mux_addr_p[POT_MUX_PINS] = { 2, 3, 4, 5 };
int buttons_p[BUTTON_PINS] = { 0, 1, 17, 22 };
int led_data_p = 11;  // MOSI
int led_clk_p  = 13;  // SCK
int led_latch_p = 10; // CS
int led_oe_p = 9;
int pot_mux_p = 14;
SPISettings settings_LED(2000000, MSBFIRST, SPI_MODE1);

// global data
unsigned int knobs [NUM_KNOBS] = {0};
bool buttons [NUM_BUTTONS] = {0};
unsigned int leds[NUM_LEDS] = {0};

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

void setup() {
    #ifdef SERIAL_CONTROL
    Serial.begin(9600);
    #endif

    #ifdef BOARD_CONTROL
    // setup SPI for LED control
    pinMode(led_latch_p, OUTPUT);
    pinMode(led_oe_p, OUTPUT);
    pinMode(led_data_p, OUTPUT);
    pinMode(led_clk_p, OUTPUT);

    // buttons
    for( uint8_t i = 0; i < BUTTON_PINS; i++)
    {
        pinMode(buttons_p[i], INPUT_PULLUP);
    }
    // pot mux addr pins
    for( uint8_t i = 0; i < POT_MUX_PINS; i++)
    {
        pinMode(pot_mux_addr_p[i], OUTPUT);
    }
    #endif

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

  pink1.amplitude(0.5);
  pink2.amplitude(0.5);
  filter_rev.frequency(200);  // high pass for reverb in
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


void loop()
{
   #ifdef SERIAL_CONTROL
   check_serial();
   #endif

   #ifdef BOARD_CONTROL
   check_board();
   #endif
}

void check_board()
{
    // read pots
    for(int i = 0; i < 4; i ++ ) //NUM_KNOBS; i ++) // TODO 
    {
        digitalWrite(pot_mux_addr_p[i], true);
        knobs[i] = analogRead(pot_mux_p);
        digitalWrite(pot_mux_addr_p[i], false);
    }
    Serial.print("pot"); Serial.println(knobs[0]);

    // read buttons
    for(int i = 0; i < NUM_BUTTONS; i ++) // TODO 
    {
        buttons[i] = digitalRead(buttons_p[i]);
        Serial.print("button "); Serial.print(i); Serial.println(buttons[i]);
    }

    // update LEDs // TODO
    digitalWrite(led_oe_p, false);
    for(int i = 0; i < NUM_LEDS; i ++)
    {
        digitalWrite(led_latch_p, false);
        digitalWrite(led_data_p, false);
        digitalWrite(led_clk_p, false);
        delay(1);
        digitalWrite(led_latch_p, true);
        digitalWrite(led_data_p, true);
        digitalWrite(led_clk_p, true);
        delay(1);
    }
    digitalWrite(led_oe_p, true);
}

void check_serial()
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
              filter_noise_l.frequency(freq);  // fb
              filter_noise_r.frequency(freq);  // fb
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
}

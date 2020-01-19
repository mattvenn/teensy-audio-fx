#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=154.1666717529297,199.1666717529297
AudioAnalyzePeak         peak1;          //xy=302.1666717529297,306.1666717529297
AudioOutputI2S           i2s2;           //xy=409.1666717529297,210.1666717529297
AudioConnection          patchCord1(i2s1, 0, peak1, 0);
AudioConnection          patchCord2(i2s1, 1, i2s2, 0);
AudioConnection          patchCord3(i2s1, 1, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=182.1666717529297,383.1666717529297
// GUItool: end automatically generated code


void setup() {
  Serial.begin(9600);

  AudioMemory(2000);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);

}

float peak, lastpeak = 0;
unsigned long beattime, lastbeattime = 0;
void loop()
{
    if (peak1.available()) {
        //Serial.println(peak1.read());
       
        peak = peak1.read();
        if(peak - lastpeak > 0.8)
        {
            lastbeattime = beattime;
            beattime = millis();
            Serial.print("beat: ");
            Serial.println(beattime - lastbeattime);
        }
        lastpeak = peak;
    }
}

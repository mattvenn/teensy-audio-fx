#ifndef LEDS_H
#define LEDS_H

#define NUM_LEDS 24
// if you change MAX_LED, make sure to regenerate gamma.h
#define MAX_LED 4095

class LEDS {

    public:
        LEDS(int data_p, int clk_p, int latch_p, int blank_p);
        LEDS() {};
        void set_data(int led, int val); // gamma correct?
        int get_data(int led);
        void send();
    
    private:
        int _led_data [NUM_LEDS] = {0};
        int _data_p, _clk_p, _latch_p, _blank_p;
        void send_bit (bool bit);
        void send_latch(bool latch);
        void send_blank(bool blank);
};

#endif

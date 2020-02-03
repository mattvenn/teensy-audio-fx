#ifndef LEDS_H
#define LEDS_H

#define NUM_LEDS 20

class LEDS {

    public:
        LEDS(int data_p, int clk_p, int cs_p, int oe_p);
        LEDS() {};
        void set_data(int led, int val); // gamma correct?
        void send();
    
    private:
        int _led_data [NUM_LEDS] = {0};
        int _data_p, _clk_p, _cs_p, _oe_p;
        void send_bit (bool bit);
        void send_cs(bool cs);
};

#endif

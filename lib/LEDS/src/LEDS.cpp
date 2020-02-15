#include <LEDS.h>
#include <stdint.h>
#include <gamma.h>

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdio.h>
#endif

void LEDS::send_bit(bool bit)
{
#ifdef ARDUINO
    digitalWrite(_clk_p, false);
    digitalWrite(_data_p, bit);
    digitalWrite(_clk_p, true);
#else
    printf("%d", bit);
#endif
}

void LEDS::send_latch(bool cs)
{
#ifdef ARDUINO
    digitalWrite(_latch_p, cs);
#else
    printf("\ncs %d\n", cs);
#endif
}

void LEDS::send_blank(bool blank)
{
#ifdef ARDUINO
    digitalWrite(_blank_p, blank);
#else
    printf("\nblank %d\n", blank);
#endif
}

LEDS::LEDS(int data_p, int clk_p, int latch_p, int blank_p)
{
    _data_p = data_p;
    _clk_p  = clk_p;
    _latch_p   = latch_p;
    _blank_p   = blank_p; // blank high, outputs off

#ifdef ARDUINO
    pinMode(_data_p, OUTPUT);
    pinMode(_clk_p, OUTPUT);
    pinMode(_latch_p, OUTPUT);
    pinMode(_blank_p, OUTPUT);
#endif

    send_blank(1); // doesn't seem to do anything though
    send_latch(0);
}

void LEDS::send()
{
    for(int led = NUM_LEDS - 1; led >= 0; led --)
        for(int bit = 11 ; bit >= 0 ; bit --)
        {
            if(gamma_table[_led_data[led]] & (1 << bit))
                send_bit(1);
            else
                send_bit(0);
        }
    send_latch(1);
    send_latch(0);
}

void LEDS::set_data(int led, int val)
{
    if(led >= NUM_LEDS)
        return;
    if(val >= LED_MAX)
        val = LED_MAX;
    _led_data[led] = val;
}

int LEDS::get_data(int led) {
    if(led >= NUM_LEDS)
        return 0;
    return _led_data[led];
}

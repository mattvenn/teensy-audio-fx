#include <LEDS.h>
#include <stdint.h>

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

void LEDS::send_cs(bool cs)
{
#ifdef ARDUINO
    digitalWrite(_cs_p, cs);
#else
    printf("\ncs %d\n", cs);
#endif
}

LEDS::LEDS(int data_p, int clk_p, int cs_p, int oe_p)
{
    _data_p = data_p;
    _clk_p  = clk_p;
    _cs_p   = cs_p;
    _oe_p   = oe_p;

#ifdef ARDUINO
    pinMode(_data_p, OUTPUT);
    pinMode(_clk_p, OUTPUT);
    pinMode(_cs_p, OUTPUT);
    pinMode(_oe_p, OUTPUT);
#endif
}

void LEDS::send()
{
    send_cs(0);
    for(int led = 0; led < NUM_LEDS; led ++)
        for(int bit = 0 ; bit < 8 ; bit ++)
        {
            if(_led_data[led] & (1 << bit))
                send_bit(1);
            else
                send_bit(0);
        }
    send_cs(1);
}

void LEDS::set_data(int led, int val)
{
    if(led >= NUM_LEDS)
        return;
    _led_data[led] = val;
}

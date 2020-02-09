#include <Pots.h>
#include <stdint.h>

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdio.h>
#include <stdlib.h>
#endif

//https://www.norwegiancreations.com/2015/10/tutorial-potentiometers-with-arduino-and-filtering/

void Pots::update()
{
    for(int pot = 0; pot < NUM_POTS ; pot ++ )
    {
        // set mux pins
        for(int m = 0; m < POT_MUX_PINS; m ++)
#ifdef ARDUINO
            digitalWrite(_pot_mux_addr_p[m], pot & (1 << m) ? 1 : 0);
#else
            printf("%d", pot & (1 << m) ? 1 : 0);
        
#endif
#ifdef ARDUINO
        // read analogue data and filter with exp filter
        delayMicroseconds(1); // wait for mux to switch
        _pot_data[pot] = (EMA_a * analogRead(_pot_p)) + ((1 - EMA_a) * _pot_data[pot]);
//        _pot_data[pot] = analogRead(_pot_p);
#else
        printf("\n");
#endif
    }
}

bool Pots::changed(int pot) {
    // maybe needs some leeway depending on filter and noise
    bool changed = abs(_old_pot_data[pot] - _pot_data[pot]) > 4;
    if(changed) 
        _old_pot_data[pot] = _pot_data[pot];
    return changed;
}

int Pots::get_value(int pot) {
    return _pot_data[pot];
}

Pots::Pots(int mux0_p, int mux1_p, int mux2_p, int mux3_p, int pot_p)
{
    _pot_mux_addr_p[0] = mux0_p;
    _pot_mux_addr_p[1] = mux1_p;
    _pot_mux_addr_p[2] = mux2_p;
    _pot_mux_addr_p[3] = mux3_p;
    _pot_p = pot_p;

#ifdef ARDUINO
    for(int i = 0; i < POT_MUX_PINS; i++)
        pinMode(_pot_mux_addr_p[i], OUTPUT);
#endif
}

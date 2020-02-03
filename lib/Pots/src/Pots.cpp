#include <Pots.h>
#include <stdint.h>

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdio.h>
#endif

void Pots::update()
{
    for(int i = 0; i < NUM_POTS ; i ++ )
    {
        // set mux pins
        for(int m = 0; m < POT_MUX_PINS; m ++)
#ifdef ARDUINO
            digitalWrite(_pot_mux_addr_p[m], i & (1 << m));
#else
            printf("%d", i & (1 << m) ? 1 : 0);
#endif
        // read analogue data
        // filter?
#ifdef ARDUINO
        _old_pot_data[i] = _pot_data[i];
        _pot_data[i] = analogRead(_pot_p);
#else
        printf("\n");
#endif
    }
}

bool Pots::changed(int pot) {
    // maybe needs some leeway depending on filter and noise
    return _old_pot_data[pot] != _pot_data[pot];
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

#include <Control.h>

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdio.h>
#endif

void Control::set_val(int val, int step, bool changed, bool write) {
    if(write && changed)
        _writing = true;         
    if(!write)
        _writing = false;

    if(_writing)
        _val[step] = val;
    else
        for(int s = 0; s < MAX_STEPS; s ++)
            _val[s] = val;
}

float Control::get_val(int step) {
    return float(_val[step]) / MAX_POT;
}

int Control::get_led_val(int step) {
    return _val[step] / (MAX_POT / MAX_LED);
}

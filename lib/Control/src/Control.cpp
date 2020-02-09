#include <Control.h>

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdio.h>
#endif

void Control::set_val(int val, int step, bool changed, bool write, bool erase) {
    if(write && changed)
        _writing = true;         
    else if(!write)
        _writing = false;

    if(_writing) {
        _val[step] = val;
#ifdef DEBUG
        sprintf(_buf, "write %d at %d", val, step);
        Serial.println(_buf);
#endif
    }
    else if(changed || erase)
    {
        for(int s = 0; s < MAX_STEPS; s ++)
            _val[s] = val;
#ifdef DEBUG
        sprintf(_buf, "set all to %d", val);
        Serial.println(_buf);
#endif
    }
}

float Control::get_val(int step) {
    return float(_val[step]) / MAX_POT;
}

int Control::get_led_val(int step) {
    return _val[step] / (MAX_POT / MAX_LED);
}

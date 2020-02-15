#include <Button.h>

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdio.h>
#endif

Button::Button(int b_p) {
    _b_p = b_p;

#ifdef ARDUINO
    pinMode(_b_p, INPUT_PULLUP);
#endif    
}

void Button::update() { // need to debounce this at some point
#ifdef ARDUINO
    // active low
    _b = !digitalRead(_b_p);
#endif    
}

bool Button::long_hold() {
    if(_b)
        _hold_time = millis() - _start_hold;
    else {
        _start_hold = millis();
        _long_hold = false;
    }

    if(_b && _hold_time > LONG_HOLD && _long_hold == false) {
        _long_hold = true;
        return true;
    }

    return false;
}

bool Button::was_pressed() {
    if(_b && _was_pressed == false) {
        _was_pressed = true;
        return true;
    }

    if(!_b)
        _was_pressed = false;

    return false;
}

bool Button::pressed() {
    return _b;
}

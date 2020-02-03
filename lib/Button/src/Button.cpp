#include <Button.h>

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <stdio.h>
#endif

Button::Button(int b_p) {
    _b_p = b_p;

#ifdef ARDUINO
/*
    pinMode(_write_p, INPUT_PULLUP);
    pinMode(_erase_p, INPUT_PULLUP);
    pinMode(_set_one_p, INPUT_PULLUP);
    pinMode(_tap_tempo_p, INPUT_PULLUP);
    */
#endif    
}

void Button::update() { // debounce?
#ifdef ARDUINO
    _b = digitalRead(_b_p);
#endif    
/*
    _write = digitalRead(_write_p);
    _erase = digitalRead(_erase_p);
    _set_one = digitalRead(_set_one_p);
    _tap_tempo = digitalRead(_tap_tempo_p);
    */
}

bool Button::pressed() {
    return _b;
}
/*
bool Button::get_write() {
    return _write;
}
bool Button::get_erase() {
    return _erase;
}

bool Button::get_tap_tempo() {
    return _tap_tempo;
}

bool Button::get_set_one() {
    return _set_one;
}
*/


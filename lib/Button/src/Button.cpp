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

void Button::update() { // debounce?
#ifdef ARDUINO
    // active low
    _b = !digitalRead(_b_p);
#endif    
}

bool Button::pressed() {
    return _b;
}

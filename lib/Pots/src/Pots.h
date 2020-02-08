#ifndef Pots_H
#define Pots_H

#define NUM_POTS 12
#define POT_MUX_PINS 4

class Pots {

    public:
        Pots(int mux0_p, int mux1_p, int mux2_p, int mux3_p, int pot_p);
        Pots() {};
        void update();
        int get_value(int pot);
        bool changed(int pot);
    
    private:
        int _pot_data [NUM_POTS] = {0};
        int _old_pot_data [NUM_POTS] = {0};
        int _pot_mux_addr_p[POT_MUX_PINS];
        int _pot_p;
        float EMA_a = 0.1;  //initialization of EMA alpha
};

#endif

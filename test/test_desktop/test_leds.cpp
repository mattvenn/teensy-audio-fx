#include <unity.h>
#include <stdio.h>
#include <LEDS.h>
#include <Control.h>
#include <Pots.h>
#include <Button.h>
#include <BarTimer.h>

#define NUM_CONTROLS 2
#define NUM_BUTTONS 2
Control control[NUM_CONTROLS];
LEDS led(1, 2, 3, 4);
Pots pots(2, 3, 4, 5, 14);
Button buttons[NUM_BUTTONS] = { Button(0), Button(1) }; //(0, 1, 17, 22);
BarTimer bar_timer;

void test_bar_timer(void){

    bar_timer.set_bpm(120);
    bar_timer.update(true);
    // 120bpm with 512 steps per bar is 15.625 between beats
    TEST_ASSERT_EQUAL(bar_timer.get_next_step_millis(), 15);
    TEST_ASSERT_EQUAL(bar_timer.get_step(), 0);
    for(int ms = 0; ms < 15.625 * MAX_STEPS-1; ms ++) {
        bar_timer.set_millis(ms);
        bar_timer.update(false);
        printf("ms = %d ms/15.625 = %f, step = %d\n", ms, ms/15.625, bar_timer.get_step());
        TEST_ASSERT_INT_WITHIN(1, bar_timer.get_step(), ms/15.625); //.625);expected, actual)
    }

    // test rollover
    int ms = MAX_STEPS * 15.625;
    bar_timer.set_millis(ms);
    bar_timer.update(false);
    TEST_ASSERT_EQUAL(bar_timer.get_step(), 0);
}
void test_button(void) {
    buttons[0].update();
    TEST_ASSERT_EQUAL(buttons[0].pressed(), false);
}
void test_control_led_and_param(void) {
    for(int i = 0; i < 1024; i += 200)
    {
        control[0].set_val(i,0,true, false, false);
        printf("pot %d val %.2f led %d\n", i, control[0].get_val(0), control[0].get_led_val(0));
    }

}
void test_control(void) {
    for(int i = 0; i < NUM_CONTROLS; i ++)
    {
        control[i].set_val(500,0,true,false, false);
        TEST_ASSERT_EQUAL(float(500)/1024, control[i].get_val(0));
        TEST_ASSERT_EQUAL(500/(1024/256), control[i].get_led_val(0));
    }
}

void test_control_seq(void) {
    // write
    for(int i = 0; i < MAX_STEPS; i ++)
        control[0].set_val(i, i, true, true, false);

    // read
    for(int i = 0; i < MAX_STEPS; i ++)
        TEST_ASSERT_EQUAL(float(i)/1024, control[0].get_val(i));

    // set to single value
    control[0].set_val(0, 0, true, false, false);

    // read
    for(int i = 0; i < MAX_STEPS; i ++)
        TEST_ASSERT_EQUAL(0, control[0].get_val(i));
}

void test_send_led_data(void) {
    led.set_data(0,50);
    led.set_data(3,50);
    led.send();
}

void test_pot_mux(void) {
    pots.update();
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_send_led_data);
    RUN_TEST(test_control);
    RUN_TEST(test_control_seq);
    RUN_TEST(test_pot_mux);
    RUN_TEST(test_control_led_and_param);
    RUN_TEST(test_button);
    RUN_TEST(test_bar_timer);
    UNITY_END();

    return 0;
}

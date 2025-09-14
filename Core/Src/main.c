#include "init.h"

uint16_t var = 0;

/* LEDs */
uint16_t led_pin_1_val = 0;
uint16_t led_pin_2_val = 0;
uint16_t led_pin_3_val = 0;
uint16_t led_pin_4_val = 0;
uint16_t led_pin_5_val = 0;
uint16_t led_pin_6_val = 0;
uint16_t led_pin_1_val_code = 0;
uint16_t led_pin_2_val_code = 0;
uint16_t led_pin_3_val_code = 0;
uint16_t led_pin_4_val_code = 0;
uint16_t led_pin_5_val_code = 0;
uint16_t led_pin_6_val_code = 0;

/* BUTTONS */
uint16_t but_1_val = 0;
uint16_t but_1_state = 0;

uint16_t but_2_val = 0;
uint16_t but_2_state = 0;

uint16_t but_3_val = 0;
uint16_t but_3_state = 0;
uint16_t but_3_prev = 0;

#define BUT_13_MASK (1 << 13)

int main(void) {

    lab_1_init();
    
    /* Start program flashing */
    GPIOA_REG(GPIO_BSRR) |= LED_4_MASK;
    delay(2500);
    GPIOA_REG(GPIO_BSRR) |= LED_4_MASK << 16;
    delay(2500);
    GPIOA_REG(GPIO_BSRR) |= LED_4_MASK;
    delay(2500);
    GPIOA_REG(GPIO_BSRR) |= LED_4_MASK << 16;
    delay(2500);

    led_pin_1_val = (GPIOA_REG(GPIO_ODR) & LED_1_MASK) != 0;
    led_pin_2_val = (GPIOA_REG(GPIO_ODR) & LED_2_MASK) != 0;
    led_pin_3_val = (GPIOA_REG(GPIO_ODR) & LED_3_MASK) != 0;
    led_pin_4_val = (GPIOA_REG(GPIO_ODR) & LED_4_MASK) != 0;
    led_pin_5_val = (GPIOA_REG(GPIO_ODR) & LED_5_MASK) != 0;
    led_pin_6_val = (GPIOA_REG(GPIO_ODR) & LED_6_MASK) != 0;

    uint16_t delay_time = 5000;

    while(1) {
        /* main loop */

        var = !(GPIOC_REG(GPIO_IDR) & BUT_13_MASK) != 0;

        but_1_state = (GPIOC_REG(GPIO_IDR) & BUT_1_MASK) != 0;
        but_2_state = (GPIOC_REG(GPIO_IDR) & BUT_2_MASK) != 0;
        but_3_state = (GPIOC_REG(GPIO_IDR) & BUT_3_MASK) != 0;

        if (but_1_state) { but_1_val = 1; }
        if (but_2_state) { but_2_val = 1; }
        if (but_3_state && but_3_prev == 0) {
            but_3_val = !but_3_val;
        }
        but_3_prev = but_3_state;

        led_pin_1_val = (GPIOA_REG(GPIO_ODR) & LED_1_MASK) != 0;
        led_pin_2_val = (GPIOA_REG(GPIO_ODR) & LED_2_MASK) != 0;
        led_pin_3_val = (GPIOA_REG(GPIO_ODR) & LED_3_MASK) != 0;
        led_pin_4_val = (GPIOA_REG(GPIO_ODR) & LED_4_MASK) != 0;
        led_pin_5_val = (GPIOA_REG(GPIO_ODR) & LED_5_MASK) != 0;
        led_pin_6_val = (GPIOA_REG(GPIO_ODR) & LED_6_MASK) != 0;

        if (!but_3_val) {
            if (but_1_val) {
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_1_MASK;
                led_pin_1_val = (GPIOA_REG(GPIO_ODR) & LED_1_MASK) != 0;
                led_pin_1_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_2_MASK;
                led_pin_2_val = (GPIOA_REG(GPIO_ODR) & LED_2_MASK) != 0;
                led_pin_2_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_3_MASK;
                led_pin_3_val = (GPIOA_REG(GPIO_ODR) & LED_3_MASK) != 0;
                led_pin_3_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_4_MASK;
                led_pin_4_val = (GPIOA_REG(GPIO_ODR) & LED_4_MASK) != 0;
                led_pin_4_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_5_MASK;
                led_pin_5_val = (GPIOA_REG(GPIO_ODR) & LED_5_MASK) != 0;
                led_pin_5_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_6_MASK;
                led_pin_6_val = (GPIOA_REG(GPIO_ODR) & LED_6_MASK) != 0;
                led_pin_6_val_code = 1;
                delay(delay_time);

                but_1_val = 0;
                but_2_val = 0;
            }
            if (but_2_val) {
                delay(delay_time);

                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_6_MASK << 16;
                led_pin_6_val = (GPIOA_REG(GPIO_ODR) & LED_6_MASK) != 0;
                led_pin_6_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_5_MASK << 16;
                led_pin_5_val = (GPIOA_REG(GPIO_ODR) & LED_5_MASK) != 0;
                led_pin_5_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_4_MASK << 16;
                led_pin_4_val = (GPIOA_REG(GPIO_ODR) & LED_4_MASK) != 0;
                led_pin_4_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_3_MASK << 16;
                led_pin_3_val = (GPIOA_REG(GPIO_ODR) & LED_3_MASK) != 0;
                led_pin_3_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_2_MASK << 16;
                led_pin_2_val = (GPIOA_REG(GPIO_ODR) & LED_2_MASK) != 0;
                led_pin_2_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_1_MASK << 16;
                led_pin_1_val = (GPIOA_REG(GPIO_ODR) & LED_1_MASK) != 0;
                led_pin_1_val_code = 0;
                delay(delay_time);

                but_1_val = 0;
                but_2_val = 0;
            }
        } else {
            if (but_2_val) {
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_1_MASK;
                led_pin_1_val = (GPIOA_REG(GPIO_ODR) & LED_1_MASK) != 0;
                led_pin_1_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_2_MASK;
                led_pin_2_val = (GPIOA_REG(GPIO_ODR) & LED_2_MASK) != 0;
                led_pin_2_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_3_MASK;
                led_pin_3_val = (GPIOA_REG(GPIO_ODR) & LED_3_MASK) != 0;
                led_pin_3_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_4_MASK;
                led_pin_4_val = (GPIOA_REG(GPIO_ODR) & LED_4_MASK) != 0;
                led_pin_4_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_5_MASK;
                led_pin_5_val = (GPIOA_REG(GPIO_ODR) & LED_5_MASK) != 0;
                led_pin_5_val_code = 1;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_6_MASK;
                led_pin_6_val = (GPIOA_REG(GPIO_ODR) & LED_6_MASK) != 0;
                led_pin_6_val_code = 1;
                delay(delay_time);

                but_1_val = 0;
                but_2_val = 0;
            }
            if (but_1_val) {

                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_6_MASK << 16;
                led_pin_6_val = (GPIOA_REG(GPIO_ODR) & LED_6_MASK) != 0;
                led_pin_6_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_5_MASK << 16;
                led_pin_5_val = (GPIOA_REG(GPIO_ODR) & LED_5_MASK) != 0;
                led_pin_5_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_4_MASK << 16;
                led_pin_4_val = (GPIOA_REG(GPIO_ODR) & LED_4_MASK) != 0;
                led_pin_4_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_3_MASK << 16;
                led_pin_3_val = (GPIOA_REG(GPIO_ODR) & LED_3_MASK) != 0;
                led_pin_3_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_2_MASK << 16;
                led_pin_2_val = (GPIOA_REG(GPIO_ODR) & LED_2_MASK) != 0;
                led_pin_2_val_code = 0;
                delay(delay_time);
                GPIOA_REG(GPIO_BSRR) |= LED_1_MASK << 16;
                led_pin_1_val = (GPIOA_REG(GPIO_ODR) & LED_1_MASK) != 0;
                led_pin_1_val_code = 0;
                delay(delay_time);

                but_1_val = 0;
                but_2_val = 0;
            }
        }
    }

    return 0;
}
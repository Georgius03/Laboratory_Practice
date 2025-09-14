#include "init.h"

void lab_1_init(void) {

    /* GPIO RCC configuration */
    RCC_REG(RCC_AHB1ENR) |= GPIOA_EN;                    // Enable clock for GPIOA

    /* GPIOA configuration (LEDS) [01 for each is Output] */
    GPIOA_REG(GPIO_MODER) |= LED_1_PIN;              // Set PA0 pin as output
    GPIOA_REG(GPIO_MODER) |= LED_2_PIN;              // Set PA1 pin as output
    GPIOA_REG(GPIO_MODER) |= LED_3_PIN;              // Set PA4 pin as output
    GPIOA_REG(GPIO_MODER) |= LED_4_PIN;              // Set PA5 pin as output
    GPIOA_REG(GPIO_MODER) |= LED_5_PIN;              // Set PA6 pin as output
    GPIOA_REG(GPIO_MODER) |= LED_6_PIN;              // Set PA7 pin as output

    /* GPIOA configuration (push-pull (reset state)) */
    GPIOA_REG(GPIO_OTYPER) = 0;                      // Set output type to push-pull

    /* GPIOA configuration (pin speed) [01 for each is Medium] */
    GPIOA_REG(GPIO_OSPEEDR) |= LED_1_PIN;            // Set medium output speed for PA0
    GPIOA_REG(GPIO_OSPEEDR) |= LED_2_PIN;            // Set medium output speed for PA1
    GPIOA_REG(GPIO_OSPEEDR) |= LED_3_PIN;            // Set medium output speed for PA4
    GPIOA_REG(GPIO_OSPEEDR) |= LED_4_PIN;            // Set medium output speed for PA5
    GPIOA_REG(GPIO_OSPEEDR) |= LED_5_PIN;            // Set medium output speed for PA6
    GPIOA_REG(GPIO_OSPEEDR) |= LED_6_PIN;            // Set medium output speed for PA7

    /* GPIOA configuration (pin speed) [00 for each is No pull-up, pull-down] */
    GPIOA_REG(GPIO_PUPDR) |= 64000000;               // Set No pull-up, pull-down for GPIOA



    /* GPIOC RCC configuration */
    RCC_REG(RCC_AHB1ENR) |= GPIOC_EN;                // Enable clock for GPIOC

    /* GPIOC configuration (push-pull (reset state)) */
    GPIOC_REG(GPIO_PUPDR) = 0;                       // No pull-up/pull-down for GPIOC
}

void delay(int nTime) {

    unsigned int i;
    unsigned long j;

    for(i = nTime; i > 0; i--) {
        for(j = 1000; j > 0; j--);
    }
}


// void normal_man_init(void) {
//     /* GPIOA configuration */
//     RCC_REG(RCC_AHB1ENR) |= GPIOA_EN;                    // Enable clock for GPIOA
//     GPIOA_REG(GPIO_MODER) |= MODER5_OUTPUT;              // Set PA5 pin as output
//     GPIOA_REG(GPIO_OTYPER) = 0;                          // Set output type to push-pull
//     GPIOA_REG(GPIO_OSPEEDR) |= OSPEEDR5_MEDIUM;          // Set medium output speed for PA5
//     GPIOA_REG(GPIO_PUPDR) = 0x64000000;                  // Configure pull-up/pull-down resistors

//     /* GPIOC configuration */
//     RCC_REG(RCC_AHB1ENR) |= GPIOC_EN;                    // Enable clock for GPIOC
//     GPIOC_REG(GPIO_PUPDR) = 0x00000000;                  // No pull-up/pull-down for GPIOC

//     /* Set initial state */
//     GPIOA_REG(GPIO_BSRR) |= BS5_SET;                     // Set PA5 output high initially
// }

void register_init(void) {

    /* GPIOA */
    *(uint32_t *)(0x40023800 + 0x30) |= 0x1; // Enable GPIOA clock (RST_MEMORY + RCC_AHB1ENR |= GPIOA_EN bit)

    *(uint32_t *)(0x40020000 + 0x00) |= 0x400; // Set PA5 as output (GPIOA_MEMORY + GPIOA_MODER |= MODER5[1:0])
    *(uint32_t *)(0x40020000 + 0x04) = 0; // Set GPIOA output type to push-pull (GPIOA_MEMORY + GPIOA_OTYPER = 0)
    *(uint32_t *)(0x40020000 + 0x08) |= 0x400; // Set GPIOA PA5 output speed to medium speed (GPIOA_MEMORY + GPIOA_OSPEEDR |= OSPEEDR5[1:0])
    *(uint32_t *)(0x40020000 + 0x0C) = 0x64000000; // Reset GPIOA to No pull-up, pull-down (GPIOA_MEMORY + GPIOA_PUPDR = 0x64000000)
    // *(uint32_t *)(0x40020000 + 0x0C) |= 0x400; // Set GPIOA PA5 pull-up (GPIOA_MEMORY + GPIOA_PUPDR |= PUPDR5[1:0])

    *(uint32_t *)(0x40020000 + 0x18) |= 0x20; // Set PA5 high (GPIOA_MEMORY + GPIOA_BSRR |= BS5 bit)
    // *(uint32_t *)(0x40020400 + 0x18) |= 0x200000; // Set PA5 high (GPIOA_MEMORY + GPIOA_BSRR |= BR5 bit)
}

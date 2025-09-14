#include "stdtypes.h"

/* Memory addresses */
#define RCC_BASE        0x40023800  // Base address for Reset and Clock Control
#define GPIOA_BASE      0x40020000  // Base address for GPIO Port A
#define GPIOB_BASE      0x40020400  // Base address for GPIO Port B
#define GPIOC_BASE      0x40020800  // Base address for GPIO Port C

/* Register offsets */
#define RCC_AHB1ENR     0x30        // AHB1 peripheral clock enable register
#define GPIO_MODER      0x00        // GPIO port mode register
#define GPIO_OTYPER     0x04        // GPIO output type register
#define GPIO_OSPEEDR    0x08        // GPIO output speed register
#define GPIO_PUPDR      0x0C        // GPIO pull-up/pull-down register
#define GPIO_IDR        0x10        // GPIO input data register
#define GPIO_ODR        0x14        // GPIO input data register
#define GPIO_BSRR       0x18        // GPIO bit set/reset register

/* Bit masks for RCC_AHB1ENR */
#define GPIOA_EN        (1 << 0)    // Bit 0: GPIOA clock enable
#define GPIOA_EN        (1 << 1)    // Bit 1: GPIOB clock enable
#define GPIOC_EN        (1 << 2)    // Bit 2: GPIOC clock enable

/* Bit masks for GPIO registers */
#define LED_1_PIN     (1 << (2 * 0))    // Pin 0 for LED1 (PA0)
#define LED_2_PIN     (1 << (2 * 1))    // Pin 1 for LED2 (PA1)
#define LED_3_PIN     (1 << (2 * 4))    // Pin 4 for LED3 (PA4)
#define LED_4_PIN     (1 << (2 * 5))    // Pin 5 for LED4 (PA5)
#define LED_5_PIN     (1 << (2 * 6))    // Pin 6 for LED5 (PA6)
#define LED_6_PIN     (1 << (2 * 7))    // Pin 7 for LED6 (PA7)

#define LED_1_MASK     (1 << 0)    // Pin 0 for LED1 (PA0)
#define LED_2_MASK     (1 << 1)    // Pin 1 for LED2 (PA1)
#define LED_3_MASK     (1 << 4)    // Pin 4 for LED3 (PA4)
#define LED_4_MASK     (1 << 5)    // Pin 5 for LED4 (PA5)
#define LED_5_MASK     (1 << 6)    // Pin 6 for LED5 (PA6)
#define LED_6_MASK     (1 << 7)    // Pin 7 for LED6 (PA7)

#define BUT_1_MASK     (1 << 0)    // Pin 0 for BUT1 (PC0)
#define BUT_2_MASK     (1 << 1)    // Pin 1 for BUT2 (PC1)
#define BUT_3_MASK     (1 << 7)    // Pin 7 for BUT3 (PC7)

/* Register access macros */
#define REG(addr)       (*(volatile uint32_t *)(addr))               // Generic register access
#define RCC_REG(offset) REG(RCC_BASE + (offset))                     // RCC register access
#define GPIOA_REG(offset) REG(GPIOA_BASE + (offset))                 // GPIOA register access
#define GPIOB_REG(offset) REG(GPIOB_BASE + (offset))                 // GPIOB register access
#define GPIOC_REG(offset) REG(GPIOC_BASE + (offset))                 // GPIOC register access


void normal_man_init(void);
void register_init(void);
void delay(int nTime);
# STM32L476 EXTI Interrupt Example

Bare metal embedded C project for STM32L476 using CMSIS.

This project demonstrates how to configure:

- GPIO output (LED on PA5)
- GPIO input with pull-up (button on PA6)
- SYSCFG configuration
- EXTI external interrupt
- NVIC interrupt controller
- Interrupt handler in C

When the button is pressed, an external interrupt is triggered and the LED toggles.

## Hardware

- STM32L476RG (Nucleo or custom board)
- LED on PA5
- Push button on PA6
- Pull-up resistor (internal)
- Optional capacitor for debounce

## Features

- Bare metal programming (no HAL)
- CMSIS registers
- External interrupt (EXTI6)
- Falling edge trigger
- NVIC interrupt handling

## File

- main.c

## Author

David Clinton

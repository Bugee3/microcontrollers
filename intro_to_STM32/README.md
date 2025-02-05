Daily Log

February 5, 2025
What I Learned Today:

STM32 Nucleo F401RE configuration.
Working with GPIO pins and controlling output devices like LEDs.
Understanding the HAL (Hardware Abstraction Layer) for STM32 microcontrollers.
Writing basic delay functions using HAL_GetTick() for timing.
Debugging and testing with STM32CubeIDE and ST-Link.
What I Did Today:

Set up the environment for STM32 development with STM32CubeIDE.
Initialized the project for STM32 Nucleo F401RE using CubeMX.
Configured GPIO pins for LED control.
Wrote a simple program to blink an LED connected to pin PA4.
Implemented a delay function using the SysTick timer for timing the LED blink.
Code Changes:

Created a basic project in STM32CubeIDE for STM32F401RE.
Configured GPIOA pin 4 for output.
Implemented a 500ms blink delay function using HAL_GetTick().
Wrote code for toggling the LED on PA4.
Setup Instructions

Prerequisites
STM32CubeIDE: Download and install from STMicroelectronics.
ST-Link Driver: Install the ST-Link driver for your platform.
STM32 Nucleo F401RE: Make sure you have the STM32 Nucleo F401RE development board.

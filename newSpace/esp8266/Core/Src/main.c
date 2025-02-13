#include "main.h"

// USART handler declaration
UART_HandleTypeDef huart2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
{
  // Initialize the HAL Library
  HAL_Init();

  // Configure the system clock
  SystemClock_Config();

  // Initialize GPIO and USART2
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  // Main loop
  while (1)
  {
    // Example: Send data to ESP8266
    char msg[] = "Hello from STM32\n";
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);

    // Simple delay
    HAL_Delay(1000);

    // Example: Receive data from ESP8266 (if any)
    uint8_t rx_data;
    if (HAL_UART_Receive(&huart2, &rx_data, 1, 1000) == HAL_OK) {
      // Do something with the received data
      // For example, echo the received byte
      HAL_UART_Transmit(&huart2, &rx_data, 1, HAL_MAX_DELAY);
    }
  }
}

// USART2 initialization function
static void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;          // Set baud rate
  huart2.Init.WordLength = UART_WORDLENGTH_8B;  // 8 data bits
  huart2.Init.StopBits = UART_STOPBITS_1;     // 1 stop bit
  huart2.Init.Parity = UART_PARITY_NONE;      // No parity
  huart2.Init.Mode = UART_MODE_TX_RX;         // TX and RX mode
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;  // No hardware flow control
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;  // Oversampling
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

// GPIO initialization function
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();  // Enable GPIOA clock

  // Configure USART2 TX (PA2)
  GPIO_InitStruct.Pin = GPIO_PIN_2;  // TX pin
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;  // Alternate function push-pull
  GPIO_InitStruct.Pull = GPIO_NOPULL;     // No pull-up or pull-down
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;  // High speed
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Configure USART2 RX (PA3)
  GPIO_InitStruct.Pin = GPIO_PIN_3;  // RX pin
  GPIO_InitStruct.Mode = GPIO_MODE_AF_INPUT;  // Alternate function input
  GPIO_InitStruct.Pull = GPIO_NOPULL;  // No pull-up or pull-down
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

// Error handler function
void Error_Handler(void)
{
  // Stay in this function if there is an error
  while (1)
  {
    // Blink an LED or do some error handling
  }
}

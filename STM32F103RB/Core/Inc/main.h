/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern UART_HandleTypeDef huart2;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN3_Pin GPIO_PIN_0
#define BTN3_GPIO_Port GPIOA
#define BTN0_Pin GPIO_PIN_1
#define BTN0_GPIO_Port GPIOA
#define BTN1_Pin GPIO_PIN_4
#define BTN1_GPIO_Port GPIOA
#define BTN2_Pin GPIO_PIN_0
#define BTN2_GPIO_Port GPIOB
#define PED_0_Pin GPIO_PIN_10
#define PED_0_GPIO_Port GPIOB
#define PED_1_Pin GPIO_PIN_8
#define PED_1_GPIO_Port GPIOA
#define LED_00_Pin GPIO_PIN_10
#define LED_00_GPIO_Port GPIOA
#define LED_01_Pin GPIO_PIN_3
#define LED_01_GPIO_Port GPIOB
#define LED_11_Pin GPIO_PIN_4
#define LED_11_GPIO_Port GPIOB
#define LED_10_Pin GPIO_PIN_5
#define LED_10_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
TIM_HandleTypeDef htim3;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

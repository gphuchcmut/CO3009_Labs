/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED_X_Pin GPIO_PIN_1
#define RED_X_GPIO_Port GPIOA
#define YELLOW_X_Pin GPIO_PIN_2
#define YELLOW_X_GPIO_Port GPIOA
#define GREEN_X_Pin GPIO_PIN_3
#define GREEN_X_GPIO_Port GPIOA
#define RED_Y_Pin GPIO_PIN_4
#define RED_Y_GPIO_Port GPIOA
#define YELLOW_Y_Pin GPIO_PIN_5
#define YELLOW_Y_GPIO_Port GPIOA
#define GREEN_Y_Pin GPIO_PIN_6
#define GREEN_Y_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_7
#define EN0_GPIO_Port GPIOA
#define SEG_A_X_Pin GPIO_PIN_0
#define SEG_A_X_GPIO_Port GPIOB
#define SEG_B_X_Pin GPIO_PIN_1
#define SEG_B_X_GPIO_Port GPIOB
#define SEG_C_X_Pin GPIO_PIN_2
#define SEG_C_X_GPIO_Port GPIOB
#define SEG_D_Y_Pin GPIO_PIN_10
#define SEG_D_Y_GPIO_Port GPIOB
#define SEG_E_Y_Pin GPIO_PIN_11
#define SEG_E_Y_GPIO_Port GPIOB
#define SEG_F_Y_Pin GPIO_PIN_12
#define SEG_F_Y_GPIO_Port GPIOB
#define SEG_G_Y_Pin GPIO_PIN_13
#define SEG_G_Y_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_8
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_9
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_10
#define EN3_GPIO_Port GPIOA
#define SW0_Pin GPIO_PIN_11
#define SW0_GPIO_Port GPIOA
#define SW1_Pin GPIO_PIN_12
#define SW1_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_13
#define SW2_GPIO_Port GPIOA
#define SEG_D_X_Pin GPIO_PIN_3
#define SEG_D_X_GPIO_Port GPIOB
#define SEG_E_X_Pin GPIO_PIN_4
#define SEG_E_X_GPIO_Port GPIOB
#define SEG_F_X_Pin GPIO_PIN_5
#define SEG_F_X_GPIO_Port GPIOB
#define SEG_G_X_Pin GPIO_PIN_6
#define SEG_G_X_GPIO_Port GPIOB
#define SEG_A_Y_Pin GPIO_PIN_7
#define SEG_A_Y_GPIO_Port GPIOB
#define SEG_B_Y_Pin GPIO_PIN_8
#define SEG_B_Y_GPIO_Port GPIOB
#define SEG_C_Y_Pin GPIO_PIN_9
#define SEG_C_Y_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

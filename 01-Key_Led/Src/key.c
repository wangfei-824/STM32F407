/**
  ******************************************************************************
  * File Name          : key.c
  * Description        : This file provides code for the processing
  *                      of key pressed event.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "key.h"


uint8_t Scan(void)
{
    uint8_t flag = 0;
    
    if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin))
    {
        // —” ±»•∂∂∂Ø
        HAL_Delay(20);
        if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin))
        {
            flag |= 0x1;
        }
    }
    
    if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin))
    {
        HAL_Delay(20);
        if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin))
        {
            flag |= 0x2;
        }
    }
    
    return flag;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

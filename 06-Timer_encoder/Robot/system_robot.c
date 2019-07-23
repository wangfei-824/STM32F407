#include "system_robot.h"
#include "comm.h"


void system_robot_init(void)
{
    // TIM2 system interupt, 100ms.
    HAL_TIM_Base_Start_IT(&htim2);
    
    // TIM3,TIM4 two motor encoder.
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
}

//void system_robot_loop(void)
//{
//}


void system_robot_step(void)
{
    HAL_IWDG_Refresh(&hiwdg);
    
    uint16_t encoder1_inc = __HAL_TIM_GET_COUNTER(&htim3);
    uint16_t encoder2_inc = __HAL_TIM_GET_COUNTER(&htim4);
    
    send_info(&huart1, 
                "encoder1_inc: %d;  encoder2_inc: %d\r\n", 
                encoder1_inc, encoder2_inc);
}


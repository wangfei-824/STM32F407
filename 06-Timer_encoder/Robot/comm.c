#include "comm.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"


void send_info(UART_HandleTypeDef *huart, const char *format, ...)
{
    static char buff[128];
    va_list ap;
    va_start(ap, format);
    
    while(HAL_UART_GetState(huart) == HAL_UART_STATE_BUSY_TX);
    
//    uint16_t length = vsprintf(buff, format, ap);
    if(vsprintf(buff, format, ap) > 0)
    {
        HAL_UART_Transmit_DMA(huart, (uint8_t *)buff, strlen(buff));
    }
    
    va_end(ap);
}

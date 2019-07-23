#ifndef __COMM_H
#define __COMM_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx_hal.h"


     void send_info(UART_HandleTypeDef *huart, const char *format, ...);
     


#ifdef __cplusplus
}
#endif
#endif /*__COMM_H */


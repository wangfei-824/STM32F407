#ifndef __SYSTEM_ROBOT_H
#define __SYSTEM_ROBOT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"
#include "dma.h"
#include "iwdg.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

     void system_robot_init(void);
     
//     void system_robot_loop(void);
     void system_robot_step(void);


#ifdef __cplusplus
}
#endif
#endif /*__SYSTEM_ROBOT_H */


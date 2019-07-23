///* Define to prevent recursive inclusion -------------------------------------*/
//#ifndef __COMM_H
//#define __COMM_H
//#ifdef __cplusplus
// extern "C" {
//#endif
//     
//#include "main.h"
//     

////extern const uint8_t TxBuffSize;
////const uint8_t RxBuffSize = 255;
////     
////extern uint8_t USART1_TxBuffer[TxBuffSize];
////extern uint8_t USART1_RxBuffer[RxBuffSize];
//     
//__STATIC_INLINE void Comm_Transmit(DMA_TypeDef *DMAx, uint32_t Stream, USART_TypeDef *USARTx, uint8_t *buff, uint8_t length)
//{    
//    LL_DMA_ConfigAddresses(DMAx, Stream,
//                         (uint32_t)buff,
//                         LL_USART_DMA_GetRegAddr(USARTx),
//                         LL_DMA_GetDataTransferDirection(DMAx, Stream));
//    LL_DMA_SetDataLength(DMAx, Stream, length);
//    
////    LL_DMA_EnableIT_TC(DMAx, Stream);
////    LL_DMA_EnableIT_TE(DMAx, Stream);
//    
////    LL_USART_EnableDMAReq_TX(USARTx);
//    LL_DMA_EnableStream(DMAx, Stream);
//}

//__STATIC_INLINE void Comm_TransmitComplete_Callback(DMA_TypeDef *DMAx, uint32_t Stream)
//{    
//    LL_DMA_DisableStream(DMAx, Stream);
//    LL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
//}

//__STATIC_INLINE void Comm_TransmitError_Callback(DMA_TypeDef *DMAx, uint32_t Stream)
//{    
//    LL_DMA_DisableStream(DMAx, Stream);
//    LL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
//}


//void Comm_Init(void);
//void USART1_Receive_Callback(uint8_t data);

//void USART1_Rx_Check(void);
//void USART1_Rx_Process(uint8_t *data, uint8_t length);

//void test_msg(void);



//#ifdef __cplusplus
//}
//#endif
//#endif /*__ COMM_H */

///**
//  * @}
//  */

///**
//  * @}
//  */

///************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

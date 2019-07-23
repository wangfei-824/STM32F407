//#include "comm.h"
//#include <string.h>
//#include <stdio.h>

//uint8_t msg[] = "test receive dma2\r\n\0";

//const uint8_t TxBuffSize = 20;
//const uint8_t RxBuffSize = 255;
//     
//static uint8_t USART1_TxBuffer[TxBuffSize];
//static uint8_t USART1_RxBuffer[RxBuffSize];

//void test_msg(void)
//{
//    while(LL_DMA_IsEnabledStream(DMA2, LL_DMA_STREAM_7));
//    
//    memcpy(USART1_TxBuffer, msg, sizeof(msg));
//    Comm_Transmit(DMA2, LL_DMA_STREAM_7, USART1, USART1_TxBuffer, sizeof(msg));
//}

//void Comm_Init(void)
//{
//    LL_USART_DisableIT_RXNE(USART1);
//    
//    /* USART1 DMA transmit. */
//    LL_DMA_ConfigAddresses(DMA2, LL_DMA_STREAM_7,
//                         (uint32_t)USART1_TxBuffer,
//                         LL_USART_DMA_GetRegAddr(USART2),
//                         LL_DMA_GetDataTransferDirection(DMA2, LL_DMA_STREAM_7));
//    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, TxBuffSize);
//    
//    LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_7);
//    LL_DMA_EnableIT_TE(DMA2, LL_DMA_STREAM_7);
//    
//    LL_USART_EnableDMAReq_TX(USART1);
//    
//    /* USART1 DMA receive. */
//    LL_DMA_ConfigAddresses(DMA2, LL_DMA_STREAM_2,
//                         LL_USART_DMA_GetRegAddr(USART1),
//                         (uint32_t)USART1_RxBuffer,
//                         LL_DMA_GetDataTransferDirection(DMA2, LL_DMA_STREAM_2));
//    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_2, RxBuffSize);
//    
//    LL_DMA_EnableIT_HT(DMA2, LL_DMA_STREAM_2);
//    LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_2);
//    LL_DMA_EnableIT_TE(DMA2, LL_DMA_STREAM_2);
//    
//    LL_USART_EnableDMAReq_RX(USART1);
//    LL_USART_EnableIT_IDLE(USART1);
//}

//void USART1_Receive_Callback(uint8_t data)
//{
//    while(LL_DMA_IsEnabledStream(DMA2, LL_DMA_STREAM_7));
//    
//    Comm_Transmit(DMA2, LL_DMA_STREAM_7, USART1, &data, 1);
//}

//void USART1_Rx_Check(void)
//{
//    static uint8_t old_pos;
//    uint8_t pos;
//    
//    pos = RxBuffSize - LL_DMA_GetDataLength(DMA2, LL_DMA_STREAM_2);
//    if(pos != old_pos)
//    {
//        if(pos > old_pos)
//        {
//            USART1_Rx_Process(&USART1_RxBuffer[old_pos], pos - old_pos);
//        }
//        else
//        {
//            USART1_Rx_Process(&USART1_RxBuffer[old_pos], RxBuffSize - old_pos);
//            if(pos > 0)
//            {
//                USART1_Rx_Process(USART1_RxBuffer, pos);
//            }
//        }
//    }
//    
//    old_pos = pos;
//    if(old_pos == RxBuffSize)
//        old_pos = 0;
//}

//void USART1_Rx_Process(uint8_t *data, uint8_t length)
//{
//    while(LL_DMA_IsEnabledStream(DMA2, LL_DMA_STREAM_7));
//    
//    uint8_t ll = sprintf((char*)USART1_TxBuffer, "size: %d\r\n", length);
//    Comm_Transmit(DMA2, LL_DMA_STREAM_7, USART1, USART1_TxBuffer, ll);
//    
////    while(LL_DMA_IsEnabledStream(DMA2, LL_DMA_STREAM_7));
////    
//////    memcpy(USART1_TxBuffer, data, length);
////    for(uint8_t i=0; i<length; ++i)
////        USART1_TxBuffer[i] = data[i];
////    Comm_Transmit(DMA2, LL_DMA_STREAM_7, USART1, USART1_TxBuffer, length);
//}

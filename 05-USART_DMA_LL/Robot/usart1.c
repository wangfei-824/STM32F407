#include "usart1.h"
#include <string.h>
#include <stdio.h>

uint8_t msg[] = "test receive dma2\r\n\0";

const uint32_t TxBuffSize = 255;
const uint32_t RxBuffSize = 30;
     
static uint8_t USART1_TxBuffer[TxBuffSize];
static uint8_t USART1_RxBuffer[RxBuffSize];

void test_msg(void)
{
    USART1_Transmit(msg, sizeof(msg));
}

void USART1_Init(void)
{    
    /* USART1 DMA transmit. */   

//    LL_DMA_ConfigAddresses(DMA2, LL_DMA_STREAM_7,
//                         (uint32_t)USART1_TxBuffer,
//                         LL_USART_DMA_GetRegAddr(USART1),
//                         LL_DMA_GetDataTransferDirection(DMA2, LL_DMA_STREAM_7));
////    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, TxBuffSize);
//    
//    LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_7);
//    LL_DMA_EnableIT_TE(DMA2, LL_DMA_STREAM_7);
//    
//    LL_USART_EnableDMAReq_TX(USART1);
    
    
    
    /* USART1 DMA receive. */
    LL_DMA_ConfigAddresses(DMA2, LL_DMA_STREAM_2,
                         LL_USART_DMA_GetRegAddr(USART1),
                         (uint32_t)USART1_RxBuffer,
                         LL_DMA_GetDataTransferDirection(DMA2, LL_DMA_STREAM_2));
    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_2, RxBuffSize);
    
    LL_DMA_EnableIT_HT(DMA2, LL_DMA_STREAM_2);
//    LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_2);
    LL_DMA_EnableIT_TE(DMA2, LL_DMA_STREAM_2);
    
    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_2);
    
    LL_USART_EnableDMAReq_RX(USART1);
    LL_USART_EnableIT_IDLE(USART1);
    
    

//    /* USART1 interupt receive. */
//    LL_USART_EnableIT_RXNE(USART1);
}

void USART1_Transmit(uint8_t *data, uint32_t length)
{
//        const uint8_t* d = data;
//    while (length--) {
//        LL_USART_TransmitData8(USART1, *d++);
//        while (!LL_USART_IsActiveFlag_TXE(USART1));
//    }
//    while (!LL_USART_IsActiveFlag_TC(USART1));
    if(data != USART1_TxBuffer)
        memcpy(USART1_TxBuffer, data, length);
    
    while(LL_DMA_IsEnabledStream(DMA2, LL_DMA_STREAM_7));
    
    LL_DMA_ConfigAddresses(DMA2, LL_DMA_STREAM_7,
                         (uint32_t)USART1_TxBuffer,
                         LL_USART_DMA_GetRegAddr(USART1),
                         LL_DMA_GetDataTransferDirection(DMA2, LL_DMA_STREAM_7));
    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, length);
    
    LL_DMA_ClearFlag_TC7(DMA2);
    LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_7);
    LL_DMA_EnableIT_TE(DMA2, LL_DMA_STREAM_7);
    
    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_7);
    LL_USART_EnableDMAReq_TX(USART1);
}

void USART1_Receive_Callback(uint8_t data)
{
    while(LL_DMA_IsEnabledStream(DMA2, LL_DMA_STREAM_7));
    
    USART1_TxBuffer[0] = data;
    
    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, 1);
    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_7);
}

void USART1_Rx_Check(void)
{
    static uint32_t old_pos;
    uint32_t pos;
    
//    LL_DMA_DisableStream(DMA2, LL_DMA_STREAM_2);
    pos = RxBuffSize - LL_DMA_GetDataLength(DMA2, LL_DMA_STREAM_2);
////    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_2, RxBuffSize);
//    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_2);
//    LL_USART_EnableDMAReq_RX(USART1);
    
    if(pos != old_pos)
    {
        if(pos > old_pos)
        {
            USART1_Rx_Process(&USART1_RxBuffer[old_pos], pos - old_pos);
        }
        else
        {
            USART1_Rx_Process(&USART1_RxBuffer[old_pos], RxBuffSize - old_pos);
            if(pos > 0)
                USART1_Rx_Process(USART1_RxBuffer, pos);
//            memcpy(USART1_TxBuffer, &USART1_RxBuffer[old_pos], RxBuffSize - old_pos);
//            
//            if(pos > 0)
//            {
//                memcpy(&USART1_TxBuffer[RxBuffSize-old_pos], USART1_RxBuffer, pos);
//                USART1_Rx_Process(USART1_TxBuffer, RxBuffSize - old_pos + pos);
//            }
//            else
//            {
//                USART1_Rx_Process(USART1_TxBuffer, RxBuffSize - old_pos);
//            }
        }
    }
    
    old_pos = pos;
    if(old_pos == RxBuffSize)
        old_pos = 0;
}

void USART1_Rx_Process(uint8_t *data, uint32_t length)
{
////    LL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
//    
//    while(LL_DMA_IsEnabledStream(DMA2, LL_DMA_STREAM_7));
//    
////    uint32_t ll;
//    if(data != USART1_TxBuffer)
////        ll = sprintf((char*)USART1_TxBuffer, "size: %d\r\n", length);
////    else 
////        ll = length;
    memcpy(USART1_TxBuffer, data, length);
////    for(uint32_t i=0; i<length; ++i)
////        USART1_TxBuffer[i] = data[i];
//    
//    LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, length);
//    LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_7);
//    uint32_t ll = sprintf((char*)USART1_TxBuffer, "size: %d\r\n", length);
    USART1_Transmit(USART1_TxBuffer, length);
}

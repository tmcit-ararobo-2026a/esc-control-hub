#pragma once

#include <cstdint>

#include "main.h"

class mmainFW
{
public:
    void setup();
    void loop();
    inline void Get_Encoder();

    volatile int64_t Encoder_Count_Port1;
    volatile int64_t Encoder_Count_Port2;
    volatile int64_t Encoder_Count_Port3;
    volatile int64_t Encoder_Count_Port4;

    volatile bool NVIC_1Hz;
    volatile bool NVIC_1kHz;
    volatile bool NVIC_10kHz;
    volatile bool NVIC_main_FDCAN;
    volatile bool NVIC_esc_CAN;

    typedef struct {
        uint32_t Id;
        uint8_t Len;
        uint8_t Data[64];
        uint8_t* Data_p;
    } fdcan_frame_callback;

    fdcan_frame_callback main_fdcan_callback;
    fdcan_frame_callback esc_fdcan_callback;
};

extern mmainFW main_FW;

extern FDCAN_HandleTypeDef hfdcan1;
extern FDCAN_HandleTypeDef hfdcan2;

extern XSPI_HandleTypeDef hospi1;

extern RTC_HandleTypeDef hrtc;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim8;

extern PCD_HandleTypeDef hpcd_USB_DRD_FS;

#include "esc_hub/app.hpp"

#include "gn10_can/devices/esc_hub_client.hpp"


void mmainFW::setup()
{
    HAL_TIM_Base_Start(&htim2);                // 10kHz
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);  // Output PWM
    HAL_TIM_Base_Start(&htim6);                // 1kHz

    if (HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL) != HAL_OK) {
        /*エラーだよ ENC1*/
    }
    if (HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL) != HAL_OK) {
        /*エラーだよ ENC2*/
    }
    if (HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL) != HAL_OK) {
        /*エラーだよ ENC3*/
    }
    if (HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL) != HAL_OK) {
        /*エラーだよ ENC4*/
    }
}

void mmainFW::loop()
{
    if (NVIC_1Hz) {
        NVIC_1Hz = 0;
    }

    if (NVIC_1kHz) {
        NVIC_1kHz = 0;
    }

    if (NVIC_10kHz) {
        NVIC_10kHz = 0;
    }

    if (NVIC_main_FDCAN) {
    }

    if (NVIC_esc_CAN) {
        NVIC_esc_CAN = 0;
    }
}

inline void mmainFW::Get_Encoder()
{
    Encoder_Count_Port1 = __HAL_TIM_GET_COUNTER(&htim8);

    Encoder_Count_Port2 = __HAL_TIM_GET_COUNTER(&htim1);

    Encoder_Count_Port3 = __HAL_TIM_GET_COUNTER(&htim3);

    Encoder_Count_Port4 = __HAL_TIM_GET_COUNTER(&htim4);
}

mmainFW main_FW;

extern "C" {

void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef* hrtc)
{
    /**
     * 1 Hzの割り込み
     */

    main_FW.Get_Encoder();
    main_FW.NVIC_1Hz = 1;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim == &htim2) {
        /**
         * 10 kHzの割り込み
         */

        main_FW.Get_Encoder();
        main_FW.NVIC_1kHz = 1;
    }

    if (htim == &htim6) {
        /**
         * 1 kHzの割り込み
         */

        main_FW.Get_Encoder();
        main_FW.NVIC_10kHz = 1;
    }
}
}
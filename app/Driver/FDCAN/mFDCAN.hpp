
#pragma once
#include "main.h"

#include "stm32h5xx_hal_fdcan.h"
#include "mFDCAN_data_template.hpp"

namespace maidui3_hal{

class mFDCANfunction : mFDCANtemplate{
    public:
        void Init();
        void Send(uint32_t Id, uint8_t *data_p);
        void Callback(uint32_t Id, uint8_t *data_p, uint8_t Len);

        void Enable_Timeout();
        void Disable_Timeout();

        void Enable_FDCAN();
        void Disable_FDCAN();

};

};

extern maidui3_hal::mFDCANfunction mFDCAN;

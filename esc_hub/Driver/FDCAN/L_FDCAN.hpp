
#pragma once

#include "L_FDCAN_template.hpp"
#include "gn10_can/drivers/driver_interface.hpp"
#include "stm32h5xx_hal_fdcan.h"

maidui3_hal::fdcan::FDCANfunction;

namespace gn10_can{
    namespace drivers{
        class DriverHALFDCAN : public ICanDriver{
            public:
                DriverHALFDCAN(FDCAN_HandleTypeDef* hfdcanx) : hfdcanx_(hfdcanx){}

                bool init(maidui3_hal::fdcan::Fifo_Type fifo_);
                bool send(const CANFrame& frame) override;
                bool receive(CANFrame& out_frame) override;

            private:
                FDCAN_HandleTypeDef* hfdcanx_;

                maidui3_hal::fdcan::FDCANfunction W2_;
        };
    }
}

namespace maidui3_hal{
    namespace fdcan{
        class FDCANfunction{
            public:
                fdcan_state_TypeDef Timeout(Enable_and_Disable state_);
                fdcan_state_TypeDef beginning(Enable_and_Disable state_);
                fdcan_state_TypeDef Tx_Callback(Enable_and_Disable state_);
                fdcan_state_TypeDef Rx_Callback(Enable_and_Disable state_);

        };
    }
}
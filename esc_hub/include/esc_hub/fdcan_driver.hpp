
#pragma once

#include "esc_hub/fdcan_config.hpp"
#include "fdcan.h"
#include "gn10_can/drivers/driver_interface.hpp"

namespace gn10_can {
namespace drivers {
class DriverHALFDCAN : public ICanDriver
{
public:
    DriverHALFDCAN(FDCAN_HandleTypeDef* hfdcanx) : hfdcanx_(hfdcanx) {}

    bool init(maidui3_hal::fdcan::Fifo_Type fifo_);
    bool send(const CANFrame& frame) override;
    bool receive(CANFrame& out_frame) override;

private:
    FDCAN_HandleTypeDef* hfdcanx_;

    maidui3_hal::fdcan::FDCANfunction ll_fdcan;
};
}  // namespace drivers
}  // namespace gn10_can

namespace maidui3_hal {
namespace fdcan {
class FDCANfunction
{
public:
    fdcan_state_TypeDef Timeout(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_);
    fdcan_state_TypeDef beginning(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_);
    fdcan_state_TypeDef Tx_Callback(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_);
    fdcan_state_TypeDef Rx_Callback(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_);
};
}  // namespace fdcan
}  // namespace maidui3_hal

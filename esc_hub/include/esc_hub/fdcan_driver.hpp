
#pragma once

#include "fdcan.h"
#include "fdcan_ll_driver.hpp"
#include "gn10_can/drivers/fdcan_driver_interface.hpp"

namespace gn10_can {
namespace drivers {
class DriverHALFDCAN : public IFDCANDriver
{
public:
    DriverHALFDCAN(FDCAN_HandleTypeDef* hfdcanx) : hfdcanx_(hfdcanx) {}

    bool init(bool fifo_);
    bool send(const FDCANFrame& frame);
    bool receive(FDCANFrame& out_frame);

private:
    FDCAN_HandleTypeDef* hfdcanx_;

    maidui3_hal::fdcan::FDCAN fdcan_;
    uint8_t rx_data[64];
    uint32_t stock_fifo;
};
}  // namespace drivers
}  // namespace gn10_can


#pragma once

#include "fdcan.h"
#include "gn10_can/drivers/fdcan_driver_interface.hpp"

namespace gn10_can {
namespace drivers {
class DriverHALFDCAN : public IFDCANDriver
{
public:
    DriverHALFDCAN(FDCAN_HandleTypeDef* hfdcanx) : hfdcanx_(hfdcanx) {}

    bool init(maidui3_hal::fdcan::Fifo_Type fifo_);
    bool send(const FDCANFrame& frame);
    bool receive(FDCANFrame& out_frame);

private:
    FDCAN_HandleTypeDef* hfdcanx_;

    maidui3_hal::fdcan::FDCANfunction ll_fdcan;
};
}  // namespace drivers
}  // namespace gn10_can

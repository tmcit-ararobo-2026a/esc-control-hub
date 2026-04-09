
#include "esc_hub/fdcan_driver.hpp"

namespace gn10_can {
namespace drivers {

bool DriverHALFDCAN::init(bool fifo_)
{
    if (fifo_)
        stock_fifo = FDCAN_RX_FIFO1;
    else
        stock_fifo = FDCAN_RX_FIFO0;
    if (fdcan_.init(hfdcanx_, fifo_) == maidui3_hal::fdcan::fdcan_state_TypeDef::Error) {
        return false;
    }
    return true;
}

bool DriverHALFDCAN::send(const FDCANFrame& frame)
{
    if (frame.is_extended) {
        fdcan_.FDCAN_TxHeader.IdType = FDCAN_EXTENDED_ID;
    } else {
        fdcan_.FDCAN_TxHeader.IdType = FDCAN_STANDARD_ID;
    }

    if (frame.MAX_DLC == 64) {
        fdcan_.FDCAN_TxHeader.FDFormat = FDCAN_FD_CAN;
    } else if (frame.MAX_DLC == 8) {
        fdcan_.FDCAN_TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
    }

    fdcan_.FDCAN_TxHeader.Identifier = frame.id;
    fdcan_.FDCAN_TxHeader.DataLength = frame.dlc;

    if (HAL_FDCAN_AddMessageToTxFifoQ(hfdcanx_, &fdcan_.FDCAN_TxHeader, const_cast<uint8_t*>(frame.data.data())) != HAL_OK) {
        return false;
    }
    return true;
}

bool DriverHALFDCAN::receive(FDCANFrame& out_frame)
{
    if (HAL_FDCAN_GetRxMessage(hfdcanx_, stock_fifo, &fdcan_.FDCAN_RxHeader, rx_data) != HAL_OK) {
        return false;
    }

    out_frame.id          = fdcan_.FDCAN_RxHeader.Identifier;
    out_frame.dlc         = fdcan_.FDCAN_RxHeader.DataLength;
    out_frame.is_extended = (fdcan_.FDCAN_RxHeader.IdType == FDCAN_EXTENDED_ID);

    for (uint8_t i = 0; i < out_frame.dlc; i++) {
        out_frame.data[i] = rx_data[i];
    }
    return true;
}

}  // namespace drivers
}  // namespace gn10_can

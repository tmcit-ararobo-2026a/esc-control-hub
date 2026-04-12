
#pragma once

#include "esc_hub/fdcan_hal_config.hpp"
#include "fdcan.h"

namespace maidui3_hal {
namespace fdcan {
class FDCAN
{
public:
    fdcan_state_TypeDef init(FDCAN_HandleTypeDef* hfdcanx_, bool fifo_ = 0);

    fdcan_state_TypeDef timeout_enable(FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_);

    fdcan_state_TypeDef timeout_disable(FDCAN_HandleTypeDef* hfdcanx_);

    fdcan_state_TypeDef beginning_enable(FDCAN_HandleTypeDef* hfdcanx_);

    fdcan_state_TypeDef beginning_disable(FDCAN_HandleTypeDef* hfdcanx_);

    fdcan_state_TypeDef tx_Callback_enable(FDCAN_HandleTypeDef* hfdcanx_);

    fdcan_state_TypeDef tx_Callback_disable(FDCAN_HandleTypeDef* hfdcanx_);

    fdcan_state_TypeDef rx_Callback_enable(FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_);

    fdcan_state_TypeDef rx_Callback_disable(FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_);

    FDCAN_TxHeaderTypeDef FDCAN_TxHeader;
    FDCAN_RxHeaderTypeDef FDCAN_RxHeader;

private:
    State_HandleTypeDef State;

    FDCAN_FilterTypeDef FDCAN_filter;
};
}  // namespace fdcan
}  // namespace maidui3_hal

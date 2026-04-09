
#pragma once

#include "esc_hub/fdcan_LL_config.hpp"
#include "fdcan.h"

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

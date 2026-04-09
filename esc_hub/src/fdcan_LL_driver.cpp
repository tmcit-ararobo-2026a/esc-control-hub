
#include "fdcan_LL_driver.hpp"

namespace maidui3_hal {
namespace fdcan {
fdcan_state_TypeDef FDCANfunction::Timeout(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_)
{
    if (state_ == Enable_and_Disable::Enable) {
    } else {
        HAL_FDCAN_DisableTimeoutCounter(hfdcanx_);
    }
}

fdcan_state_TypeDef FDCANfunction::beginning(
    Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_
)
{
    if (state_ == Enable_and_Disable::Enable) {
        if (HAL_FDCAN_Start(hfdcanx_) == HAL_OK) {
            return fdcan_state_TypeDef::ERROR;
        }
    } else {
        if (HAL_FDCAN_Stop(hfdcanx_) == HAL_OK) {
            return fdcan_state_TypeDef::ERROR;
        }
    }
    return fdcan_state_TypeDef::COMPLETE;
}

fdcan_state_TypeDef FDCANfunction::Tx_Callback(
    Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_
)
{
}

fdcan_state_TypeDef FDCANfunction::Rx_Callback(
    Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_
)
{
}

}  // namespace fdcan
}  // namespace maidui3_hal
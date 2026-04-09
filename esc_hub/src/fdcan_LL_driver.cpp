
#include "fdcan_LL_driver.hpp"

namespace maidui3_hal {
namespace fdcan {

fdcan_state_TypeDef FDCANfunction::Timeout(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_)
{
    if (state_ == Enable_and_Disable::Enable) {
        if (fifo_ == Fifo_Type::_FIFO0_) {
            if (HAL_FDCAN_ConfigTimeoutCounter(hfdcanx_, FDCAN_TIMEOUT_RX_FIFO0, 2000) != HAL_OK) {
                State.Config.TimeoutNVIC = 1;
            }
        } else if (fifo_ == Fifo_Type::_FIFO1_) {
            if (HAL_FDCAN_ConfigTimeoutCounter(hfdcanx_, FDCAN_TIMEOUT_RX_FIFO1, 2000) != HAL_OK) {
                State.Config.TimeoutNVIC = 1;
            }
        }

        if (HAL_FDCAN_ActivateNotification(hfdcanx_, FDCAN_IT_TIMEOUT_OCCURRED, 0) != HAL_OK) {
            State.Config.TimeoutNVIC = 1;
        }

        if (HAL_FDCAN_EnableTimeoutCounter(hfdcanx_) != HAL_OK) {
            State.Config.TimeoutCounter = 1;
        }
    } else {
        if (HAL_FDCAN_DeactivateNotification(hfdcanx_, FDCAN_IT_TIMEOUT_OCCURRED) != HAL_OK) {
            State.Config.TimeoutNVIC = 1;
        }

        if (HAL_FDCAN_DisableTimeoutCounter(hfdcanx_) != HAL_OK) {
            State.Config.TimeoutCounter = 1;
        }
    }
}

fdcan_state_TypeDef FDCANfunction::beginning(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_)
{
    if (state_ == Enable_and_Disable::Enable) {
        if (HAL_FDCAN_Start(hfdcanx_) == HAL_OK) {
            State.Config.beginning = 1;
            return fdcan_state_TypeDef::Error;
        }
    } else {
        if (HAL_FDCAN_Stop(hfdcanx_) == HAL_OK) {
            State.Config.beginning = 1;
            return fdcan_state_TypeDef::Error;
        }
    }
    return fdcan_state_TypeDef::Complete;
}

fdcan_state_TypeDef FDCANfunction::Tx_Callback(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_)
{
    if (state_ == Enable_and_Disable::Enable) {
        if (HAL_FDCAN_ActivateNotification(hfdcanx_, FDCAN_IT_TX_COMPLETE, 0) != HAL_OK) {
            State.Config.TxCallback = 1;
        }
    } else {
        if (HAL_FDCAN_DeactivateNotification(hfdcanx_, FDCAN_IT_TX_COMPLETE) != HAL_OK) {
            State.Config.TxCallback = 1;
        }
    }
}

fdcan_state_TypeDef FDCANfunction::Rx_Callback(Enable_and_Disable state_, FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_)
{
    if (state_ == Enable_and_Disable::Enable) {
        if (fifo_ == Fifo_Type::_FIFO0_) {
            if (HAL_FDCAN_ActivateNotification(hfdcanx_, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_RX_FIFO0_FULL, 0) != HAL_OK) {
                State.Config.RxCallback = 1;
            }
        } else if (fifo_ == Fifo_Type::_FIFO1_) {
            if (HAL_FDCAN_ActivateNotification(hfdcanx_, FDCAN_IT_RX_FIFO1_NEW_MESSAGE | FDCAN_IT_RX_FIFO1_FULL, 0) != HAL_OK) {
                State.Config.RxCallback = 1;
            }
        }
    } else {
        if (fifo_ == Fifo_Type::_FIFO0_) {
            if (HAL_FDCAN_DeactivateNotification(hfdcanx_, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_RX_FIFO0_FULL) != HAL_OK) {
                State.Config.RxCallback = 1;
            }
        } else if (fifo_ == Fifo_Type::_FIFO1_) {
            if (HAL_FDCAN_DeactivateNotification(hfdcanx_, FDCAN_IT_RX_FIFO1_NEW_MESSAGE | FDCAN_IT_RX_FIFO1_FULL) != HAL_OK) {
                State.Config.RxCallback = 1;
            }
        }
    }
}

}  // namespace fdcan
}  // namespace maidui3_hal
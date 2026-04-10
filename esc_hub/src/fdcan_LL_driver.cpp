
#include "esc_hub/fdcan_ll_driver.hpp"

namespace maidui3_hal {
namespace fdcan {

fdcan_state_TypeDef FDCAN::init(FDCAN_HandleTypeDef* hfdcanx_, bool fifo_)
{
    Fifo_Type _fifo_;
    if (fifo_) {
        _fifo_                    = Fifo_Type::_FIFO1_;
        FDCAN_filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO1;
    } else {
        _fifo_                    = Fifo_Type::_FIFO0_;
        FDCAN_filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    }

    if (timeout_disable(hfdcanx_) == fdcan_state_TypeDef::Error) {
        return fdcan_state_TypeDef::Error;
    }

    if (beginning_disable(hfdcanx_) == fdcan_state_TypeDef::Error) {
        return fdcan_state_TypeDef::Error;
    }

    if (tx_Callback_disable(hfdcanx_) == fdcan_state_TypeDef::Error) {
        return fdcan_state_TypeDef::Error;
    }

    if (rx_Callback_disable(hfdcanx_, _fifo_) == fdcan_state_TypeDef::Error) {
        return fdcan_state_TypeDef::Error;
    }

    FDCAN_filter.IdType      = FDCAN_STANDARD_ID;
    FDCAN_filter.FilterIndex = 0;
    FDCAN_filter.FilterType  = FDCAN_FILTER_MASK;
    FDCAN_filter.FilterID1   = 0;
    FDCAN_filter.FilterID2   = 0;

    FDCAN_TxHeader.TxFrameType         = FDCAN_DATA_FRAME;
    FDCAN_TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    FDCAN_TxHeader.BitRateSwitch       = FDCAN_BRS_OFF;
    FDCAN_TxHeader.TxEventFifoControl  = FDCAN_STORE_TX_EVENTS;
    FDCAN_TxHeader.MessageMarker       = 0;

    if (HAL_FDCAN_ConfigFilter(hfdcanx_, &FDCAN_filter) != HAL_OK) {
        State.Config.Param = 1;
        return fdcan_state_TypeDef::Error;
    }

    if (timeout_enable(hfdcanx_, _fifo_) == fdcan_state_TypeDef::Error) {
        return fdcan_state_TypeDef::Error;
    }

    if (tx_Callback_enable(hfdcanx_) == fdcan_state_TypeDef::Error) {
        return fdcan_state_TypeDef::Error;
    }

    if (rx_Callback_enable(hfdcanx_, _fifo_) == fdcan_state_TypeDef::Error) {
        return fdcan_state_TypeDef::Error;
    }

    if (beginning_enable(hfdcanx_) == fdcan_state_TypeDef::Error) {
        return fdcan_state_TypeDef::Error;
    }
}

fdcan_state_TypeDef FDCAN::timeout_enable(FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_)
{
    if (fifo_ == Fifo_Type::_FIFO0_) {
        if (HAL_FDCAN_ConfigTimeoutCounter(hfdcanx_, FDCAN_TIMEOUT_RX_FIFO0, 2000) != HAL_OK) {
            State.Config.TimeoutNVIC = 1;
            return fdcan_state_TypeDef::Error;
        }
    } else if (fifo_ == Fifo_Type::_FIFO1_) {
        if (HAL_FDCAN_ConfigTimeoutCounter(hfdcanx_, FDCAN_TIMEOUT_RX_FIFO1, 2000) != HAL_OK) {
            State.Config.TimeoutNVIC = 1;
            return fdcan_state_TypeDef::Error;
        }
    }

    if (HAL_FDCAN_ActivateNotification(hfdcanx_, FDCAN_IT_TIMEOUT_OCCURRED, 0) != HAL_OK) {
        State.Config.TimeoutNVIC = 1;
        return fdcan_state_TypeDef::Error;
    }

    if (HAL_FDCAN_EnableTimeoutCounter(hfdcanx_) != HAL_OK) {
        State.Config.TimeoutCounter = 1;
        return fdcan_state_TypeDef::Error;
    }
    return fdcan_state_TypeDef::Complete;
}

fdcan_state_TypeDef FDCAN::timeout_disable(FDCAN_HandleTypeDef* hfdcanx_)
{
    if (HAL_FDCAN_DeactivateNotification(hfdcanx_, FDCAN_IT_TIMEOUT_OCCURRED) != HAL_OK) {
        State.Config.TimeoutNVIC = 1;
        return fdcan_state_TypeDef::Error;
    }

    if (HAL_FDCAN_DisableTimeoutCounter(hfdcanx_) != HAL_OK) {
        State.Config.TimeoutCounter = 1;
        return fdcan_state_TypeDef::Error;
    }
    return fdcan_state_TypeDef::Complete;
}

fdcan_state_TypeDef FDCAN::beginning_enable(FDCAN_HandleTypeDef* hfdcanx_)
{
    if (HAL_FDCAN_Start(hfdcanx_) == HAL_OK) {
        State.Config.beginning = 1;
        return fdcan_state_TypeDef::Error;
    }
    return fdcan_state_TypeDef::Complete;
}

fdcan_state_TypeDef FDCAN::beginning_disable(FDCAN_HandleTypeDef* hfdcanx_)
{
    if (HAL_FDCAN_Stop(hfdcanx_) == HAL_OK) {
        State.Config.beginning = 1;
        return fdcan_state_TypeDef::Error;
    }
    return fdcan_state_TypeDef::Complete;
}

fdcan_state_TypeDef FDCAN::tx_Callback_enable(FDCAN_HandleTypeDef* hfdcanx_)
{
    if (HAL_FDCAN_ActivateNotification(hfdcanx_, FDCAN_IT_TX_COMPLETE, 0) != HAL_OK) {
        State.Config.TxCallback = 1;
        return fdcan_state_TypeDef::Error;
    }
    return fdcan_state_TypeDef::Complete;
}

fdcan_state_TypeDef FDCAN::tx_Callback_disable(FDCAN_HandleTypeDef* hfdcanx_)
{
    if (HAL_FDCAN_DeactivateNotification(hfdcanx_, FDCAN_IT_TX_COMPLETE) != HAL_OK) {
        State.Config.TxCallback = 1;
        return fdcan_state_TypeDef::Error;
    }
    return fdcan_state_TypeDef::Complete;
}

fdcan_state_TypeDef FDCAN::rx_Callback_enable(FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_)
{
    if (fifo_ == Fifo_Type::_FIFO0_) {
        if (HAL_FDCAN_ActivateNotification(hfdcanx_, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_RX_FIFO0_FULL, 0) != HAL_OK) {
            State.Config.RxCallback = 1;
            return fdcan_state_TypeDef::Error;
        }
    } else if (fifo_ == Fifo_Type::_FIFO1_) {
        if (HAL_FDCAN_ActivateNotification(hfdcanx_, FDCAN_IT_RX_FIFO1_NEW_MESSAGE | FDCAN_IT_RX_FIFO1_FULL, 0) != HAL_OK) {
            State.Config.RxCallback = 1;
            return fdcan_state_TypeDef::Error;
        }
    }
    return fdcan_state_TypeDef::Complete;
}

fdcan_state_TypeDef FDCAN::rx_Callback_disable(FDCAN_HandleTypeDef* hfdcanx_, Fifo_Type fifo_)
{
    if (fifo_ == Fifo_Type::_FIFO0_) {
        if (HAL_FDCAN_DeactivateNotification(hfdcanx_, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_RX_FIFO0_FULL) != HAL_OK) {
            State.Config.RxCallback = 1;
            return fdcan_state_TypeDef::Error;
        }
    } else if (fifo_ == Fifo_Type::_FIFO1_) {
        if (HAL_FDCAN_DeactivateNotification(hfdcanx_, FDCAN_IT_RX_FIFO1_NEW_MESSAGE | FDCAN_IT_RX_FIFO1_FULL) != HAL_OK) {
            State.Config.RxCallback = 1;
            return fdcan_state_TypeDef::Error;
        }
    }
    return fdcan_state_TypeDef::Complete;
}

}  // namespace fdcan
}  // namespace maidui3_hal
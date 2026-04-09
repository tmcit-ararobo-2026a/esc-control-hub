
#pragma once
#include <cstdint>

namespace maidui3_hal {
namespace fdcan {

enum class fdcan_state_TypeDef : bool {
    Complete,
    Error,
};

enum class Enable_and_Disable : bool {
    Enable,
    Disable,
};

enum class Fifo_Type : bool {
    _FIFO0_,
    _FIFO1_,
};

typedef struct {
    struct {
        bool TimeoutNVIC;
        bool TimeoutCounter;
        bool beginning;
        bool TxCallback;
        bool RxCallback;
    } Config;
} State_HandleTypeDef;

}  // namespace fdcan
}  // namespace maidui3_hal
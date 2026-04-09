
#pragma once
#include <cstdint>

namespace maidui3_hal{
    namespace fdcan{
        enum class fdcan_state_TypeDef : bool{
            COMPLETE,
            ERROR,
        };

        enum class Enable_and_Disable : bool{
            Enable,
            Disable,
        };

        enum class Fifo_Type : bool{
            _FIFO0_,
            _FIFO1_,
        };
    }
}
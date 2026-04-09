
#include "L_FDCAN.hpp"

namespace gn10_can{
    namespace drivers{
        bool DriverHALFDCAN::init(maidui3_hal::fdcan::Fifo_Type fifo_){
            FDCAN_FilterTypeDef filter;

            filter.IdType       = FDCAN_STANDARD_ID;
            filter.FilterIndex  = 0;
            filter.FilterType   = FDCAN_FILTER_MASK;
            filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
            filter.FilterID1    = 0x000;
            filter.FilterID2    = 0x000;

            if(HAL_FDCAN_ConfigFilter(hfdcanx_, &filter) != HAL_OK){
                
            }

            W2_.Timeout(maidui3_hal::fdcan::Enable_and_Disable::Enable);
            W2_.Tx_Callback(maidui3_hal::fdcan::Enable_and_Disable::Enable);
            W2_.Rx_Callback(maidui3_hal::fdcan::Enable_and_Disable::Enable);
            W2_.beginning(maidui3_hal::fdcan::Enable_and_Disable::Enable);

        }
    }
}

namespace maidui3_hal{
    namespace fdcan{
        fdcan_state_TypeDef FDCANfunction::Timeout(Enable_and_Disable state_){

        }

        fdcan_state_TypeDef FDCANfunction::beginning(Enable_and_Disable state_){

        }

        fdcan_state_TypeDef FDCANfunction::Tx_Callback(Enable_and_Disable state_){

        }

        fdcan_state_TypeDef FDCANfunction::Rx_Callback(Enable_and_Disable state_){

        }

    }
}
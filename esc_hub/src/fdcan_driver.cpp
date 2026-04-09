
#include "esc_hub/fdcan_driver.hpp"

namespace gn10_can {
namespace drivers {
bool DriverHALFDCAN::init(maidui3_hal::fdcan::Fifo_Type fifo_)
{
    FDCAN_FilterTypeDef filter;

    filter.IdType       = FDCAN_STANDARD_ID;
    filter.FilterIndex  = 0;
    filter.FilterType   = FDCAN_FILTER_MASK;
    filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    filter.FilterID1    = 0x000;
    filter.FilterID2    = 0x000;

    if (HAL_FDCAN_ConfigFilter(hfdcanx_, &filter) != HAL_OK) {
    }

    ll_fdcan.Timeout(maidui3_hal::fdcan::Enable_and_Disable::Enable, hfdcanx_);
    ll_fdcan.Tx_Callback(maidui3_hal::fdcan::Enable_and_Disable::Enable, hfdcanx_);
    ll_fdcan.Rx_Callback(maidui3_hal::fdcan::Enable_and_Disable::Enable, hfdcanx_);
    ll_fdcan.beginning(maidui3_hal::fdcan::Enable_and_Disable::Enable, hfdcanx_);
}
}  // namespace drivers
}  // namespace gn10_can

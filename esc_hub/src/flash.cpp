#include "esc_hub/flash.hpp"

namespace maidui3_hal {
namespace XSPI {

State flash::Init(XSPI_HandleTypeDef hxspix_)
{
    return State::Standby;
}

}  // namespace XSPI
}  // namespace maidui3_hal

/*stm32h5xx_hal_xspi.h*/

#include "esc_hub/flash.hpp"

namespace maidui3_hal {
namespace QuadSPI {

State flash::Init() {}

State flash::Write()
{
    Cmd.OperationType   = HAL_XSPI_OPTYPE_READ_CFG;
    Cmd.Instruction     = 0x02;
    Cmd.InstructionMode = HAL_XSPI_INSTRUCTION_1_LINE;
    Cmd.AddressMode     = HAL_XSPI_ADDRESS_1_LINE;
    Cmd.AddressWidth    = HAL_XSPI_ADDRESS_24_BITS;
    Cmd.DataMode        = HAL_XSPI_DATA_4_LINES;
    Cmd.Address         = 0;

    HAL_XSPI_Command(&hxspi1, &Cmd, HAL_XSPI_TIMEOUT_DEFAULT_VALUE);
    HAL_XSPI_Transmit(&hxspi1, )
}

State flash::Read() {}

}  // namespace QuadSPI
}  // namespace maidui3_hal

/*stm32h5xx_hal_xspi.h*/

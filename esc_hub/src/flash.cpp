#include "esc_hub/flash.hpp"

namespace maidui3_hal {
namespace XSPI {

State flash::Init() {}

State flash::Write()
{
    Cmd.OperationType;
    Cmd.IOSelect;

    Cmd.Instruction;
    Cmd.InstructionMode;
    Cmd.InstructionWidth;
    Cmd.InstructionDTRMode;

    Cmd.Address;
    Cmd.AddressMode;
    Cmd.AddressWidth;
    Cmd.AddressDTRMode;

    Cmd.AlternateBytes;
    Cmd.AlternateBytesMode;
    Cmd.AlternateBytesWidth;
    Cmd.AlternateBytesDTRMode;

    Cmd.DataMode;
    Cmd.DataLength;
    Cmd.DataDTRMode;
    Cmd.DummyCycles;
    Cmd.DQSMode;
    Cmd.SIOOMode;

    HAL_XSPI_Command(&hxspi1, &Cmd, HAL_XSPI_TIMEOUT_DEFAULT_VALUE);
    HAL_XSPI_Transmit(&hxspi1, )
}

State flash::Read() {}

}  // namespace XSPI
}  // namespace maidui3_hal

/*stm32h5xx_hal_xspi.h*/


#pragma once
#include "esc_hub/flash_data_config.hpp"
#include "octospi.h"

namespace maidui3_hal {
namespace XSPI {

class flash
{
public:
    State Init(XSPI_HandleTypeDef hxspix_);

    State SPI_Write();
    State SPI_Read();

    State QSPI_Write();
    State QSPI_Read();

private:
    XSPI_RegularCmdTypeDef Cmd_   = {0};
    XSPI_MemoryMappedTypeDef Map_ = {0};
    XSPI_HandleTypeDef hxspix_    = {0};
};

};  // namespace XSPI
};  // namespace maidui3_hal

extern maidui3_hal::XSPI::flash Flash;

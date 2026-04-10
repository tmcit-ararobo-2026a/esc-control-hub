
#pragma once
#include "esc_hub/flash_data_config.hpp"
#include "octospi.h"

namespace maidui3_hal {
namespace QuadSPI {

class flash
{
public:
    State Init();
    State Write();
    State Read();

private:
};

};  // namespace QuadSPI
};  // namespace maidui3_hal

extern maidui3_hal::QuadSPI::flash Flash;

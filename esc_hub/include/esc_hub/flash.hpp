
#pragma once
#include "esc_hub/flash_data_config.hpp"

namespace maidui3_hal{

class mFLASHfunction : mFLASHtemplate{
    public:
        State Init();
        State Write();
        State Read();
};

};

extern maidui3_hal::mFLASHfunction mFLASH;

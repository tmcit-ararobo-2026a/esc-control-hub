
#pragma once
#include "Flash_data_template.hpp"

namespace maidui3_hal{

class mFLASHfunction : mFLASHtemplate{
    public:
        State Init();
        State Write();
        State Read();
};

};

extern maidui3_hal::mFLASHfunction mFLASH;

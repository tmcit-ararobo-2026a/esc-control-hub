
#pragma once
#include "mFLASH_data_template.hpp"

class mFLASH_function : mFLASH_data_template{
    public:
        State Init();
        State Write();
        State Read();
};

extern mFLASH_function mFLASH;

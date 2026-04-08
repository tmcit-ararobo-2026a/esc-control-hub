
#pragma once
#include <cstdint>

namespace maidui3_hal{

class mFDCANtemplate
{
    static constexpr uint32_t dlc_table[16] = {
        FDCAN_DLC_BYTES_0,
        FDCAN_DLC_BYTES_1,
        FDCAN_DLC_BYTES_2,
        FDCAN_DLC_BYTES_3,
        FDCAN_DLC_BYTES_4,
        FDCAN_DLC_BYTES_5,
        FDCAN_DLC_BYTES_6,
        FDCAN_DLC_BYTES_7,
        FDCAN_DLC_BYTES_8,
        FDCAN_DLC_BYTES_12,
        FDCAN_DLC_BYTES_16,
        FDCAN_DLC_BYTES_20,
        FDCAN_DLC_BYTES_24,
        FDCAN_DLC_BYTES_32,
        FDCAN_DLC_BYTES_48,
        FDCAN_DLC_BYTES_64,
    };


#define Data_len(len) ((len >= 0) && (len <= 64)) ? (len <= 8 ? dlc_table[len] : (len <= 12 ? dlc_table[9] : \
                      (len <= 16 ? dlc_table[10] : (len <= 20 ? dlc_table[11] : (len <= 24 ? dlc_table[12] : \
                      (len <= 32 ? dlc_table[13] : (len <= 48 ? dlc_table[14] : dlc_table[15]))))))) : dlc_table[0]
};

}


#pragma once

#include <cstdint>

namespace maidui3_hal {
namespace XSPI {

typedef struct {
    uint32_t addr;
    uint8_t reg_bit;
};

typedef struct {
} reg;

}  // namespace XSPI
}  // namespace maidui3_hal
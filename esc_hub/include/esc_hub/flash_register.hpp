
#pragma once

#include <cstdint>

namespace maidui3_hal {
namespace QuadSPI {

typedef struct {
    uint32_t addr;
    uint8_t reg_bit;
};

typedef struct {
} reg;

}  // namespace QuadSPI
}  // namespace maidui3_hal
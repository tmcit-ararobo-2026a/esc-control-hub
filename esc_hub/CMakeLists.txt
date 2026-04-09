cmake_minimum_required(VERSION 3.22)

add_library(esc_hub STATIC
    src/app.cpp
    src/fdcan_ll_driver.cpp
    src/fdcan_driver.cpp
    src/flash.cpp
    src/usb_fs.cpp
)

target_include_directories(esc_hub PUBLIC
    include
)

target_compile_features(esc_hub PUBLIC cxx_std_17)

target_link_libraries(esc_hub PRIVATE gn10_can)
target_link_libraries(esc_hub PRIVATE stm32cubemx)
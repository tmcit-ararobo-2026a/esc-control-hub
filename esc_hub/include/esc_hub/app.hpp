#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/**
 * @brief 最初に１回だけ実行される関数
 */
void setup();

/**
 * @brief setup関数終了後実行され続けるループ関数
 */
void loop();
#ifdef __cplusplus
}
#endif
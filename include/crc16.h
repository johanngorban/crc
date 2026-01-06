#pragma once

#include <stdint.h>

void crc16_init();

uint16_t crc16_compute(const uint8_t *data, uint16_t length);

uint16_t crc16_old(const uint16_t *data, uint16_t length);
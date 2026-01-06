#include "crc16.h"

#define CRC16_WIDTH                 (16)
#define CRC16_TOPBIT                (1 << (CRC16_WIDTH - 1))
#define CRC16_POLYNOMIAL            (0x1021)
#define CRC16_INITIAL_REMAINDER     (0xFFFF)
#define CRC16_FINAL_XOR_VALUE       (0x0000)


static uint16_t crc16_table[256];

void crc16_init() {
    for (uint16_t dividend = 0; dividend < 256; dividend++) {
        uint16_t remainder = dividend << (CRC16_WIDTH - 8);
        for (uint8_t bit = 0; bit < 8; bit++) {
            if (remainder & CRC16_TOPBIT) {
                remainder = (remainder << 1) ^ CRC16_POLYNOMIAL;
            }
            else {
                remainder <<= 1;
            }
        }

        crc16_table[dividend] = remainder;
    }
}

uint16_t crc16_compute(const uint8_t *data, uint16_t length) {
    uint16_t remainder = CRC16_INITIAL_REMAINDER;
    
    for (uint16_t i = 0; i < length; i++) {
        uint8_t byte = (remainder >> (CRC16_WIDTH - 8)) ^ data[i];
        remainder = crc16_table[byte] ^ (remainder << 8);
    }

    return (remainder ^ CRC16_FINAL_XOR_VALUE);
}
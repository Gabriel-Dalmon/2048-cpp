#include "../../include/utils/BitMaths.h"

int absBitOperation(int num) {
    int mask = num >> (sizeof(int) * 8 - 1);  // Get the sign bit
    return (num + mask) ^ mask;
}

int absBitOperation(int num, int* bitMask) {
    *bitMask = num >> (sizeof(int) * 8 - 1);  // Get the sign bit
    return (num + *bitMask) ^ *bitMask;
};
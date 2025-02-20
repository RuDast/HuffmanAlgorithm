#include <stdio.h>
#include "../headers/utils.h"

void write_bit(BitWriter* bw, int bit) {
    bw->buffer = (bw->buffer << 1) | (bit & 1);
    bw->bit_count++;
    if (bw->bit_count == 8) {
        fputc(bw->buffer, bw->file);
        bw->bit_count = 0;
        bw->buffer = 0;
    }
}

void flush_bit_writer(BitWriter* bw) {
    if (bw->bit_count > 0) {
        bw->buffer <<= (8 - bw->bit_count);
        fputc(bw->buffer, bw->file);
        bw->bit_count = 0;
        bw->buffer = 0;
    }
}

int read_bit(BitReader* br) {
    if (br->bit_count == 0) {
        int temp = fgetc(br->file);
        if (temp == EOF) return -1;
        br->buffer = (unsigned char)temp;
        br->bit_count = 8;
    }
    int bit = (br->buffer >> (br->bit_count - 1)) & 1;
    br->bit_count--;
    return bit;
}
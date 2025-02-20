#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

typedef struct {
    FILE *file;
    unsigned char buffer;
    int bit_count;
} BitWriter;

typedef struct {
    FILE *file;
    unsigned char buffer;
    int bit_count;
} BitReader;

void write_bit(BitWriter* bw, int bit);
void flush_bit_writer(BitWriter* bw);
int read_bit(BitReader* br);

#endif // UTILS_H

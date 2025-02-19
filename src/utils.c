#include <stdio.h>
#include <stdlib.h>

#include "../headers/utils.h"
#include "../headers/huffman.h"

void encode(const char* filename) {

}

void countFrequencies(const char *filename, int freq[256]) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("File open error!\n");
        return;
    }

    fseek(file, 0L, SEEK_END);
    const long long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < length; ++i)
    {
        freq[(unsigned char)fgetc(file)] ++;
    }
    fclose(file);
}



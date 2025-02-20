#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/huffman.h"
#include "../headers/utils.h"
#include "../headers/compression.h"

int decode(const char* input_filename, const char* output_extension) {
    FILE* inputFile = fopen(input_filename, "rb");
    if (!inputFile) {
        return -1;
    }

    int freq[256];
    if (fread(freq, sizeof(int), 256, inputFile) != 256) {
        return -1;
    }

    HuffmanNode* root = generateTree(freq);
    if (root == NULL) {
        return -1;
    }

    char output_filename[256];
    strcpy(output_filename, input_filename);
    char *dot = strrchr(output_filename, '.');
    if (dot) {
        strcpy(dot, output_extension);
    } else {
        strcat(output_filename, output_extension);
    }

    FILE* out = fopen(output_filename, "wb");
    if (!out) {
        return -1;
    }

    long total_symbols = 0;
    for (int i = 0; i < 256; i++) {
        total_symbols += freq[i];
    }

    BitReader br;
    br.file = inputFile;
    br.buffer = 0;
    br.bit_count = 0;
    HuffmanNode* current = root;
    int bit = 0;
    while (total_symbols > 0) {
        bit = read_bit(&br);
        if (bit == -1)
            break;
        current = bit == 0 ? current->left : current->right;

        if (!current->left && !current->right) {
            fputc(current->ch, out);
            total_symbols--;
            current = root;
        }
    }

    fclose(inputFile);
    fclose(out);
    deleteTree(root);
    return 0;
}

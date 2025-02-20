#include <stdio.h>

#include "../headers/huffman.h"
#include "../headers/utils.h"
#include "../headers/encode.h"

int encode(const char* input_filename, const char* output_filename) {
    int freq[256] = {0};

    FILE *inputFile = fopen(input_filename, "rb");
    if (!inputFile) {
        return -1;
    }
    int ch;
    while ((ch = fgetc(inputFile)) != EOF)
        freq[ch]++;
    fseek(inputFile, 0, SEEK_SET);


    HuffmanNode* root = generateTree(freq);
    if (!root)
        return -1;

    char codes[256][256] = {{0}};
    char code[256];
    generateCodes(root, code, 0, codes);

    FILE *outputFile = fopen(output_filename, "wb");
    if (!outputFile) {
        return -1;
    }

    if (fwrite(freq, sizeof(int), 256, outputFile) != 256) {
        return -1;
    }

    BitWriter bw;
    bw.file = outputFile;
    bw.buffer = 0;
    bw.bit_count = 0;
    while ((ch = fgetc(inputFile)) != EOF) {
        for (int i = 0; codes[ch][i] != '\0'; i++) {
            write_bit(&bw, (codes[ch][i] == '1') ? 1 : 0);
        }
    }
    flush_bit_writer(&bw);

    fclose(inputFile);
    fclose(outputFile);
    deleteTree(root);
    return 0;
}

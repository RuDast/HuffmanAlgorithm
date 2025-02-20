#include "test.h"

#include <stdio.h>
#include <time.h>
#include "../headers/compression.h"

void test(const char *input_filename, const char *output_filename, const char *decode_filename) {
    clock_t start = clock();
    encode(input_filename, output_filename);
    clock_t end = clock();
    double time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The file was compressed in %lf seconds.\n", time);

    start = clock();
    encode(output_filename, decode_filename);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("The file was decompressed in %lf seconds.\n", time);
}
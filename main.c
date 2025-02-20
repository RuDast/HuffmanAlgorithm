#include "headers/compression.h"

int main(void) {
    encode("F:\\HuffmanAlgorithm\\input.txt", "F:\\HuffmanAlgorithm\\output.txt");
    decode("F:\\HuffmanAlgorithm\\output.txt", "F:\\HuffmanAlgorithm\\decode.txt");
    return 0;
}

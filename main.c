#include "headers/compression.h"

int main(void) {
    encode("D:\\C\\HuffmanAlgorithm\\input.txt", "D:\\C\\HuffmanAlgorithm\\output.txt");
    decode("D:\\C\\HuffmanAlgorithm\\output.txt", "D:\\C\\HuffmanAlgorithm\\decode.txt");
    return 0;
}

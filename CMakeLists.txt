cmake_minimum_required(VERSION 3.29)
project(HuffmanAlgorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(HuffmanAlgorithm main.c
        src/huffman.c headers/huffman.h
        src/list.c headers/list.h
        src/utils.c headers/utils.h
        src/encode.c src/decode.c headers/compression.h
        tests/test.c
        tests/data/test.h
)

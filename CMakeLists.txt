cmake_minimum_required(VERSION 3.29)
project(HuffmanAlgorithm C)

set(CMAKE_C_STANDARD 11)

add_executable(HuffmanAlgorithm
src/huffman.c headers/huffman.h
        src/utils.c headers/utils.h)

#ifndef HUFFMAN_H
#define HUFFMAN_H

#define CODE_SIZE 256

typedef struct node {
    unsigned char symbol;
    unsigned char is_symbol;
    unsigned int freq;
    unsigned char code[CODE_SIZE];
    int level;
    struct node * left, *right, *next;
} NODE;

#endif //HUFFMAN_H

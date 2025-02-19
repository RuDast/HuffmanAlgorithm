#ifndef HUFFMAN_H
#define HUFFMAN_H

#define CODE_SIZE 256

typedef struct node {
    unsigned char symbol;
    // unsigned char is_symbol;
    unsigned int freq;
    // unsigned char code[CODE_SIZE];
    // int level;
    struct node * left, *right, *next;
} Node;

Node * MakeNodeFromNode(const Node * left, const Node * right);
Node * MakeTreeFromList(Node * head);

#endif //HUFFMAN_H

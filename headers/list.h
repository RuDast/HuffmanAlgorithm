#ifndef LIST_H
#define LIST_H

#include "huffman.h"

typedef struct ListNode_t{
    HuffmanNode* node;
    struct ListNode_t* next;
} Node;

Node* insertToList(Node* head, HuffmanNode* huff_node);
HuffmanNode* popToList(Node** head);

#endif // LIST_H

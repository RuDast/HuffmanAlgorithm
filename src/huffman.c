#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/huffman.h"
#include "../headers/list.h"

HuffmanNode* createHuffmanNode(unsigned char ch, int freq) {
    HuffmanNode* node = malloc(sizeof(HuffmanNode));
    if (!node) {
        return NULL;
    }
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

HuffmanNode* mergeNodes(HuffmanNode* left, HuffmanNode* right) {
    HuffmanNode* parent = createHuffmanNode(0, left->freq + right->freq);
    parent->left = left;
    parent->right = right;
    return parent;
}

HuffmanNode* generateTree(int freq[]) {
    Node* list = NULL;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            HuffmanNode* node = createHuffmanNode(i, freq[i]);
            list = insertToList(list, node);
        }
    }
    if (!list) return NULL;


    if (!list->next) {
        HuffmanNode* only = list->node;
        free(list);
        return only;
    }

    while (list && list->next) {
        HuffmanNode* left = popToList(&list);
        HuffmanNode* right = popToList(&list);
        HuffmanNode* parent = mergeNodes(left, right);
        list = insertToList(list, parent);
    }
    HuffmanNode* root = popToList(&list);
    return root;
}

void generateCodes(HuffmanNode* root, char code[], int depth, char codes[256][256]) {
    if (!root->left && !root->right) {
        code[depth] = '\0';
        strcpy(codes[root->ch], code);
        return;
    }
    if (root->left) {
        code[depth] = '0';
        generateCodes(root->left, code, depth + 1, codes);
    }
    if (root->right) {
        code[depth] = '1';
        generateCodes(root->right, code, depth + 1, codes);
    }
}

void deleteTree(HuffmanNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

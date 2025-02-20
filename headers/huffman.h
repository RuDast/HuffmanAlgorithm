#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct HuffmanNode {
    unsigned char ch;
    int freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

HuffmanNode* createHuffmanNode(unsigned char ch, int freq);
HuffmanNode* mergeNodes(HuffmanNode* left, HuffmanNode* right);
HuffmanNode* generateTree(int freq[]);
void generateCodes(HuffmanNode* root, char code[], int depth, char codes[256][256]);
void deleteTree(HuffmanNode* root);

#endif // HUFFMAN_H

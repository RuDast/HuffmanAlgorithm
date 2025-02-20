#include <stdlib.h>
#include "../headers/huffman.h"
#include "../headers/list.h"

Node* createNode(HuffmanNode* node) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node)
        return NULL;
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

Node* insertToList(Node* head, HuffmanNode* huff_node) {
    Node* new_node = createNode(huff_node);
    if (head == NULL || huff_node->freq < head->node->freq) {
        new_node->next = head;
        return new_node;
    }
    Node* current = head;
    while (current->next && current->next->node->freq <= huff_node->freq)
        current = current->next;
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

HuffmanNode* popToList(Node** head) {
    if (!head || !(*head))
        return NULL;
    Node* temp = *head;
    HuffmanNode* huff_node = temp->node;
    *head = temp->next;
    free(temp);
    return huff_node;
}

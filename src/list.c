#include "../headers/huffman.h"

Node* InsertNode(Node* head, Node* newNode) {
    if (!head || newNode->freq < head->freq) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next && current->next->freq <= newNode->freq) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

#include <stdlib.h>

#include "../headers/huffman.h"
#include "../headers/utils.h"

Node * MakeNodeFromNode(const Node * left, const Node * right) {
    Node * res = malloc(sizeof(Node));
    res->freq = left->freq + right->freq;
    res->is_symbol = 0;
    res->symbol = 0;
    res->left = left;
    res->right = right;
    res->next = 0;
    return res;
}

Node * MakeTreeFromList(Node * head) {
    while (head && head->next)
    {
        const Node * left = head;
        const Node * right = head->next;
        // TODO add2list(&(head->next->next), MakeNodeFromNode(left, right));
        head = head->next->next;
    }
    return head;
}

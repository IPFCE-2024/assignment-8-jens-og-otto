#include "insertion_sort.h"
#include <stdio.h>
#include <stdlib.h>

node* sorted_insert(node* sorted, node* new_node) {
    if (sorted == NULL || sorted->data >= new_node->data) {
        new_node->next = sorted;
        return new_node;
    }

    node* current = sorted;
    while (current->next != NULL && current->next->data < new_node->data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return sorted;
}

node* isort(node* list) {
    if (list == NULL || list->next == NULL) {
        return list; 
    }

    node* sorted = NULL;  
    node* current = list; 

    while (current != NULL) {
        node* next = current->next;
        sorted = sorted_insert(sorted, current); 
        current = next; 
    }

    return sorted; 
}

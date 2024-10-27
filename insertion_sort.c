#include "insertion_sort.h"
#include <stdio.h>
#include <stdlib.h>

node* sorted_insert(node* sorted, node* new_node) 
{
    // hvis sorted er NULL eller sorted som peger på data ikke er ligmed eller større end new_node som peger på data
    // så er new_node der peger på next ligmed sorted
    if (sorted == NULL || sorted->data >= new_node->data) 
    {
        new_node->next = sorted;
        return new_node;
    }
    // ellers så laves en ny node current som sættes til at være ligmed sorted herefter oprettes der en whileløkke 
    // hvori så længe current som peger på next ikke er NULL og current der peger på data der peger på next
    // er mindre end new_node der peger på data så skal current ved ligmed current der peger på next
    node* current = sorted;
    while (current->next != NULL && current->next->data < new_node->data) 
    {
        current = current->next;
    }
    // new_node der peger på next skal være ligmed current der peger på next og current der peger på next skal være ligmed new_node
    new_node->next = current->next;
    current->next = new_node;

    return sorted;
}

node* isort(node* list) 
{
    // hvis vores list er tom returneres list da vi ikke skal sortere noget så
    if (list == NULL || list->next == NULL) 
    {
        return list; 
    }
    // ellers så laves to nodes sorted=NULL og current=list som køres igennem en whileløkke
    // hvori så længe current ikke er NULL så skal next være ligmed current der peger på next 
    // og sorted skal være ligmed sorted_insert som er den void funktionen fra tidligere 
    // herefter skal current være ligmed next
    node* sorted = NULL;  
    node* current = list; 

    while (current != NULL) {
        node* next = current->next;
        sorted = sorted_insert(sorted, current); 
        current = next; 
    }

    return sorted; 
}

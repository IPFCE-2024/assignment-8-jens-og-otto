#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


// Opgave 3
void initialize(queue *q) {
    // køen initialiseres til at starte med at være tom
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

bool empty(const queue *q) {
    // dobbelttjekker at køen er tom
    return q->size  == 0;
}

bool full(const queue *q) {
    // køen kan aldrig være fuld så længde der er plads i hukommelsen
    return false;
}

void enqueue(queue *q, int x) {
    // allocerer plads i hukommelsen med malloc til new_node
    node* new_node = (node*)malloc(sizeof(node));
   new_node->data = x;
   new_node->next = NULL;
    // hvis køens sidste element er NULL altså hvis køen er tom 
    // så skal både køens første element og sidste element være new_node så vi har et enkelt elemnt i vores kø
   if (q->rear == NULL)
    {
     q->front = new_node;
     q->rear = new_node;
    }
    // hvis så køen IKKE er tom så skal køens sidste element være det næst tilføjede element
    // altså et nyt element new_node og køens størrelse vokser
    else
    {
    q->rear->next = new_node;
    q->rear = new_node;
    }
    q->size++;
}

int dequeue(queue *q) {
    // hvis køen er tom stopper programmet da vi ikke kan tage et element fra en tom kø
    if (empty(q))
    {
        return -1;
    }
    // hvis køen så ikke er tom fjernes et element fra køen
    node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    // hvis køen så er tom nu efter vi har fjernet et element så frigøres der plads i hukommelsen
    // ved at fjerne vores midlertidige element temp
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return data;
}

// Opgave 4
void push(int element, node **head) {
    // laver plads i hukommelsen til en ny node som er en pointer til toppen af vores stack
    node *newNode = (node*)malloc(sizeof(node));
    newNode->next = *head;
    *head = newNode;
}

int pop(node **head) {
    // vi forsøger at poppe et element fra vores stack og hvis toppen af stacken så er tom printes det ud
    if (*head == NULL)
    {
        printf("Stack er tom\n");
        return -1;
    }
    // hvis stackens øverste element ikker NULL så poppes det øverste element
    int data = (*head)->data;
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
}

void enqueueStack(queue *q, int x) {
    // vi skubber et element oven på stacken ved brug af vores kø funktion
    push(x, &(q->front));
}

int dequeueStack(queue *q) {
    // vi laver en midlertidig stack med et midlertidigt top element som skal være tomt
    stack temp;
    temp.head = NULL;
    // hvis vores kø er tom så kan vi ikke skubbe elementer fra vores kø oven på vores stack 
    // derfor printes der ud af stacken er tom
    if (q->front == NULL)
    {
        printf("Stack er tom\n");
        return -1;
    }
    // hvis der er mindst et element i vores kø så skubbes det oven på vores stack
    while (q->front != NULL)
    {
        int element = pop(&(q->front));
        push(element, &(temp.head));
    }
    int result = pop(&(temp.head));
    // mens vores midlertidige stack så ikke er tom så vil vi poppe de øverste element fra stacken
    //  ved at skubbe det ud med vores kø funktion
    while (temp.head != NULL)
    {
        push(pop(&(temp.head)), &(q->front));
    }
    return result;
}
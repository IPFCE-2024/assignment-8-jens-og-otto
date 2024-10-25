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
    node* new_node = (node*)malloc(sizeof(node));
   new_node->data = x;
   new_node->next = NULL;

   if (q->rear == NULL)
    {
     q->front = new_node;
     q->rear = new_node;
    }
    else
    {
    q->rear->next = new_node;
    q->rear = new_node;
    }
    q->size++;
}

int dequeue(queue *q) {
    if (empty(q))
    {
        return -1;
    }
        node* temp = q->front;
        int data = temp->data;
        q->front = q->front->next;

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
    node *newNode = (node*)malloc(sizeof(node));
    newNode->next = *head;
    *head = newNode;
}

int pop(node **head) {
    if (*head == NULL)
    {
        printf("Stack er tom\n");
        return -1;
    }
    int data = (*head)->data;
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
}

void enqueueStack(queue *q, int x) {
    push(x, &(q->front));
}

int dequeueStack(queue *q) {
    stack temp;
    temp.head = NULL;
    
    if (q->front == NULL)
    {
        printf("Stack er tom\n");
        return -1;
    }
    
    while (q->front != NULL)
    {
        int element = pop(&(q->front));
        push(element, &(temp.head));
    }
    int result = pop(&(temp.head));

    while (temp.head != NULL)
    {
        push(pop(&(temp.head)), &(q->front));
    }
    return result;

    int main(); {
    queue q; 
    q.front = NULL; 

    enqueueStack(&q, 1);
    enqueueStack(&q, 2);
    enqueueStack(&q, 3);

    printf("Dequeued: %d\n", dequeueStack(&q)); 
    printf("Dequeued: %d\n", dequeueStack(&q)); 

    enqueueStack(&q, 4);

    printf("Dequeued: %d\n", dequeueStack(&q)); 
    printf("Dequeued: %d\n", dequeueStack(&q)); 
    printf("Dequeued: %d\n", dequeueStack(&q)); 

    return 0;
    }
}
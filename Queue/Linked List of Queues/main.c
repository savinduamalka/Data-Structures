#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

typedef struct ListNode {
    Queue* queue;
    struct ListNode* next;
} ListNode;

QueueNode* createQueueNode(int data) {

    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    
    return q;
}

int main(){

  printf("Linked List of Queues\n");

  return 0;
}

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

int main(){

  printf("Linked List of Queues\n");

  return 0;
}

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

int main(){

  printf("Linked List of Queues\n");

  return 0;
}

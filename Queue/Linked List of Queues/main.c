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

int isQueueEmpty(Queue* q) {

    return q->front == NULL;
}

void enqueue(Queue* q, int data) {

    QueueNode* newNode = createQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return data;
}

void displayQueue(Queue* q) {
    
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    QueueNode* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

ListNode* createListNode(Queue* q) {
    
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->queue = q;
    newNode->next = NULL;
    return newNode;
}

void addQueueToList(ListNode** head, Queue* q) {
    
    ListNode* newNode = createListNode(q);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayListOfQueues(ListNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    ListNode* temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("Queue %d: ", i++);
        displayQueue(temp->queue);
        temp = temp->next;
    }
}

void freeQueue(Queue* q) {
    
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

void freeListOfQueues(ListNode* head) {
    
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        freeQueue(temp->queue);
        free(temp);
    }
}

int size(Queue* q) {
    
    int count = 0;
    QueueNode* temp = q->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


int main(){
    
    ListNode* head = NULL;

    Queue* q1 = createQueue();
    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    addQueueToList(&head, q1);

    Queue* q2 = createQueue();
    enqueue(q2, 40);
    enqueue(q2, 50);
    enqueue(q2, 60);
    addQueueToList(&head, q2);

    Queue* q3 = createQueue();
    enqueue(q3, 60);
    enqueue(q3, 70);
    enqueue(q3, 80);
    enqueue(q3, 90);
    addQueueToList(&head, q3);

    printf("Linked List of Queues:\n");
    displayListOfQueues(head);

    printf("\nDequeuing from first queue: %d\n", dequeue(q1));
    printf("Dequeuing from second queue: %d\n", dequeue(q2));

    printf("\nAfter dequeuing:\n");
    displayListOfQueues(head);

    freeListOfQueues(head);

  return 0;
}

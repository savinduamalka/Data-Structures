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

// Add this function to count the number of queues in the list
int listSize(ListNode* head) {
    int count = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int peek(Queue* q) {
    
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}


int main() {
    ListNode* head = NULL;
    int choice, queue_num, data;
    Queue* selected_queue = NULL;
    ListNode* temp = NULL;

    while (1) {
        printf("\n--- Linked List of Queues Menu ---\n");
        printf("1. Add new queue\n");
        printf("2. Enqueue to a queue\n");
        printf("3. Dequeue from a queue\n");
        printf("4. Peek front of a queue\n");
        printf("5. Display a queue\n");
        printf("6. Display all queues\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    Queue* q = createQueue();
                    addQueueToList(&head, q);
                    printf("New queue added as Queue %d.\n", listSize(head));
                }
                break;
            case 2:
                printf("Enter queue number to enqueue to: ");
                scanf("%d", &queue_num);
                temp = head;
                for (int i = 1; temp != NULL && i < queue_num; i++)
                    temp = temp->next;
                if (temp == NULL) {
                    printf("Invalid queue number.\n");
                    break;
                }
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(temp->queue, data);
                printf("Enqueued %d to Queue %d.\n", data, queue_num);
                break;
            case 3:
                printf("Enter queue number to dequeue from: ");
                scanf("%d", &queue_num);
                temp = head;
                for (int i = 1; temp != NULL && i < queue_num; i++)
                    temp = temp->next;
                if (temp == NULL) {
                    printf("Invalid queue number.\n");
                    break;
                }
                data = dequeue(temp->queue);
                if (data != -1)
                    printf("Dequeued %d from Queue %d.\n", data, queue_num);
                break;
            case 4:
                printf("Enter queue number to peek: ");
                scanf("%d", &queue_num);
                temp = head;
                for (int i = 1; temp != NULL && i < queue_num; i++)
                    temp = temp->next;
                if (temp == NULL) {
                    printf("Invalid queue number.\n");
                    break;
                }
                data = peek(temp->queue);
                if (data != -1)
                    printf("Front of Queue %d: %d\n", queue_num, data);
                break;
            case 5:
                printf("Enter queue number to display: ");
                scanf("%d", &queue_num);
                temp = head;
                for (int i = 1; temp != NULL && i < queue_num; i++)
                    temp = temp->next;
                if (temp == NULL) {
                    printf("Invalid queue number.\n");
                    break;
                }
                printf("Queue %d: ", queue_num);
                displayQueue(temp->queue);
                break;
            case 6:
                printf("All queues:\n");
                displayListOfQueues(head);
                break;
            case 7:
                freeListOfQueues(head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

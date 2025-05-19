#include <stdio.h>
#include <stdbool.h> 
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;


bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == SIZE - 1;
}

void search(int value) {

    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            if (queue[i] == value) {
                printf("Value %d found at position %d\n", value, i - front + 1);
                return;
            }
        }
        printf("Value %d not found in the queue\n", value);
    }
}

int size() {
    if (isEmpty())
        return 0;
    return rear - front + 1;
}

void enqueue(int value) {

  if (isFull())
      printf("Queue is full (Overflow)\n");
  else {
      if (isEmpty()) front = 0; 
      rear++;
      queue[rear] = value;
      printf("Inserted %d\n", value);
  }

}

void dequeue() {

  if (isEmpty()) { 
      printf("Queue is empty (Underflow)\n");
  } else {
      printf("Removed %d\n", queue[front]);
      front++;
      if (front > rear) {
          front = -1;
          rear = -1;
      }
  }
}

void peek() {

  if (isEmpty()) { 
      printf("Queue is empty\n");
  } else {
      printf("Front element is: %d\n", queue[front]);

  }
}

void display() {

  if (isEmpty()) {
      printf("Queue is empty\n");
  } else {
      printf("Queue elements are: ");
      for (int i = front; i <= rear; i++) {
          printf("%d ", queue[i]);
      }
      printf("\n");
  }

}


void rearElement() {
    
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Rear element is: %d\n", queue[rear]);
    }
}

int main() {
    int choice, value;

    printf("Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Is Empty\n");
    printf("6. Is Full\n");
    printf("7. Size\n");
    printf("8. Rear\n");
    printf("9. Search\n");
    printf("10. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 6:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;

            case 7:
                printf("Current queue size: %d\n", size());
                break;

            case 8:
                rearElement();
                break;

            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 10:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

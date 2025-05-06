#include <stdio.h>
#include <stdbool.h> 
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;


bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {

  if (rear == SIZE - 1)
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


int main() {
    int choice, value;

    printf("Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");

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
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

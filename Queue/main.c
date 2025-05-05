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


int main(){

  printf("Hello DSA Queue....\n");

  if (isEmpty()) {
      printf("Queue is initially empty.\n");
  }

  enqueue(10);
  enqueue(20);
  enqueue(30);

  display();

  peek();

  dequeue();
  peek();
  display();

  dequeue();
  dequeue();

  if (isEmpty()) {
      printf("Queue became empty after dequeues.\n");
  }

  dequeue(); 
  peek();

  display();

  return 0;
}

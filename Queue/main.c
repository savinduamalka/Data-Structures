#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {

  if (rear == SIZE - 1)
      printf("Queue is full (Overflow)\n");
  else {
      if (front == -1) front = 0; 
      rear++;
      queue[rear] = value;
      printf("Inserted %d\n", value);
  }

}

void dequeue() {

  if (front == -1 || front > rear) {
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
  if (front == -1 || front > rear) {
      printf("Queue is empty\n");
  } else {
      printf("Front element is: %d\n", queue[front]);

  }
}

void display() {
  if (front == -1 || front > rear) {
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
  dequeue();
  peek();

  display();
  
  return 0;
}

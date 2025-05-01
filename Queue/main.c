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

int main(){

  printf("Hello DSA Queue....\n");
  return 0;
}

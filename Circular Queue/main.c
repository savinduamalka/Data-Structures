#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
  if((rear+1)%SIZE==front){
    printf("Queue is full (Overflow)\n");
    return;
  }

  if(front==-1){
    front=0;
  }

  rear=(rear+1)%SIZE;
  queue[rear]=value;
  printf("Inserted %d\n",value);
}

void dequeue(){
  if(front==-1){
    printf("Queue is empty (Underflow)\n");
    return;
  }

  printf("Removed %d\n",queue[front]);

  if(front==rear){
    front=-1;
    rear=-1;
  }else{
    front=(front+1)%SIZE;
  }
}

void printQueue(){
  if(front==-1){
    printf("Queue is empty\n");
    return;
  }

  int i=front;

  while(1){
    printf("%d ",queue[i]);
    if(i==rear) break;
    i=(i+1)%SIZE;
  }
  printf("\n");
}
int main() {
  int choice, value;
  while (1) {
    printf("\nCircular Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        enqueue(value);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        printQueue();
        break;
      case 4:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice. Try again.\n");
    }
  }
}

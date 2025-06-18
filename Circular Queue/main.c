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
int main(){

  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  printQueue();
  dequeue();
  printQueue();
  enqueue(6);
  printQueue();
  return 0;
}

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

int main(){

  return 0;
}

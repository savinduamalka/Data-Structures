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

int main(){

  return 0;
}

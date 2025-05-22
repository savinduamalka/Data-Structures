#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void print(){
  struct Node* temp=top;
  if(!temp){
    printf("Stack is underflow\n");
    return;   
  }

  while(temp){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

int main(){
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  print();

  return 0;
}

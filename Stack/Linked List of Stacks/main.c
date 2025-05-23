#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", data);
}

void print(){
  struct Node* temp=top;
  if(isEmpty()){
    printf("Stack is underflow\n");
    return;   
  }

  while(temp){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void pop(){

  if(isEmpty()){
    printf("Stack is underflow\n");
    return;
  }

  int poppedValue;
  struct Node* temp=top;
  poppedValue=temp->data;
  top=temp->next;
  free(temp);
  printf("Popped %d\n", poppedValue);
}

int main(){
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  print();
  pop();

  print();

  return 0;
}

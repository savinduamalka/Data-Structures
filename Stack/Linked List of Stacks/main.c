#include <stdlib.h>

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

int main(){
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  
  return 0;
}

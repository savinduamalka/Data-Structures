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
  return 0;
}

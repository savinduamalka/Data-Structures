#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
  struct Node *prev;
};

struct Node* head = NULL;

struct Node* createNode(int data){
  struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));

  if(!newNode){
    printf("Memory allocation failed...\n");
    return NULL;
  }

  newNode->data=data;
  newNode->prev=NULL;
  newNode->next= NULL;

  return newNode;
}

int main(){
  return 0;
}

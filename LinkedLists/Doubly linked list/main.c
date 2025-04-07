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

void insertAtBeggining(int data){
  struct Node* newNode= createNode(data);

  if(!newNode){
    printf("Failed...");
    return;
  }

  newNode->next=head;
  head->prev=newNode;

  head=newNode;

}

int main(){
  insertAtBeggining(1001);
  insertAtBeggining(1000);
  return 0;
}

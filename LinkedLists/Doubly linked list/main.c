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

  if(head == NULL){
    head = newNode;
    return;
  }

  newNode->next=head;
  head->prev=newNode;
  head=newNode;
}

void printDoublyLinkedList(){
  if(!head){
    printf("Doubly linked list is empty...\n");
    return;
  }

  struct Node* temp= head;

  while(temp!=NULL){
    printf("%d -> ",temp->data);
    temp= temp->next;
  }

  printf("NULL\n");
}

void freeList(){
  struct Node* temp;

  while(head!=NULL){
    temp= head;
    head=head->next;
    if(head!=NULL){
      head->prev = NULL;
    }
    free(temp);
  }
}

void insertAtPosition(int data, int pos){
  if(!head){
    printf("Can not insert. This list is empty...");
    return;
  }

  struct Node* newNode= createNode(data);

  if(pos==1){
    newNode->next=head;
    head->prev=newNode;
    head= newNode;
  }
  
  struct Node* temp= head;
  int i=1;

  while(temp!=NULL && i<pos-1){
    temp=temp->next;
    i++;
  }
  
  newNode->next=temp->next;
  newNode->prev=temp;
  temp->next=newNode;
}

int main(){
  insertAtBeggining(1001);
  insertAtBeggining(1000);
  insertAtBeggining(1004);
  insertAtBeggining(1005);

  

  printDoublyLinkedList();

  insertAtPosition(100,3);

  printDoublyLinkedList();

  freeList(head);

  return 0;
}

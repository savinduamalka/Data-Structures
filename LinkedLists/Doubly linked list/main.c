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
    printf("Can not insert. This list is empty...\n");
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

void insertAtEnd(int data){

  struct Node* newNode = createNode(data);

  if(!head){
    head = newNode;
    return;
  }

  struct Node* current = head;

  while(current->next!=NULL){
    current= current->next;
  }

current->next = newNode;
newNode->prev = current;
newNode->next= NULL;
  
}

void deleteAtBeginning(){
  if(!head){
    printf("Nothing to be deleted...\n");
    return;
  }

  struct Node* temp= head;

  head= head->next;
  
  if(head!=NULL){
    head->prev = NULL;
  }


  free(temp);
}

void deleteAtPosition(int pos){
  if(!head){
    printf("Nothing to be deleted...\n");
    return;
  }

  struct Node* temp= head;

  if(pos==1){
    head= head->next;
    if(head!=NULL){
      head->prev = NULL;
    }
    free(temp);
    return;
  }

  int i=1;
  while(temp!=NULL && i<pos){
    temp= temp->next;
    i++;
  }

  if(temp==NULL){
    printf("Position not found...\n");
    return;
  }

  temp->prev->next = temp->next;
  if(temp->next!=NULL){
    temp->next->prev = temp->prev;
  }
  free(temp);
}

void deleteAtEnd(){
  if(!head){
    printf("Nothing to be deleted...\n");
    return;
  }

  struct Node* temp= head;

  if(head->next == NULL){
    head = NULL;
    free(temp);
    return;
  }

  while(temp->next!=NULL){
    temp=temp->next;
  }

  temp->prev->next = NULL;
  free(temp);
}

void reverseDoublyLinkedList() {
  if (!head) {
      printf("Doubly linked list is empty...\n");
      return;
  }

  struct Node* current = head;
  struct Node* temp = NULL;

  while (current != NULL) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev; 
  }

  if (temp != NULL) {
      head = temp->prev;
  }
}

int main(){
  insertAtBeggining(1001);
  // insertAtBeggining(1000);
  // insertAtBeggining(1004);
  // insertAtBeggining(1005);

  

  printDoublyLinkedList();

  //insertAtPosition(100,3);

  printDoublyLinkedList();

  //insertAtEnd(759);

  printDoublyLinkedList();

  deleteAtBeginning();

  printDoublyLinkedList();

  deleteAtPosition(1);
  printDoublyLinkedList();

  deleteAtEnd();

  printDoublyLinkedList();

  reverseDoublyLinkedList();
  printDoublyLinkedList();

  freeList(head);

  return 0;
}

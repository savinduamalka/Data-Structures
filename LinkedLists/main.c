#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node* createNode(int data){
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

	if(!newNode){ // check whether there is an error in memory allocation
		printf("Memory Error\n");
		return NULL;
	}

	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

void PrintSinglyLinkedList(struct Node *head) {
	struct Node *temp = head;
	printf("Linked List: ");
	
	while (temp != NULL) {
			printf("%d -> ", temp->data);
			temp = temp->next;
	}
	
	printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node *head, int data){
	struct Node *newNode = createNode(data);

	if (!newNode) {
			return head; 
	}

	newNode->next = head;
	return newNode;
}

struct Node* insertAtEnd(struct Node *head, int data){
	struct Node *newNode = createNode(data);

	if (!newNode) {
			return head; 
	}

	if (head == NULL) { // Handle empty list situation
		return newNode;
}

	struct Node *temp = head;
	while (temp->next != NULL) {
			temp = temp->next;
	}

	temp->next = newNode;
	return head;
}

void freeList(struct Node *head) {
	struct Node *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

struct Node* insertAtPosition(struct Node *head, int data, int position){
	struct Node *newNode = createNode(data);

	if (!newNode) {
		return head; 
	}

	if (position == 1) {
		newNode->next = head;
		return newNode;
	}

	struct Node *temp = head;
	for (int i = 1; i < position - 1 && temp != NULL; i++) {
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Position out of range\n");
		free(newNode);
		return head;
	}

	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}

int main(){
	printf("Insert a value for head node: ");
	int data;
	scanf("%d", &data);
	struct Node *head = createNode(data);

	if (!head) {
		return 1;
	}

	PrintSinglyLinkedList(head);

	printf("Insert a value for new node: ");
	scanf("%d", &data);
	head = insertAtBeginning(head, data);

	PrintSinglyLinkedList(head);

	printf("Insert a value for new node at end: ");
	scanf("%d", &data);

	head = insertAtEnd(head, data);
	PrintSinglyLinkedList(head);

	printf("Insert a value for new node at a specific position: ");
	scanf("%d", &data);
	int position;
	printf("Enter the position: ");
	scanf("%d", &position);

	head = insertAtPosition(head, data, position);
	PrintSinglyLinkedList(head);
	
	freeList(head);
	return 0;
}

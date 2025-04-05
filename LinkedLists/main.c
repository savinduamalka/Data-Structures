#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node* createNode(int data){
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

	if(!newNode){ 
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


struct Node* deleteFirstNode(struct Node *head) {
	if (head == NULL) {
		return NULL; 
	}

	struct Node *temp = head;
	head = head->next; 
	free(temp); 
	return head;
}	

struct Node* deleteLastNode(struct Node *head) {
	if (head == NULL) {
		return NULL; 
	}

	if (head->next == NULL) { 
		free(head);
		return NULL;
	}

	struct Node *temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	free(temp->next); 
	temp->next = NULL; 
	return head;
}

void countOfNode(struct Node *head){
	int count=0;

	if(!head){
		printf("The list is empty\n");
		return;
	}

	struct Node *temp=head;

	while(temp!=NULL){
		count++;
		temp=temp->next;
	}

	printf("Count is %d\n",count);
}

void printDataOnly(struct Node* head){
	if(!head){
		printf("List is empty\n");
		return;
	}
	struct Node* temp= head;

	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

// Insert at beginning with pass by reference
void insertAtBegingPassByRef(struct Node** head, int data){
	struct Node* newNode = createNode(data);

	if (!newNode) { 
		return; 
 }

	newNode->next=*head;

	*head= newNode;
}

// Reverse the linked list
struct Node* reverseList(struct Node *head) {
	struct Node *prev = NULL, *current = head, *next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

struct Node* deleteAtPosition(struct Node *head, int position) {
	if (head == NULL || position < 1) {
		printf("Invalid position or empty list\n");
		return head;
	}

	if (position == 1) {
		struct Node *temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	struct Node *temp = head;
	for (int i = 1; i < position - 1 && temp != NULL; i++) {
		temp = temp->next;
	}

	if (temp == NULL || temp->next == NULL) {
		printf("Position out of range\n");
		return head;
	}

	struct Node *nodeToDelete = temp->next;
	temp->next = nodeToDelete->next;
	free(nodeToDelete);

	return head;
}

struct Node* deleteLinkedList(struct Node* head){
	if(!head){
		printf("No linked list here\n");
		return NULL;
	}

	struct Node* temp= head;
	while(temp!=NULL){
		temp=temp->next;
		free(head);
		head=temp;
	}
	return NULL;
}

int searchNode(struct Node* head, int key) {
    struct Node* current = head;  
    int index = 1;

    while (current != NULL) {
        if (current->data == key)
            return index;  
        current = current->next;
        index++;
    }
    return -1;     
}


int main(){
	printf("Insert a value for head node: ");
	int data;
	if (scanf("%d", &data) != 1) {
		printf("Invalid input. Exiting...\n");
		return 1;
	}

	struct Node *head = createNode(data);
	if (!head) {
		return 1;
	}

	PrintSinglyLinkedList(head);

	printf("Insert a value for new node: ");
	if (scanf("%d", &data) != 1) {
		printf("Invalid input. Exiting...\n");
		freeList(head);
		return 1;
	}
	head = insertAtBeginning(head, data);
	PrintSinglyLinkedList(head);

	printf("Insert a value for new node at end: ");
	if (scanf("%d", &data) != 1) {
		printf("Invalid input. Exiting...\n");
		freeList(head);
		return 1;
	}
	head = insertAtEnd(head, data);
	PrintSinglyLinkedList(head);

	printf("Insert a value for new node at a specific position: ");
	if (scanf("%d", &data) != 1) {
		printf("Invalid input. Exiting...\n");
		freeList(head);
		return 1;
	}
	int position;
	printf("Enter the position: ");
	if (scanf("%d", &position) != 1 || position < 1) {
		printf("Invalid position. Exiting...\n");
		freeList(head);
		return 1;
	}
	head = insertAtPosition(head, data, position);
	PrintSinglyLinkedList(head);

	printf("Deleting the first node...\n");
	head = deleteFirstNode(head);
	PrintSinglyLinkedList(head);

	printf("Deleting the last node...\n");
	head = deleteLastNode(head);
	PrintSinglyLinkedList(head);

	countOfNode(head);

	printDataOnly(head);

	printf("Reversing the linked list...\n");
	head = reverseList(head);
	PrintSinglyLinkedList(head);

	printf("Delete a node at a specific position\n");
	printf("Enter the position: ");
	if (scanf("%d", &position) != 1 || position < 1) {
		printf("Invalid position. Exiting...\n");
		freeList(head);
		return 1;
	}
	head = deleteAtPosition(head, position);
	PrintSinglyLinkedList(head);

    int key;
    printf("Enter the value to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input. Exiting...\n");
        freeList(head);
        return 1;
    }
    int searchResult = searchNode(head, key);
    if (searchResult != -1)
        printf("%d found at index %d\n", key, searchResult);
    else
        printf("%d not found in the list\n", key);


	head =deleteLinkedList(head);

	if(head==NULL){
		printf("Lined List deleted successfully");
	}
	
	freeList(head);
	return 0;
}

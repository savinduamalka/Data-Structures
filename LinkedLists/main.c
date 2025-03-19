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

int main(){
	printf("Insert a value for head node: ");
	int data;
	scanf("%d", &data);
	struct Node *head = createNode(data);

	PrintSinglyLinkedList(head);

	printf("Insert a value for new node: ");
	scanf("%d", &data);
	head = insertAtBeginning(head, data);

	PrintSinglyLinkedList(head);
	
	free(head);
	return 0;
}

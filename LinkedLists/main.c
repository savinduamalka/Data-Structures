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

void displayMenu() {
    printf("\nLinked List Operations:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete First Node\n");
    printf("5. Delete Last Node\n");
    printf("6. Delete at Position\n");
    printf("7. Count Nodes\n");
    printf("8. Print Data Only\n");
    printf("9. Reverse List\n");
    printf("10. Search Node\n");
    printf("11. Print List\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node *head = NULL;
    int choice, data, position, key, searchResult;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            choice = -1; 
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the value to insert at the position: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                printf("Enter the position: ");
                if (scanf("%d", &position) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteFirstNode(head);
                break;
            case 5:
                head = deleteLastNode(head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                if (scanf("%d", &position) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                head = deleteAtPosition(head, position);
                break;
            case 7:
                countOfNode(head);
                break;
            case 8:
                printDataOnly(head);
                break;
            case 9:
                head = reverseList(head);
                break;
            case 10:
                printf("Enter the value to search: ");
                if (scanf("%d", &key) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                searchResult = searchNode(head, key);
                if (searchResult != -1)
                    printf("%d found at index %d\n", key, searchResult);
                else
                    printf("%d not found in the list\n", key);
                break;
            case 11:
                PrintSinglyLinkedList(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    head = deleteLinkedList(head);
    freeList(head);

    return 0;
}

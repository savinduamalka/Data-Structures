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

int main(){
	
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", data);
}

void print(){
  struct Node* temp=top;
  if(isEmpty()){
    printf("Stack is underflow\n");
    return;   
  }

  while(temp){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void pop(){

  if(isEmpty()){
    printf("Stack is underflow\n");
    return;
  }

  int poppedValue;
  struct Node* temp=top;
  poppedValue=temp->data;
  top=temp->next;
  free(temp);
  printf("Popped %d\n", poppedValue);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}

int main() {
    int choice, value;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    // Clear input buffer
                    int c; while ((c = getchar()) != '\n' && c != EOF);
                    break;
                }
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                print();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

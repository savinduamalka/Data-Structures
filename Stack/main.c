#include <stdio.h>
#include <stdbool.h> 
#define MAX 100


int stack[MAX];
int top = -1; 

void push(int value) {

  if (top == MAX - 1) {
      printf("Stack Overflow\n");
  } else {
      top++;
      stack[top] = value;
      printf("%d pushed to stack\n", value);
  }
}

int pop() {

  if (top == -1) {
      printf("Stack Underflow\n");
      return -1;
  } else {
      int value = stack[top];
      top--;
      return value;
  }

}

void display() {

  if (top == -1) {
      printf("Stack is empty\n");
  } else {
      printf("Stack elements are:\n");
      for (int i = top; i >= 0; i--) {
          printf("%d\n", stack[i]);
      }
  }


}

int peek() {

  if (top == -1) {
      printf("Stack is empty\n");
      return -1;
  } else {
      return stack[top];
  }
}

bool isEmpty() {
  return top == -1;

}

bool isFull() {
  return top == MAX - 1;
}

int size() {
  return top + 1;
}

int main(){
    push(10);
    push(20);
    push(30);

    display();

    printf("Top element is %d\n", peek());
    printf("Stack size: %d\n", size());

    printf("%d popped from stack\n", pop());
    
    display();

  return 0;
}

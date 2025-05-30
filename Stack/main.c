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

void clear() {
  top = -1;
  printf("Stack cleared!\n");
}

bool search(int value) {
  for (int i = top; i >= 0; i--) {
      if (stack[i] == value) {
          return true;
      }
  }
  return false;
  
}

void reverse() {
  if (top == -1) {
      printf("Stack is empty, cannot reverse\n");
      return;
  }

  int tempStack[MAX];
  int tempTop = -1;


  while (top != -1) {
      tempStack[++tempTop] = pop();
  }


  for (int i = 0; i <= tempTop; i++) {
      push(tempStack[i]);
  }

  printf("Stack reversed!\n");
}

int main(){
    push(10);
    push(20);
    push(30);

    display();

    printf("Top element is %d\n", peek());
    printf("Stack size: %d\n", size());
    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Is stack full? %s\n", isFull() ? "Yes" : "No");

    printf("%d popped from stack\n", pop());

    display();
    printf("Stack size after pop: %d\n", size());
    
    reverse();
    display();

  return 0;
}

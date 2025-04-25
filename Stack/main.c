#include <stdio.h>
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

int main(){
  printf("Stack in DSA...\n");
  push(1000);
  push(2000);
  push(3000);
  display();
  return 0;
}

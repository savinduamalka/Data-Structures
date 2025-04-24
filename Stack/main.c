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

int main(){
  printf("Stack in DSA...\n");
  push(1000);
  push(2000);
  push(3000);
  return 0;
}

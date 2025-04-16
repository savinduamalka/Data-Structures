#include <stdio.h>

void printArray(int arr[], int size){
  if (size == 0) {
    printf("Array is empty...\n");
} else {
    printf("The elements in the array are: \n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
}

int main() {
    const int MAX = 50;
    int arr[MAX];
    int size = 0, input;

    printf("This is the Data Structure of Arrays...\n");
    printf("....To exit the inserting element for array, press 0 ....\n");

    while (size < MAX) {
        printf("Enter a number for position %d: ", size + 1);
        scanf("%d", &input);

        if (input == 0) {
            break; 
        }

        arr[size] = input;
        size++;
    }

    printArray(arr, size);

    return 0;
}

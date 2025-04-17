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

void insertAtGivenPosition(int arr[], int *size, int pos, int data){
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    for(int i = *size; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = data;
    (*size)++;
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

    int pos, data;

    printf("Enter position to insert (0-based index): ");
    scanf("%d", &pos);


    printf("Enter value to insert: ");
    scanf("%d", &data);

    insertAtGivenPosition(arr, &size, pos, data);

    printf("Array after insertion:\n");
    printArray(arr, size);
    

    return 0;
}

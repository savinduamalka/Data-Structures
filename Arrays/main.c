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

void deleteAtGivenPosition(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position for deletion!\n");
        return;
    }
    
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i+1];
    }
    
    (*size)--;
    
    printf("Element at position %d deleted successfully.\n", pos);
}

void reverseArray(int arr[], int size) {
    int temp;

    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

}

void searchElement(int arr[], int size, int key) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d.\n", key, i);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}


int main() {
    const int MAX = 50;
    int arr[MAX];
    int size = 0, input;
    int choice, pos, data;

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

    do {
        printf("\nChoose an operation:\n");
        printf("1. Print Array\n");
        printf("2. Insert at Position\n");
        printf("3. Delete at Position\n");
        printf("4. Reverse Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printArray(arr, size);
                break;
            case 2:
                printf("Enter position to insert (0-based index): ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAtGivenPosition(arr, &size, pos, data);
                printf("Array after insertion:\n");
                printArray(arr, size);
                break;
            case 3:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &pos);
                deleteAtGivenPosition(arr, &size, pos);
                printf("Array after deletion:\n");
                printArray(arr, size);
                break;
            case 4:
                printf("Reversing the array...\n");
                reverseArray(arr, size);
                printf("Array after reversing:\n");
                printArray(arr, size);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 0);



    return 0;
}


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

void findMaxMin(int arr[], int size) {

    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    int max = arr[0], min = arr[0];

    for (int i = 1; i < size; i++) {

        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {

            min = arr[i];
        }
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

}


void sortArray(int arr[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array sorted successfully.\n");
    
}

void findSumAndAverage(int arr[], int size) {

    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    float average =(float) sum / size;

    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", average);
}

void rotateArray(int arr[], int size, int k) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    k = k % size; 
    int temp[k];

    // Store the first k elements in a temporary array
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // Shift the rest of the array
    for (int i = 0; i < size - k; i++) {
        arr[i] = arr[i + k];
    }

    // Place the temporary elements at the end
    for (int i = 0; i < k; i++) {
        arr[size - k + i] = temp[i];
    }

    printf("Array rotated by %d positions.\n", k);
}

int main() {
    const int MAX = 50;
    int arr[MAX];
    int size = 0, input;
    int choice, pos, data, key;

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
        printf("5. Search Element\n");
        printf("6. Find Maximum and Minimum\n");
        printf("7. Sort Array\n"); 
        printf("8. Find Sum and Average\n");
        printf("9. Rotate Array\n");
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
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchElement(arr, size, key);
                break;
            case 6:
                findMaxMin(arr, size);
                break;
            case 7:
                sortArray(arr, size);
                printf("Array after sorting:\n");
                printArray(arr, size);
                break;
            case 8:
                findSumAndAverage(arr, size);
                break;
            case 9:
                printf("Enter number of positions to rotate: ");
                scanf("%d", &pos);
                rotateArray(arr, size, pos);
                printf("Array after rotation:\n");
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


#include <stdio.h>
#include <stdlib.h>

void array_input(int arr[], int n){
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}

void array_print(int arr[], int n){
    if(n == 0){
        printf("Array is empty.\n");
        return;
    }

    printf("The array is:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void array_insert(int arr[], int *n, int capacity){
    int pos, val;

    if(*n == capacity){
        printf("Array Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("Enter position to insert (1 to %d):\n", *n + 1);
    scanf("%d", &pos);

    if(pos < 1 || pos > *n + 1){
        printf("Invalid Position!\n");
        return;
    }

    printf("Enter value to insert:\n");
    scanf("%d", &val);

    pos--;

    for(int i = *n; i > pos; i--){
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    (*n)++;
}

void array_delete(int arr[], int *n){
    int pos;

    if(*n == 0){
        printf("Array Underflow! Cannot delete.\n");
        return;
    }

    printf("Enter position to delete (1 to %d):\n", *n);
    scanf("%d", &pos);

    if(pos < 1 || pos > *n){
        printf("Invalid Position!\n");
        return;
    }

    pos--;

    for(int i = pos; i < *n - 1; i++){
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

int main(){
    int *arr;
    int n, capacity;

    printf("Enter maximum capacity of array:\n");
    scanf("%d", &capacity);

    if(capacity <= 0){
        printf("Invalid capacity!\n");
        return 0;
    }

    arr = (int*) malloc(capacity * sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("Enter number of elements in array:\n");
    scanf("%d", &n);

    if(n < 0 || n > capacity){
        printf("Invalid size!\n");
        free(arr);
        return 0;
    }

    array_input(arr, n);

    int choice;

    do{
        printf("\n----- MENU -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                array_insert(arr, &n, capacity);
                break;

            case 2:
                array_delete(arr, &n);
                break;

            case 3:
                array_print(arr, n);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    free(arr); 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define max 5

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

void array_insert(int arr[], int *n){
    int pos, val;

    if(*n == max){
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
    int arr[max];
    int n;

    printf("Enter number of elements in array (max %d):\n", max);
    scanf("%d", &n);

    if(n < 0 || n > max){
        printf("Invalid size!\n");
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
                array_insert(arr, &n);
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

    return 0;
}
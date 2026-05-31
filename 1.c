#include <stdio.h>

void array_input(int arr[],int n){
    printf("Enter the each element of an array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

int array_min(int arr[],int n){
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}
int array_location(int arr[],int n){
    int e;
    printf("Enter the element of whose location You want to find in an array:\n");
    scanf("%d",&e);
    for(int i=0;i<n;i++){
        if(arr[i]==e){
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the no of element u want in an array:\n");
    scanf("%d",&n);
    int arr[n];
    array_input(arr,n);
    int min=    array_min(arr,n);
    printf("The minimum value in array is: %d\n",min);
    int loc = array_location(arr,n);
    if(loc != -1){
        printf("The element is in arr[%d]\n",loc);
    }
    else{
        printf("Element not in an array");
    }
    return 0;
}
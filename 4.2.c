# include <stdio.h>

void bubble_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
              if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
              }
        }
    }
}

void array_input(int arr[],int n){
    printf("enter the elment of an array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void array_print(int arr[],int n){
    printf("The sorted array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the no of element u want in an array:\n");
    scanf("%d",&n);
    int arr[n];
    array_input(arr,n);
    bubble_sort(arr,n);
    array_print(arr,n);

    return 0;
}
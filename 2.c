# include <stdio.h>

void insertion(int arr[],int pos,int val,int size){
    for(int i=size-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=val;
}

int main(){
    int arr[9]={1,2,3,4,5};
    int n=9;
    int size=5;
    int pos , val;

    printf("Enter the at index at which u want to insert the value:\n");
    scanf("%d",&pos);

    printf("Enter the value that u want to insert:\n");
    scanf("%d",&val);

    insertion(arr,pos,val,size);
    size++;

    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }

    return 0;
}
# include <stdio.h>

void array_deletion(int arr[],int n,int pos){
    for(int i=0; i<n;i++){
        if(pos==i){
            for(int j=i;j<n-1;j++){
                arr[j]=arr[j+1];
            }
            break;
        }
    }
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int pos;

    printf("Enter the index at which u want to delet the element in an array:\n");
    scanf("%d",&pos);

    array_deletion(arr,n,pos);
    
    n--;
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
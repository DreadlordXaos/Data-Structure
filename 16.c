# include <stdio.h>

# define n 5

int queue[n];
int enqueue=-1;
int dequeue =0;

void push(){
    if(enqueue==n-1){
        printf("Overflow");
        return;
    }
    enqueue++;
    printf("Enter data:");
    scanf("%d",&queue[enqueue]);
    return;
}

void pop(){
    printf("%d",queue[dequeue]);
    int temp;
    for(int i=0;i<enqueue;i++){
        
    }
}
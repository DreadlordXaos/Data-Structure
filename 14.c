# include <stdio.h>
# define n 6
int top = -1;
int stack[n];

void push(){
    if(top == n-1){
        printf("Overflow...");
        return;
    }
    int x;
    printf("\nEnter the data:");
    scanf("%d",&x);
     top++;
     stack[top]=x;
     return;
}

void pop(){
    if(top==-1){
        printf("\nThe stack is empty:");
        return;
    }
    printf("\nThe vale %d has been popped out of stack:",stack[top]);
    top--;
    return;
}

void peek(){
    if(top==-1){
        printf("\nThe stack is empty:");
        return;
    }
    printf("%d",stack[top]);
    return;
}

void display(){
    if(top==-1){
        printf("\nThe stack is empty:");
        return;
    }

    for(int i=top;i<=0;i--){
        printf("\n%d",stack[i]);
    }
    return;
}


int main(){
    int choice;
    do{
        printf("\n------------- Menu -----------");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\n--------------------------------");
        printf("\nSelect your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                 push();
                 break;

            case 2:
                 pop();
                 break;

            case 3:
                 peek();
                 break;

            case 4:
                 display();
                 break;
        }
    } while(choice !=5);

    printf("Exting the program...");
    return 0;
}
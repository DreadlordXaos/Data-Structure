# include <stdio.h>
# include <stdlib.h>

struct stack{
    int data;
    struct stack*next;
};

struct stack*top=0,*newstack;

void push(){
    newstack = (struct stack *) malloc(sizeof(struct stack));
    printf("\nEnter data:");
    scanf("%d",&newstack->data);
    newstack->next=0;
    if(top==0){
        top=newstack;
    }
    else{
        newstack->next=top;
        top=newstack;
    }
    return;
}

void pop(){
    if(top ==0){
        printf("\nThe stack is empty:");
        return;
    }
    struct stack *temp;
    temp =top;
    printf("\n%d is popped form stack:",top->data);
    top=top->next;
    free(temp);
    return;
}

void peek(){
    if(top ==0){
        printf("\nThe stack is empty:");
        return;
    }
    printf("%d",top->data);
}

void display(){
    if(top ==0){
        printf("\nThe stack is empty:");
        return;
    }
    struct stack *temp=top;
    while( temp!=0){
        printf("\n%d",temp->data);
        temp = temp->next;
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
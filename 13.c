# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *temp,*head=0,*newnode;

void createlist(){
    int choice = 1;
    while(choice !=0){
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=newnode->prev=0;
        printf("\n");
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp = newnode;
        }
        printf("Do you want to continue(1/0):");
        scanf("%d",&choice);
    }
    return;
}

void printlist(){
    temp =head;
    while(temp!=0){
        printf("%d",temp->data);
        if(temp->next !=0){
            printf(" -> ");
        }
        temp = temp->next;
    }
}

void insertion(){
    int pos;
    printf("Enter the position at which u want to enter the linked list:");
    scanf("%d",&pos);
    printf("\n");
    temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    printf("\n");
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    return;
}

void deletion(){
   int pos;

printf("Enter position to delete: ");
scanf("%d",&pos);

temp = head;

if(pos == 1){

    head = head->next;
    head->prev = 0;
    free(temp);
}

else{

    for(int i=1;i<pos;i++){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
}

void reverse(){
    struct node *current;
    temp =current = head;
    while(current !=0){
        temp=current->next;
        current->next=current->prev;
        current->prev=temp;
        current=current->prev;
    }
    head = temp->prev;
}
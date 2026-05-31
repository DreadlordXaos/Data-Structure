# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

int main(){
    struct node *temp,*newnode,*head=0;
    int choice;
    printf("Do you want to create an linked list (1/0):\n");
    scanf("%d",&choice);
    while(choice != 0 ){
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d",& newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp = newnode;
        }
        printf("Do you want to continue (1/0):\n");
        scanf("%d",&choice);
    }
    temp=head;
    while(temp != 0){
        printf("%d",temp->data);
        if(temp->next != 0){
            printf(" -> ");
        }
        temp=temp->next;
    }
    temp = head;
    printf("\n");

    printf("Do you want to add node at any position(1/0):\n");
    scanf("%d",&choice);
    if(choice){
        int pos;
        printf("Enter the position that u want to enter the node:\n");
        scanf("%d",&pos);
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d",&newnode->data);
        if(pos==1){
            newnode->next=temp;
            head=newnode;
        }
        else{
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
        temp = head;
    while(temp != 0){
        printf("%d",temp->data);
        if(temp->next != 0){
            printf(" -> ");
        }
        temp=temp->next;
    }
    }
    return 0;
}
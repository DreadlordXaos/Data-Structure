# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *temp, *newnode,*head=0;
    int choice;
    printf("Do you want to create an linked list (1/0):\n");
    scanf("%d",&choice);
    while(choice != 0){
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d",& newnode->data);
        newnode->next=0;
        if(head==0){
            temp=head=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to add another node (1/0):\n");
        scanf("%d",& choice);
    }

    temp =head;
    while(temp!=0){
        printf("%d",temp->data);
        if(temp->next != 0){
            printf(" -> ");
        }
        temp=temp->next;
    }
    printf("\n");
    printf("Do you want to insert a new node at beginning(1/0):\n");
    scanf("%d",& choice);
    if(choice){
        newnode=(struct node *) malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;

        temp =head;
    while(temp!=0){
        printf("%d",temp->data);
        if(temp->next != 0){
            printf(" -> ");
        }
        temp=temp->next;
    }
    }
    return 0;
}
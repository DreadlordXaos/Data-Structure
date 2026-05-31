# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *temp ,*newnode,*head=0;

void createlist(){
    int choice =1;
    while(choice!=0){
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        printf("\n");
        if(head == 0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue(1/0):");
        scanf("%d",&choice);
        printf("\n");
    }
    return;
}

void printlist(){
    if(head == 0){
        printf("The list is empty");
        return;
    }
    temp =head;
    while(temp!=0){
        printf("%d",temp->data);
        if(temp->next !=0){
            printf(" -> ");
        }
        temp=temp->next;
    }
    return;
}

void lengthcount(){
    if(head==0){
        printf("The list is empty");
        return;
    }
    int count=0;
    temp =head;
    while(temp!=0){
        count++;
        temp = temp->next;
    }
    printf("The length of linked list is %d",count);
    printf("\n");
    return;
}

void reverse(){
    temp =head;
    struct node  *currentnode ,*prevnode=0,*nextnode;
    currentnode = nextnode =head;
    while(nextnode !=0){
        nextnode = currentnode->next;
        currentnode->next = prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head = prevnode;
    return;
}

int main(){
    int choice;
    do{
        printf("\n------------ Menu ------------\n");
        printf("1.Create a linked list\n");
        printf("2.Print linked lsit\n");
        printf("3.Print length of linked list\n");
        printf("4.Reverse linked list\n");
        printf("5. Exit\n");
        printf("Enter the choice do u want:");
        scanf("%d",&choice);
        printf("\n");

        switch(choice){
            case 1:
                createlist();
                break;
            
            case 2:
                printlist();
                break;
            
            case 3:
                lengthcount();
                break;
            
            case 4:
                reverse();
                break;
        }
    } while (choice !=5);

    printf("Exiting....");
    return 0;
}
# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *temp=0,*newnode,*head=0;

void printlist(){
    temp=head;
    printf("\n");
    if(head == 0){
        printf("List is empty\n");
        return;
    }
    while(temp!=0){
        printf("%d",temp->data);
        if(temp->next != 0){
            printf(" -> ");
        }
        temp = temp->next;
    }
}

void createlist() {
    int choice =1;
    while(choice != 0){
        newnode=(struct node *) malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
     }
    printf("\n");
    printf("Do you want to continue (1/0):");
    scanf("%d",&choice);
  }
}

void insertatbeginning(){
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("\n");
    printf("Enter Data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insertatlast(){
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("\n");
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head == 0){
        head = newnode;
        return;
    }
    temp=head;
    while(temp->next != 0){
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertatanyposition(){
    int pos;
    printf("\n");
    printf("Enter the position that u want to insert the linked list:");
    scanf("%d",&pos);
    if(pos==1){
        insertatbeginning();
    }
    else{
        newnode=(struct node *) malloc(sizeof(struct node));
        printf("\n");
        printf("Enter data:");
        scanf("%d",&newnode->data);
        temp =head;
        for( int i=1;i<pos-1;i++){
            if(temp==0){
                printf("\nInvalid position");
                free(newnode);
                return;
            }
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void deleteformbeginning(){
    if(head==0){
        printf("\nList is empty");
        return;
    }
    temp = head;
    head=head->next;
    free(temp);
}

void deletefromlast(){
    if(head == 0){
        printf("\nList is empty");
        return;
    }
    if(head->next == 0){
        free(head);
        head = 0;
        return;
    }
    temp=head;
    while(temp->next->next != 0){
        temp = temp->next;
    }
    free(temp->next);
    temp->next=0;
}

void deletefromanyposition(){
    if(head == 0){
        printf("\nList is empty");
        return;
    }
    temp=head;
    int pos;
    struct node *temp2;
    printf("\n");
    printf("Enter the position of the list that u want to delet:");
    scanf("%d",&pos);
    if(pos==1){
        deleteformbeginning();
    }
    else{
        for(int i=0;i<pos-2;i++){
            temp = temp->next;
        }
        temp2=temp->next;
        if(temp2==0){
            printf("\nInvalid Position");
            return;
        }
        temp->next=temp2->next;
        free(temp2);
    }
}

int main(){
    int choice;
    do{
        printf("\n********Menu********\n");
        printf("1.Create Linked List\n");
        printf("2.Delet from the beginning\n");
        printf("3.Delet form the last\n");
        printf("4.Delet from any position\n");
        printf("5.Insert at beginning\n");
        printf("6.Insert at last\n");
        printf("7.Insert at any position\n");
        printf("8.Print list\n");
        printf("9.Exit\n");
        printf("Enter the choice do u want:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                createlist();
                break;
            
            case 2:
                deleteformbeginning();
                break;
            
            case 3:
                deletefromlast();
                break;
            
            case 4:
                deletefromanyposition();
                break;
            
            case 5:
                insertatbeginning();
                break;
            
            case 6:
                insertatlast();
                break;
            
            case 7:
                insertatanyposition();
                break;

            case 8:
                printlist();
                break;
    }
 } while(choice != 9);
   printf("\nExitixing the program...");
   return 0;

}
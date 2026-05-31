# include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *temp,*newnode,*head=0;

void creatlist(){
    int choice;
    printf("Do you want to create an linked list:(1/0):");
    printf("\n");
    scanf("%d",&choice);
    while(choice != 0){
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head == 0){
            head = temp= newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue (1/0):");
        scanf("%d",&choice);
    }
}

void printlist(){
    temp =head;
    while(temp !=0){
        printf("%d",temp->data);
        if(temp->next != 0){
            printf(" -> ");
        }
        temp=temp->next;
    }
}

void deletebeginning(){
    printf("\n");
    int choice;
    printf("Do you want to delet the first link(1/0):");
    scanf("%d",&choice);
    printf("\n");
    if(choice){
        temp = head;
        head=head->next;
        free(temp);
        printlist();
        return;
    }
    else{
        return ;
    }
}

void deletfromend(){
    int choice;
    printf("Do you want to delet form the end(1/0):");
    scanf("%d",&choice);
    printf("\n");
    if(choice){
        int count = 0;
    temp = head;
    while(temp->next != 0){
        temp = temp->next;
        count++;
    }
    free(temp);
    temp = head;
    for(int i=0;i<count-1;i++){
        temp=temp->next;
    }
    temp->next=0;
    printlist();
    return ;
    }
    else{
        return;
    }

}

void deleteanyposition(){
    temp= head;
    int choice;
    printf("Do you want to delete from link(1/0):");
    scanf("%d",&choice);
    printf("\n");
    if(choice){
        int pos;
        printf("Enter the position which u want to delet:");
        scanf("%d",&pos);
        printf("\n");
        if(pos==1){
            temp = head;
            head=head->next;
            free(temp);
            printlist();
            return;
        }
        else{
            struct node *temp2;
        temp2=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        for(int i =0;i<pos-2;i++){
            temp2=temp2->next;
        }
        temp2->next = temp->next;
        free(temp);
        printlist();
        return ;
        }
    }
    else{
        return;
    }
}

int main(){
    creatlist();
    printlist();
    deletebeginning();
    deletfromend();
    deleteanyposition();

    return 0;
}
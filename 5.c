#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *newnode, *head = 0, *temp;
    int choice;

    printf("Do you want to create a linked list (1/0):\n");
    scanf("%d", &choice);

    while(choice != 0){

        newnode = malloc(sizeof(struct node));

        printf("Enter data:\n");
        scanf("%d", &newnode->data);

        newnode->next = 0;

        if(head == 0){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (1/0):\n");
        scanf("%d", &choice);
    }

    temp = head;

  while(temp != 0){
    printf("%d", temp->data);

    if(temp->next != 0){
        printf(" -> ");
    }

    temp = temp->next;
  }
    return 0;
}
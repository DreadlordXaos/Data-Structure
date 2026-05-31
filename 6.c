# include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* insert(struct node *head,int value){
    struct node *newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    newnode ->data=value;
    newnode ->next=head;
    head=newnode;

    return head;
}

void display(struct node *head){
    while(head != NULL){
        printf("%d",head->data);
        if(head->next != NULL){
            printf("->");
        }
        head = head->next;
    }
}

int main(){
    struct node *head=0;
    head=insert(head,10);
    head=insert(head,50);
    head=insert(head,550);

    display(head);

    return 0;
}
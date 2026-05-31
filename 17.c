# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node*create(){
    int x;
    printf("Enter data or -1 to not enter:\n");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    struct node *newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=x;
    printf("Enter data for left of %d\n",x);
    newnode->left=create();
    printf("Enter data for right of %d\n",x);
    newnode->right=create();
    return newnode;
}

int main(){
    struct node*root;
    root=0;
    root=create();
    return 0;
}
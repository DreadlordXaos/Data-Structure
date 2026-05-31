# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int x){
    struct node *newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=x;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root){
    int x;
    while(1){
        printf("Enter data or -1 to exit");
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        if(root==NULL){
            root=create(x);
        }
        else{
            struct node *temp =root;
            while(1){
                if(temp->data > x){
                    if(temp->left==NULL){
                        temp->left=create(x);
                        break;
                    }
                    temp=temp->left;
                }
                else if(temp->data <x){
                    if(temp->right==NULL){
                        temp->right=create(x);
                        break;
                    }
                    temp=temp->right;
                }
                else{
                    break;
                }
            }
        }
    }
    return root;
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    struct node *root;
    root=NULL;
    root=insert(root);
    inorder(root);
    return 0;
}
# include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int key){
    struct node *newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=key;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node*root,int key){
    if(root ==NULL){
        create(key);
    }
    if(root->data > key){
        root->left=insert(root->left,key);
    }
    else if(root->data < key){
        root->right=insert(root->right,key);
    }
    else{
        printf("Duplicate input\n");
    }
    return root;
}

struct node *search(struct node*root,int key){
    if(root ==NULL || root->data==key){
        return root;
    }
    if(root->data > key){
        return search(root->left,key);
    }
    else if(root->data < key){
        return search(root->right,key);
    }

}

struct node *inorder_successor(struct node *root){
    struct node*current;
    current=root;
    while(current && current->left != NULL){
        current =current->left;
    }
    return current;
}

struct node *delete(struct node *root,int key){
    struct node *temp;
    if(root == NULL){
        return root;
    }
    if(root->data > key){
        root->left=delete(root->left,key);
    }
    else if(root->data < key){
        root->right=delete(root->right,key);
    }
    else{
        if(root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            temp=root->right;
            free(root);
            return temp;
        }
        temp=inorder_successor(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
        return root;
    }
}



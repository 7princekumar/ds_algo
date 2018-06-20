/*
Change a tree so that the roles of the left and right pointers are swapped at every node.
So the tree...
         4 
       /   \ 
      2     5
    /   \
   1     3
   
   is changed to
         4 
       /   \  
      5     2
          /   \ 
         3     1

The solution is short, but very recursive. As it happens, this can be accomplished without 
changing the root node pointer, so the return-the-new-root construct is not necessary. 
Alternately, if you do not want to change the tree nodes, you may construct and return a new 
mirror tree based on the original tree.

void mirror(struct node* node) { ...
*/


#include <iostream>
#include <cstdbool>
#include <vector>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;


NODE new_node(int data){
    NODE temp = new(struct node);
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

NODE insert_rec(NODE root, int data){
    if(root == NULL){
        root = new_node(data);
    }else{
        if(data <= root->data){
            root->left = insert_rec(root->left, data);
        }else{
            root->right = insert_rec(root->right, data);
        }
    }
    return root;
}

NODE create_default_tree(){
    NODE root = NULL;
    int ele[] = {4,2,5,1,3};
    int n = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<n; i++){
        root = insert_rec(root, ele[i]);
    }

    return root;
}

void display_preorder(NODE root){
    if(root==NULL){
        return;
    }else{
        cout<<root->data<<" ";
        display_preorder(root->left);
        display_preorder(root->right);
    }
}


NODE mirror(NODE); //top-down -> swap from top
void mirror_bottom_up(NODE); //bottom-up ->first reach bottom and then swap and come up



int main(){
    NODE root = create_default_tree();
    cout<<"Before (pre-order): ";
    display_preorder(root);

    root = mirror(root);
    cout<<"\nAfter (pre-order): ";
    display_preorder(root);

    mirror_bottom_up(root);
    cout<<"\nAfter bottom-up (pre-order): ";
    display_preorder(root);

    return 0;
}

NODE mirror(NODE root){
    if(root == NULL){
        return NULL;
    }else{
        //swap and traverse down
        NODE lchild = root->left;
        NODE rchild = root->right;
        root->left  = rchild;
        root->right = lchild;
        root->left = mirror(root->left);
        root->right = mirror(root->right);
    }
    return root ;
}

void mirror_bottom_up(NODE root){
    if(root == NULL){
        return;
    }else{
        //traverse down
        mirror_bottom_up(root->left);
        mirror_bottom_up(root->right);

        //swap
        NODE temp = root->left;
        root->left = root->right;
        root->right = temp ;
    }
}


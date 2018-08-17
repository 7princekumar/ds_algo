/*
For each node in a binary search tree, create a new duplicate node, and insert the duplicate 
as the left child of the original node. The resulting tree should still be a binary search tree.
So the tree...
         2 
       /   \ 
      1     3
is changed to...
          2 
        /   \ 
       2     3
     /      / 
    1      3
   /   
  1
As with the previous problem, this can be accomplished without changing the root node pointer. 

void doubleTree(struct node* node) { ...
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
    int ele[] = {2,1,3};
    // int ele[] = {4,2,5,1,3};
    int n = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<n; i++){
        root= insert_rec(root, ele[i]);
    }

    return root ;
}

void display_pre_order(NODE root){
    if(root == NULL){
        return;
    }else{
        cout<<root->data<<" ";
        display_pre_order(root->left);
        display_pre_order(root->right);
    }
}


void double_tree(NODE);


int main(){
    NODE root = create_default_tree();
    cout<<"Before: "; display_pre_order(root);
    double_tree(root);
    cout<<"\nAfter: "; display_pre_order(root);
    cout<<endl ;

    return 0;
}

void double_tree(NODE root){
    if(root == NULL){
        return;
    }else{
        //traverse down
        double_tree(root->left);
        double_tree(root->right);

        //create a node with save value as root's data, attatch it as the left child
        NODE temp = new_node(root->data);
        temp->left = root->left; //first attach what will be unattached soon
        root->left = temp; //now attach this
    }
}
/*
This problem demonstrates simple binary tree traversal. 
Given a binary tree, count the number of nodes in the tree.
*/

#include <iostream>
#include <cstdbool>

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
    return temp ;
}

void display_inorder(NODE root){
    if(root == NULL){
        return;
    }else{
        display_inorder(root->left);
        cout<<root->data<<" ";
        display_inorder(root->left);
    }
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
    int ele[] = {10,5,25,3,7,20,30,2,15,22};
    int ele_size = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<ele_size; i++){
        root = insert_rec(root, ele[i]);
    }
    return root;
 }

int number_of_nodes(NODE);

int main(){
    NODE root = create_default_tree();
    cout<<"Tree: "; display_inorder(root); cout<< endl;
    cout<<"Number of nodes: "<<number_of_nodes(root); cout<< endl;


    return 0;
}

int number_of_nodes(NODE root){
    if(root == NULL){
        return 0;
    }else{
        return number_of_nodes(root->left) + number_of_nodes(root->right) + 1;
    }
}
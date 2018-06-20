/*
isBST() -- version 1
Suppose you have helper functions minValue() and maxValue() that return the min or max int value 
from a non-empty tree (see problem 3 above). Write an isBST() function that returns true if a tree 
is a binary search tree and false otherwise. Use the helper functions, and don't forget to check 
every node in the tree. 
Returns true if a binary tree is a binary search tree. 

int isBST(struct node* node) { ...
*/

#include <iostream>
#include <cstdbool>
#include <vector>
#include <queue>
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

NODE insert_in_tree(NODE root, int data, queue<NODE> &bfs_q){
    if(root == NULL){
        return new_node(data);
    }
    bfs_q.push(root);
    while(!bfs_q.empty()){
        //get the front
        NODE curr = bfs_q.front();

        //add both children if present, else attach the node
        if(curr->left != NULL){
            bfs_q.push(curr->left);
        }else{
            curr->left = new_node(data);
            break;
        }
        if(curr->right != NULL){
            bfs_q.push(curr->right);
        }else{
            curr->right = new_node(data);
            break;
        }

        //pop the front
        bfs_q.pop();
    }
    return root;
}

NODE create_BST(){
    NODE root = NULL;
    int ele[] = {4,2,5,1,3};
    int n = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<n; i++){
        root = insert_rec(root, ele[i]);
    }

    return root;
}


NODE create_BT(){
    NODE root = NULL;
    int ele[] = {1,2,3,4,5};
    int n = sizeof(ele)/sizeof(ele[0]);
    
    queue<NODE> bfs_q;
    for(int i=0; i<n; i++){
        root = insert_in_tree(root, ele[i], bfs_q);
    }

    return root;
}

void print_in_order(NODE root){
    if(root == NULL){
        return;
    }
    print_in_order(root->left);
    cout<<root->data<<' ';
    print_in_order(root->right);
}

void store_in_order(NODE root, vector<int> &ele){
    if(root == NULL){
        return;
    }
    store_in_order(root->left, ele);
    ele.push_back(root->data);
    store_in_order(root->right, ele);
}

bool isBST(NODE);


int main(){
    NODE bst_root = create_BST();
    NODE bt_root = create_BT();
    cout<<"BST(inorder): "; print_in_order(bst_root);cout<<endl;
    if(isBST(bst_root)){
        cout<<"BST."<<endl;
    }else{
        cout<<"Not a BST."<<endl;
    }

    cout<<"BT(inorder) : "; print_in_order(bt_root); cout<<endl;
    if(isBST(bt_root)){
        cout<<"BST."<<endl;
    }else{
        cout<<"Not a BST."<<endl;
    }

    return 0;
}


bool isBST(NODE root){
    vector<int> ele;
    store_in_order(root, ele);

    bool flag = true;
    for(int i=1; i<ele.size(); i++){
        for(int j=0; j<i-1; j++){
            if(ele[j] >= ele[i]) flag = false;
        }
        for(int j=i; j<ele.size(); j++){
            if(ele[j] < ele[i]) flag = false;
        }
    }
    return flag;
}
/*
Given two binary trees, return true if they are structurally identical -- they are made 
of nodes with the same values arranged in the same way.

int sameTree(struct node* a, struct node* b) {
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

NODE create_default_tree_a(){
    NODE root = NULL;
    int ele[] = {2,1,3};
    int n = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<n; i++){
        root = insert_rec(root, ele[i]);
    }
    return root;
}

NODE create_default_tree_b(){
    NODE root = NULL;
    int ele[] = {2,1};
    int n = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<n; i++){
        root = insert_rec(root, ele[i]);
    }
    return root;
}


bool same_tree(NODE , NODE);



int main(){
    NODE root_a = create_default_tree_a();
    NODE root_b = create_default_tree_b();

    if(same_tree(root_a, root_b)){
        cout<<"SAME"<<endl;
    }else{
        cout<<"NOT SAME"<<endl;
    }
    return 0;
}

bool same_tree(NODE a, NODE b){
    if(a == NULL && b == NULL){ //both null
        return true;
    }
    if( (a != NULL) && (b != NULL) ){ //both not null
        if(a->data == b->data){
            if( same_tree(a->left, b->left) && same_tree(a->right, b->right) ){
                return true;
            }
        }
    }

    return false;
}
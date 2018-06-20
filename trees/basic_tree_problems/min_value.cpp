/*
Given a non-empty binary search tree (an ordered binary tree), 
return the minimum data value found in that tree. 
Note that it is not necessary to search the entire tree. 
A maxValue() function is structurally very similar to this function. 
This can be solved with recursion or with a simple while loop.

int minValue(struct node* node) { ...
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

    return temp;
}

NODE insert_rec(NODE root, int data){
    if(root==NULL){
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
    int ele[] = {10,5,15,3,7,20,30,2,15,22};
    int n = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<n; i++){
        root = insert_rec(root, ele[i]);
    }
    
    return root;
}



int min_value(NODE);



int main(){
    NODE root = create_default_tree();
    cout<<"Min value: "<<min_value(root); cout<<endl ;

    return 0;
}


int min_value(NODE root){
    NODE p = root;
    while(p->left != NULL){
        p = p->left;
    }
    return p->data;
}
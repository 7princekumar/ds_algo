//print zig zag/ spiral
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
        if(data < root->data){
            root->left = insert_rec(root->left, data);
        }else{
            root->right = insert_rec(root->right, data);
        }
    }
    return root;
}

NODE create_default_tree(){
    NODE root = NULL;
    int a[] = {10,5,25,3,7,20,30,2,15,22,6};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        root = insert_rec(root, a[i]);
    }
    return root;
}


void print_zig_zag(NODE root){
    if(root == NULL) return;
    stack<NODE> s1;
    stack<NODE> s2;
    
    //first fill 1st stack
    s1.push(root);

    while( !(s1.empty() && s2.empty()) ){
        while(!s1.empty()){
            //put childrens of s1 nodes to s2 (first left, then right)
            NODE temp = s1.top(); s1.pop();
            cout << temp->data << " ";
            if(temp->left  != NULL) s2.push(temp->left);
            if(temp->right != NULL) s2.push(temp->right);
        }

        while(!s2.empty()){
            //put childrens of s2 nodes to s1 (first right, then left)
            NODE temp = s2.top(); s2.pop();
            cout << temp->data << " ";
            if(temp->right != NULL) s1.push(temp->right);
            if(temp->left  != NULL) s1.push(temp->left);
        }
    }
}


int main(){
    NODE root = create_default_tree();
    print_zig_zag(root); cout << endl;
    return 0;
}
//print_level_order
#include <iostream>
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


void print_level_order(NODE root){
    if(root == NULL) return;
    queue<NODE> q;
    q.push(root);
    while(!q.empty()){
        NODE temp = q.front();
        q.pop();
        //print data for the current node
        cout << temp->data << " ";
        //add its children if any
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}


int main(){
    NODE root = create_default_tree();
    print_level_order(root); cout << endl;
    return 0;
}
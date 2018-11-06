#include <iostream>
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
    int a[] = {2,1,3};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        root = insert_rec(root, a[i]);
    }
    return root;
}

void print_inorder(NODE root){
    if(root == NULL) return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

void duplicate(NODE root){
    if(root == NULL) return;
    duplicate(root->left);
    duplicate(root->right);

    NODE temp = new_node(root->data);

    if(root->left == NULL){ //leaf node
        root->left = temp;
    }else{                  // intermediate node
        temp->left = root->left;
        root->left = temp;
    }
}

int main(){
    NODE root = create_default_tree();
    
    cout << "Before: "; print_inorder(root);
    cout << endl;
    duplicate(root);
    cout << "After : "; print_inorder(root); 
    cout << endl;

    return 0;
}
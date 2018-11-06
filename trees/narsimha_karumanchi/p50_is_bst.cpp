//check if a tree is BST
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
    int a[] = {10,5,25,3,7,20,30,2,15,22,6}; //bst
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        root = insert_rec(root, a[i]);
    }
    return root;
}

NODE create_default_tree2(){
    NODE root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    return root;
}

void print_inorder(NODE root){
    if(root == NULL) return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

bool is_bst(NODE root, int min, int max){
    if(root == NULL) return true;
    if((min < root->data) && (root->data < max)){
        return is_bst(root->left, min, root->data) && is_bst(root->right, root->data, max);
    }
    return false;
}



int main(){
    NODE bst_root = create_default_tree();    
    if(is_bst(bst_root, INT_MIN, INT_MAX)) cout << "YES\n";
    else cout << "NO\n";

    NODE root = create_default_tree2();
    if(is_bst(root, INT_MIN, INT_MAX)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
//given a bst and two numbers K1 and K2, give an algo for printing all the elements 
//of BST in the range K1 and K2.
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
    int a[] = {10,5,25,3,7,20,30,2,15,22,6};
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

void print_btw_range(NODE root, int K1, int K2){
    if(root == NULL) return;
    print_btw_range(root->left, K1, K2);
    if((K1 <= root->data) && (root->data <= K2)){
        cout << root->data << " ";
    }
    print_btw_range(root->right, K1, K2);
}


int main(){
    NODE root = create_default_tree();
    print_inorder(root); cout << endl;
    int k1, k2; cin >> k1 >> k2;
    print_btw_range(root, k1, k2);
    cout << endl;

    return 0;
}
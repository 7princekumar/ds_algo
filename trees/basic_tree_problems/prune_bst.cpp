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

NODE prune_bst(NODE root, int k1, int k2){
    if(root == NULL) return NULL;

    //traverse down first (bottom up) => postorder
    root->left = prune_bst(root->left, k1, k2);
    root->right = prune_bst(root->right, k1 ,k2);

    //check
    if(k1 <= root->data && root->data <= k2){
        return root;
    }else if(root->data < k1){
        return root->right;
    }else{ //means root->data > k2
        return root->left;
    }

    return root;
}



int main(){
    NODE root = create_default_tree();
    cout << "Before: "; print_inorder(root); cout << endl;
    int k1, k2;
    cout <<"k1: "; cin >> k1;
    cout <<"k2: "; cin >> k2;

    root = prune_bst(root, k1, k2);
    cout << "After: "; print_inorder(root); cout << endl;

    return 0;
}
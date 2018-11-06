//same tree
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

NODE create_default_tree1(){
    NODE root = NULL;
    int a[] = {10,5,25,3,7,20,30,2,15,22,6};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        root = insert_rec(root, a[i]);
    }
    return root;
}
NODE create_default_tree2(){
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

bool same_tree(NODE root1, NODE root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL && root2 != NULL){
        return false;
    }else if(root1 != NULL && root2 == NULL){
        return false;
    }else{
        if(root1->data == root2->data){
            return same_tree(root1->left, root2->left) && same_tree(root1->right, root2->right);
        }else{
            return false;
        }
    }
}


int main(){
    NODE root1 = create_default_tree1();
    NODE root2 = create_default_tree2();
    if(same_tree(root1, root2)){
        cout << "Same.";
    }else{
        cout << "Not same.";
    }
    cout << endl;

    return 0;
}
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

NODE find_min(NODE root){
    NODE p = root;
    while(p->left != NULL){
        p = p->left;
    }
    return p;
}

void find_successor(NODE root, NODE &ans, int data){
    if(root == NULL) return;
    if(root->data == data){
        if(root->right != NULL){
            ans = find_min(root->right);
        }
    }else if(data > root->data){
        find_successor(root->right, ans, data);
    }else{
        ans = root;
        find_successor(root->left, ans, data);
    }
}



int main(){
    NODE root = create_default_tree();
    print_inorder(root); cout << endl;
    int n; cout << "n: "; cin >> n;
    
    NODE ans = NULL;
    find_successor(root, ans, n);
    if(ans != NULL){
        cout << "successor: " << ans->data << endl;
    }else{
        cout << "not found" << endl;
    }

    return 0;
}
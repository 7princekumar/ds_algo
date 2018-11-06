//is_bst
#include <iostream>
#include <vector>
#include <cstdbool>
#include <queue>
#include <algorithm>
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

NODE create_default_bst(){
    NODE root = NULL;
    int a[] = {10,5,25,3,7,20,30,2,15,22,6};
    int a_size = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<a_size; i++){
        root = insert_rec(root, a[i]);
    }
    return root;
}


NODE insert_bt(NODE root, int data){
    if(root == NULL){
        return new_node(data);
    }
    queue<NODE> q;
    q.push(root);
    while(!q.empty()){
        NODE temp = q.front();
        q.pop();
        
        if(temp->left != NULL){
            q.push(temp->left);
        }else{
            temp->left = new_node(data);
            break;
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }else{
            temp->right = new_node(data);
            break;
        }
    }
    return root;
}

NODE create_default_bt(){
    NODE root = NULL;
    int a[] = {10,5,25,3,7,20,30,2,15,22,6};
    int a_size = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<a_size; i++){
        root = insert_bt(root, a[i]);
    }
    return root;
}

void print_tree_inorder(NODE root){
    if(root == NULL) return;
    print_tree_inorder(root->left);
    cout << root->data << " ";
    print_tree_inorder(root->right);
}

void store_inorder(NODE root, vector<int>& v){
    if(root == NULL){
        return;
    }else{
        store_inorder(root->left, v);
        v.push_back(root->data);
        store_inorder(root->right, v);
    }
}


bool is_bst(NODE root){
    vector<int> v;
    store_inorder(root, v);
    return is_sorted(v.begin(), v.end());
}


int main(){
    NODE r1 = create_default_bst();
    NODE r2 = create_default_bt();

    print_tree_inorder(r1); cout << endl;
    print_tree_inorder(r2); cout << endl;

    is_bst(r1) ? cout << "yes\n": cout << "no\n";
    is_bst(r2) ? cout << "yes\n": cout << "no\n";
    return 0;
}
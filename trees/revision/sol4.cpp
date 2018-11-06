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
    int a_size = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<a_size; i++){
        root = insert_rec(root, a[i]);
    }
    return root;
}

int min_value(NODE root){
    if(root == NULL) return -1;
    NODE p = root;
    while(p->left != NULL){
        p = p->left;
    }
    return p->data;
}


int main(){
    NODE root = create_default_tree();
    cout << "min_value: " << min_value(root) << endl;
    return 0;
}


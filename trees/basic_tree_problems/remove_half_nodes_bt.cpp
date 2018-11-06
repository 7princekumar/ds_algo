//http://www.techiedelight.com/convert-given-binary-tree-to-full-tree-removing-half-nodes/
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

bool is_leaf(NODE root){
    if(root->left == NULL && root->right == NULL) return true;
    else return false;
}

bool has_two_child(NODE root){
    if(root->left != NULL && root->right != NULL) return true;
    else return false;
}

NODE remove_half_nodes(NODE root){
    if(root == NULL) return NULL;
    
    //traverse
    root->left = remove_half_nodes(root->left);
    root->right = remove_half_nodes(root->right);

    //check
    if(has_two_child(root) || is_leaf(root)){
        return root;
    }else{
        //definatly root has atleast one child now
        if(root->left == NULL){
            return root->right;
        }else{
            return root->left;
        }
    }
    return root;
}

//NOTE: we can store child node in a variable and can do 'delete root' and return the child node to
//avoid memory leak



int main(){
    NODE root = create_default_tree();
    cout << "Before: "; print_inorder(root); cout << endl;
    root = remove_half_nodes(root);
    cout << "After: "; print_inorder(root); cout << endl;

    return 0;
}
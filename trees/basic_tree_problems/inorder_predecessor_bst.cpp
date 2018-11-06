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

NODE find_max(NODE root){
    NODE p = root;
    while(p->right != NULL){
        p = p->right;
    }
    return p;
}



void find_predecessor(NODE root, NODE& ans, int data){
    if(root == NULL) return;
    if(root->data == data){
        //we found the node with the given data, pred is in it's left subtree if any
        if(root->left != NULL){ 
            ans = find_max(root->left); //don't pass ref more than once ->ERROR
        }
        //NOTE: else part is taken care while traversing right where we saved the root as ans
    }else if(data < root->data){
        find_predecessor(root->left, ans, data);
    }else{
        //before going to right sub-tree, mark ans as the current node, 
        //right-sub-tree doesn't have left child node
        ans = root;
        find_predecessor(root->right, ans, data);
    }
}




int main(){
    NODE root = create_default_tree();
    print_inorder(root); cout << endl;
    int n; cout << "n: "; cin >> n;
    
    NODE ans = NULL;
    find_predecessor(root, ans, n);
    if(ans != NULL){
        cout << "predecessor: " << ans->data << endl;
    }else{
        cout << "not found" << endl;
    }

    return 0;
}


/*
algo:
    find the node in the tree
    if node->left is present, find the max node taking node->left as root
    else, traverse right, but first save the ans as current-root

*/
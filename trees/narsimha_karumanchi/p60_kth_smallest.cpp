//kth smallest elememt in bst
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


//counts the nodes in this sub-tree including root provided
int count_nodes(NODE root){
    if(root == NULL) return 0;
    int count = 0;
    count += count_nodes(root->left) + 1 + count_nodes(root->right);
    return count;
}

void kth_smallest_node(NODE root, NODE& ans, int k){
    if(root == NULL) return;
    //traverse all nodes in inorder fashion
    kth_smallest_node(root->left, ans, k);
    if((count_nodes(root->left) + 1) == k){
        ans = root;
        return;
    }
    kth_smallest_node(root->right, ans, k);
}


int main(){
    NODE root = create_default_tree();
    print_inorder(root);
    int k = 3;
    cout << "\nNodes: " << count_nodes(root) << endl;

    NODE ans = NULL;
    kth_smallest_node(root, ans, k);
    if(ans != NULL) cout << ans->data << endl;
    else cout << "no\n";
    
    return 0;
}
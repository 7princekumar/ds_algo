//lca of two leaf nodes in bst -> Os(log n)
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

//checks if node is present in the bst, true if present, else false;
void check(NODE root, bool& found, int x){
    if(root == NULL) return;
    if(root->data == x){
        found = true; return;
    }else{
        check(root->left, found, x);
        check(root->right, found, x);
    }
    
}

//METHOD 1
void find_lca_bst(NODE root, NODE* parent, int d1, int d2){
    if(root == NULL) return;
    if((d1 < root->data) && (root->data < d2)){
        *parent = root;
        return;
    }
    if(root->left != NULL) find_lca_bst(root->left, parent, d1, d2);
    if(root->right != NULL) find_lca_bst(root->right, parent, d1, d2);
}

//METHOD 2 (use this one)
NODE find_lca_bst(NODE root, int d1, int d2){
    if(root == NULL) return NULL;
    if((d1 < root->data) && (d2 < root->data)) 
        return find_lca_bst(root->left, d1, d2); //both less, lca must be in left
    if((d1 > root->data) && (d2 > root->data)) 
        return find_lca_bst(root->right, d1, d2); //both greater, lca must be in right
    return root;
}



int main(){
    NODE root = create_default_tree();
    int d1 = 2, d2 = 6;
    
    //check if both nodes are present in bst
    bool found1 = false, found2 = false;
    check(root, found1, d1);
    check(root, found2, d2);
    if(!found1 || !found2){
        cout << "Nodes are not present.\n";
        return 0;
    }
    
    //find lca now
    NODE parent = NULL;
    find_lca_bst(root, &parent, d1, d2);
    if(parent != NULL) cout << parent->data << endl;
    else cout << "Something went wrong.\n";

    //lca using method 2
    parent = find_lca_bst(root, d1, d2);
    if(parent != NULL) cout << parent->data << endl;
    else cout << "Something went wrong.\n";

    return 0;
}
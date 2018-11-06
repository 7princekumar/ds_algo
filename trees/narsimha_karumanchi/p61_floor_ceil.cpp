//floor - the largest key in the BST less than or equal to the key
//ceil  - the smallest key in the BST greater than or equal to the key
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

//NOTE: draw a sample tree and then work out, becomes easier
void ceil_of_node(NODE root, int n, NODE& ans){ //n = 23, output = 25
    //base case
    if(root == NULL) return;
    if(root->data == n){
        ans = root;
        return;
    }

    if(root->data < n){ //ans is in right sub-tree, as we need a number greater than n
        ceil_of_node(root->right, n, ans);
    }else{
        ans = root;
        ceil_of_node(root->left, n, ans);
    }
}


void floor_of_node(NODE root, int n, NODE& ans){
    //base case
    if(root == NULL) return;
    if(root->data == n){
        ans = root;
        return;
    }

    //traverse accordingly
    if(root->data > n){ //ans is in left sub-tree as ans is less than n
        floor_of_node(root->left, n, ans);
    }else{
        ans = root; 
        floor_of_node(root->right, n, ans);
    }
}



int main(){
    NODE root = create_default_tree();
    cout << "bst(inorder): "; print_inorder(root); cout << endl;
    int n; cout << "n: "; cin >> n;
    
    NODE ans = NULL; 
    ceil_of_node(root, n, ans);
    if(ans != NULL)
        cout << "Ceil: " << ans->data << endl;
    
    ans = NULL; 
    floor_of_node(root, n, ans);
    if(ans != NULL)
        cout << "Floor: " << ans->data << endl;
    
    return 0;
}
//lca of two leaf nodes in bt(not bst)
#include <iostream>
#include <queue>
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

NODE insert_bt(NODE root, int data){
    if(root == NULL){
        root = new_node(data);
    }else{
        queue<NODE> q;
        q.push(root);
        while(!q.empty()){
            NODE temp = q.front();
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }else{
                temp->left = new_node(data); break;
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }else{
                temp->right = new_node(data); break;
            }
        }
    }
    return root;
}

NODE create_default_tree(){
    NODE root = NULL;
    int a[] = {1,2,3,4,5,6,7,8,9,10,11};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++){
        root = insert_bt(root, a[i]);
    }
    return root;
}

void print_inorder(NODE root){
    if(root == NULL) return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

void check(NODE root, bool& found, int x){
    if(root == NULL) return;
    if(root->data == x){
        found = true; return;
    }else{
        check(root->left, found, x);
        check(root->right, found, x);
    }
    
}

//this code assumes both d1 and d2 are present in the bt
NODE find_lca_bt(NODE root, int d1, int d2){
    //base case
    if(root == NULL) return NULL;
    if(root->data == d1 || root->data == d2) return root;

    //traverse left and right
    NODE left_lca  = find_lca_bt(root->left,  d1, d2);
    NODE right_lca = find_lca_bt(root->right, d1, d2);

    //if both are not null, means for this node, both are present left, right of this node
    if(left_lca != NULL && right_lca != NULL) return root;
    
    //one of them is null, then
    if(left_lca != NULL){
        return find_lca_bt(root->left, d1, d2);
    }else{
        return find_lca_bt(root->right, d1, d2);
    }
}



int main(){
    NODE root = create_default_tree();
    int d1 = 7, d2 = 10;
    
    //check if both nodes are present in bst
    bool found1 = false, found2 = false;
    check(root, found1, d1);
    check(root, found2, d2);
    if(!found1 || !found2){
        cout << "Nodes are not present.\n";
        return 0;
    }
    
    //find lca now
    NODE parent = find_lca_bt(root, d1, d2);
    if(parent != NULL) cout << parent->data << endl;
    else cout << "Something went wrong.\n";

    return 0;
}
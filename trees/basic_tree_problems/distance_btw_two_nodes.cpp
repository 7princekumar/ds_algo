#include <iostream>
#include <cstdbool>
#include <vector>
#include <stack>
#include <queue>
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
    if(root == NULL) return new_node(data);
    queue<NODE> q;
    q.push(root);
    while(!q.empty()){
        NODE curr = q.front(); q.pop();
        if(curr->left != NULL){
            q.push(curr->left);
        }else{
            curr->left = new_node(data);
            break;
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }else{
            curr->right = new_node(data);
            break;
        }
    }
    return root;
}

NODE create_tree(){
    NODE root = new_node(1); 
    root->left = new_node(2); 
    root->right = new_node(3); 
    root->left->left = new_node(4); 
    root->left->right = new_node(5); 
    root->right->left = new_node(6); 
    root->right->right = new_node(7); 
    root->right->left->right = new_node(8);
    return root;
}

NODE create_bt(){
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

void print_level_order(NODE root){
    if(root == NULL) return;
    queue<NODE> q;
    q.push(root);
    while(!q.empty()){
        NODE curr = q.front(); q.pop();
        if(curr == NULL) continue;
        cout << curr->data << " ";
        q.push(curr->left);
        q.push(curr->right);
    }
}

//finds lca of two nodes assuming both are present
NODE find_lca(NODE root, int n1, int n2){
    if(root == NULL) return NULL;
    if(root->data == n1 || root->data == n2) return root;

    NODE left_node = find_lca(root->left, n1, n2);
    NODE right_node = find_lca(root->right, n1, n2);

    if(left_node != NULL && right_node != NULL) return root; // if both not null, then root is ans;
    
    if(left_node != NULL) return left_node;
    else return right_node;
}


//find level of the node (note: root as level 0)
int find_level(NODE root, int n, int level){
    if(root == NULL) return -1;
    if(root->data == n) return level;
    
    int temp = find_level(root->left, n, level + 1);
    if(temp >= 0) return temp;
    return find_level(root->right, n, level + 1);
}


//assuming both nodes are present in the tree
//if not, just run a check function to see if both are there first
int get_distance(NODE root, int n1, int n2){
    NODE lca_node = find_lca(root, n1, n2);
    int d1 = find_level(lca_node, n1, 0);
    int d2 = find_level(lca_node, n2, 0);
    return d1 + d2 + 1;
}

int main(){
    // NODE root = create_bt();
    NODE root = create_tree();
    cout << "tree(inorder)    : "; print_inorder(root); cout << endl;
    cout << "tree(level-order): "; print_level_order(root); cout << endl;
    cout << "distance: " << get_distance(root, 8, 5) << endl;
    return 0;
}
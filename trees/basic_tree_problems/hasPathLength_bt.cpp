/*
In Binary Tree (not bst): ROOT TO LEAF path
            5
          /  \ 
         4    8
        /    /  \ 
       11   13   4 
      /   \       \ 
     7     2       1
Root-to-leaf paths:
   path 1: 5 4 11 7
   path 2: 5 4 11 2
   path 3: 5 8 13
   path 4: 5 8 4  1
*/
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

NODE create_default_bt(){
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

bool has_path(NODE root, int sum){
    if(root == NULL) return (sum == 0);
    return has_path(root->left, sum - root->data) || has_path(root->right, sum - root->data);
}


int main(){
    NODE root = create_default_bt();
    int sum = 188;
    if(has_path(root, sum)) cout << "yes\n";
    else cout << "no\n";
    return 0;
}
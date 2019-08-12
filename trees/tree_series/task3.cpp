/*
Given a binary tree, compute its "maxDepth" -- the number of nodes
along the longest path from the root node down to the farthest leaf 
node. The maxDepth of the empty tree is 0.
*/

#include <iostream>
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

void print_inorder(NODE root){
  if(root == NULL) return;
  print_inorder(root->left);
  cout << root->data << " ";
  print_inorder(root->right);
}

NODE create_default_btree(){
  int a[] = {10,5,25,3,7,20,30,2,6,15,22};
  int n = sizeof(a)/sizeof(a[0]);
  NODE root = NULL;
  for(int i=0; i<n; i++){
    root = insert_rec(root, a[i]);
  }
  return root;
}

int depthof_btree(NODE root){
  if(root == NULL) return 0;
  int lh = depthof_btree(root->left);
  int rh = depthof_btree(root->right);
  return 1 + max(lh, rh);
}

int depthof_btree(NODE root, int depth){
  if(root == NULL) return depth;
  int lh = depthof_btree(root->left, depth + 1);
  int rh = depthof_btree(root->right, depth + 1); 
  return max(lh, rh);
}


int main(){
  NODE root = create_default_btree();
  cout << "btree: "; print_inorder(root); cout << endl;
  cout << "depth1: " << depthof_btree(root) << endl;
  cout << "depth2: " << depthof_btree(root, 0) << endl;
  return 0;
}

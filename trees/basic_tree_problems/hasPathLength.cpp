/*
We'll define a "root-to-leaf path" to be a sequence of nodes in a tree starting 
with the root node and proceeding downward to a leaf (a node with no children). 
We'll say that an empty tree contains no root-to-leaf paths. So for example, 
the following tree has exactly four root-to-leaf paths:
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
   path 4: 5 8 4 1
For this problem, we will be concerned with the sum of the values of such a path -- for example, the sum of the values on the 5-4-11-7 path is 5 + 4 + 11 + 7 = 27.
Given a binary tree and a sum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. Return false if no such path can be found. (Thanks to Owen Astrachan for suggesting this problem.)

int hasPathSum(struct node* node, int sum) {
*/


#include <iostream>
#include <cstdbool>
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
        if(data <= root->data){
            root->left = insert_rec(root->left, data);
        }else{
            root->right = insert_rec(root->right, data);
        }
    }
    return root;
}

NODE create_default_tree(){
    NODE root = NULL;
    int ele[] = {10,5,15,3,7,12,20,2,11,13,30};
    int n = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<n; i++){
        root = insert_rec(root, ele[i]);
    }
    
    return root;  
}


bool hasPathLength(NODE, int);


int main(){
    int k; cout<<"K(sum): "; cin>> k;
    NODE root = create_default_tree();
    
    if(hasPathLength(root, k)){
        cout<<"Present."<<endl;
    }else{
        cout<<"Not present."<<endl;
    }

    return 0;
}

bool hasPathLength(NODE root, int curr_sum){
    if(root==NULL){
        return (curr_sum == 0);
    }else{
        return ( hasPathLength(root->left, curr_sum - root->data) || hasPathLength(root->right, curr_sum - root->data) );
    }
}
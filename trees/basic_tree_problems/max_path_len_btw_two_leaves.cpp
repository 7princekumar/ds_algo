//maximum path length btw two nodes in a tree

#include <iostream>
#include <cstdbool>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

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


NODE create_default_tree(){
    NODE root = new_node(-15); 
    root->left = new_node(5); 
    root->right = new_node(6); 
    root->left->left = new_node(-8); 
    root->left->right = new_node(1); 
    root->left->left->left = new_node(2); 
    root->left->left->right = new_node(6); 
    root->right->left = new_node(3); 
    root->right->right = new_node(9); 
    root->right->right->right= new_node(0); 
    root->right->right->right->left= new_node(4); 
    root->right->right->right->right= new_node(-1); 
    root->right->right->right->right->left= new_node(10); 
    return root;  
}

void store_inorder(NODE root, vector<int>& nodes){
    if(root == NULL) return;
    store_inorder(root->left, nodes);
    nodes.push_back(root->data);
    store_inorder(root->right, nodes);
}


//NOTE(debug info): you can't return a ref variable
//for each node from top to bottom, calc
int max_path(NODE root, int& score){
    //base case
    if(root == NULL) return INT_MIN; //since we're calculating max of two nodes' data
    if(root->left == NULL && root->right == NULL) return root->data; //leaf

    //traverse down first
    int left_score  = max_path(root->left, score);
    int right_score = max_path(root->right, score);

    //now, do stuff(with the ref variables) and then return stuff
    //ie, calculate local_score
    int local_score = max(left_score, right_score) + root->data;
    //calculate score
    if(root->left != NULL && root->right != NULL){ //has two child
        score = max(score, left_score + right_score + root->data); //score
    }else{
        if(root->left == NULL){
            score = max(score, right_score + root->data);
        }else{
            score = max(score, left_score  + root->data);
        }
    }

    return local_score; 
}


void print_v(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(){
    NODE root = create_default_tree();
    vector<int> nodes;
    store_inorder(root, nodes);
    cout << "Nodes: "; print_v(nodes);
    int score = INT_MIN;
    max_path(root, score);
    cout << score << endl;
    return 0;
}

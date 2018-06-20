/*
Given a binary tree, print out all of its root-to-leaf paths as defined above. 
This problem is a little harder than it looks, since the "path so far" needs to 
be communicated between the recursive calls. Hint: In C, C++, and Java, probably 
the best solution is to create a recursive helper function printPathsRecur(node, 
int path[], int pathLen), where the path array communicates the sequence of nodes 
that led up to the current call. Alternately, the problem may be solved bottom-up, 
with each node returning its list of paths. This strategy works quite nicely in Lisp, 
since it can exploit the built in list and mapping primitives. 
Given a binary tree, print out all of its root-to-leaf paths, one per line. 
    
void printPaths(struct node* node) {
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
    int ele[] = {10,5,25,3,7,20,30,2,15,22};
    int n = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<n; i++){
        root = insert_rec(root, ele[i]);
    }

    return root;
}

void print_paths(NODE, vector<int>) ;

int main(){
    NODE root = create_default_tree();
    vector<int> paths;
    print_paths(root, paths) ;

    return 0;
}

void print_i_v(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"->";
    }
    cout<<endl;
}

//pre-order ->as root at the top
void print_paths(NODE root, vector<int> curr_path){
    curr_path.push_back(root->data);
    
    if(root->left == NULL && root->right == NULL){
        // it's a leaf, so print the path that led to here
        print_i_v(curr_path);
    }else{
        if(root->left != NULL)
            print_paths(root->left, curr_path);
        if(root->right != NULL)
            print_paths(root->right, curr_path);
    }
}
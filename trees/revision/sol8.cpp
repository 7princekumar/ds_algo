//print paths
#include <iostream>
#include <vector>
#include <cstdbool>

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
    for(int i=0; i< n; i++){
        root = insert_rec(root, a[i]);
    }
    return root;
}

void print_2v(vector<vector<int> >& v){
    for(int i=0; i< v.size(); i++){
        for(int j=0; j< v[i].size(); j++){
            cout << v[i][j] << "-> ";
        }
        cout << endl;
    }
}


void store_paths(NODE root, vector<vector<int> >& v, vector<int> path){
    if(root == NULL) return; 
    if(root->left == NULL && root->right == NULL){ //if leaf
        path.push_back(root->data);
        v.push_back(path);
    }else{
        path.push_back(root->data);
        if(root->left != NULL)
            store_paths(root->left, v, path);
        if(root->right != NULL)
            store_paths(root->right, v, path);
    }
}

void print_paths(NODE root){
    vector<vector<int> > paths;
    vector<int> path;
    store_paths(root, paths, path);
    print_2v(paths);
}



int main(){
    NODE root = create_default_tree();
    print_paths(root);
    return 0;
}
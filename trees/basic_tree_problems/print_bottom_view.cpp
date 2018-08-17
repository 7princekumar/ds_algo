 //TRAVERSE IN any-traveral form, post,pre, in order.
#include <iostream>
#include <cstdbool>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct node {
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
        if(data<root->data){
            root->left = insert_rec(root->left, data);
        }else{
            root->right = insert_rec(root->right, data);
        }
    }
    return root;
}

NODE create_default_tree(){
    NODE root = NULL;
    int ele[] = {4,2,6,1,3,5,7};
    int ele_size = sizeof(ele)/sizeof(ele[0]);
    for(int i=0; i<ele_size; i++){
        root = insert_rec(root, ele[i]);
    }
    return root;
}

void print_i_v(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

void print_bottom_view(NODE);
void bottom_view(NODE, map<int, vector<int> > &, int); 
int height_of_tree(NODE);

int main(){
    NODE root = create_default_tree();
    print_bottom_view(root);
    return 0;
}

int height_of_tree(NODE root){
    if(root == NULL){
        return 0;
    }else{
        int lh = height_of_tree(root->left) + 1;
        int rh = height_of_tree(root->right) + 1;
        return max(lh, rh);
    }
}

void print_bottom_view(NODE root){
    //hash
    map<int, vector<int> > hash;
    
    //call helper-function with level=0
    bottom_view(root, hash, 0);
    
    //print hash
    int height = height_of_tree(root);
    for(int i=height-1; i>=0; i--){
        print_i_v(hash[i]);
    }
    cout<< endl;
}

void bottom_view(NODE root, map<int, vector<int> > &hash, int level){
    if(root == NULL){
        return;
    }else{
        //traverse
        bottom_view(root->left, hash, level+1);
        bottom_view(root->right, hash, level+1);

        //do something
        hash[level].push_back(root->data);
    }
}
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
    NODE temp = new (struct node);
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

NODE insert_rec(NODE root, int data){
    if(root==NULL){
        root = new_node(data);
    }else{
        if(data <= root->data){
            root->left = insert_rec(root->left, data);
        }else{
            root->right = insert_rec(root->right, data);
        }
    }
    return root ;
}

NODE create_default_tree(){
    NODE root = NULL ;
    int ele[] = {10,5,25,3,7,20,30,2,15,22,6};
    int ele_size = sizeof(ele)/sizeof(ele[0]);

    for(int i=0; i<ele_size; i++){
        root = insert_rec(root, ele[i]);
    }

    return root;
}




int max_depth(NODE) ;

int main(){
    NODE root = create_default_tree();
    int depth = max_depth(root) ;
    cout<<"Depth: "<<depth<<endl; 

    return 0;
}






int max_depth(NODE root){
    if(root == NULL){
        return 0;
    }else{
        int left_depth  = max_depth(root->left);
        int right_depth = max_depth(root->right);

        if(left_depth >= right_depth){
            return left_depth + 1;
        }else{
            return right_depth + 1;
        }
    }
    
}
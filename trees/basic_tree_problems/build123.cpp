/*
Write code that builds the following little 1-2-3 binary search tree...
a: by calling newNode() three times, and using three pointer variables
b: by calling newNode() three times, and using only one pointer variable
c: by calling insert() three times passing it the root pointer to build up the tree
*/

#include <iostream>
#include <vector>
#include <cstdbool>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;

NODE new_node(int);
void display_in_order(NODE);   //root at the middle
NODE insert_rec(NODE, int);
void solution1();
void solution2();
void solution3();

int main(){
    solution1();
    solution2();
    solution3();

    return 0;
}

void solution1(){
    //a: by calling newNode() three times, and using three pointer variables
    NODE root = new_node(2);
    
    NODE left_child = new_node(1);
    root->left = left_child;
    
    NODE right_child = new_node(3);
    root->right = right_child;

    cout<<"Solution 1: "; display_in_order(root); cout<<endl ;
}

void solution2(){
    //b: by calling newNode() three times, and using only one pointer variable
    NODE root = new_node(2);
    root->left = new_node(1);
    root->right = new_node(3);
    
    cout<<"Solution 2: "; display_in_order(root); cout<<endl ;
}

void solution3(){
    //c: by calling insert() three times passing it the root pointer to build up the tree
    NODE root = NULL;
    root = insert_rec(root, 2);
    root = insert_rec(root, 1);
    root = insert_rec(root, 3);
    
    cout<<"Solution 3: "; display_in_order(root); cout<<endl ;
}


NODE new_node(int data){
    NODE temp = new(struct node); //similar to malloc -> NODE temp = (NODE)malloc(sizeof(struct node))
    if(temp != NULL){
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
    }
    return temp;
}


void display_in_order(NODE root){
    if(root == NULL){
        return;
    }else{
        display_in_order(root->left);
        cout<< root->data<< ' '; //in -> go left, print then go right
        display_in_order(root->right);
    }
}


NODE insert_rec(NODE root, int data){
    if(root == NULL){
        NODE temp = new_node(data);
        return temp;
    }else{
        //recur down the tree
        if(data <= root->data)
            root->left = insert_rec(root->left, data);
        else
            root->right = insert_rec(root->right, data);

        //return (unchanged) root pointer
        return root ;
    }
}
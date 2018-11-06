#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdbool>

using namespace std;
typedef long long ll;

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
    int ele[] = {4,2,6,1,3,5,7};
    int ele_size = sizeof(ele)/sizeof(ele[0]);
    for(int i=0; i<ele_size; i++){
        root = insert_rec(root, ele[i]);
    }
    return root;
}

void print_inorder(NODE root){
    if(root == NULL){
        return;
    }else{
        print_inorder(root->left);
        cout<<root->data <<" ";
        print_inorder(root->right);
    }
}

void print_level_order(NODE root){
    if(root == NULL) return;
    queue<NODE> q;
    q.push(root);
    while(!q.empty()){
        NODE temp = q.front();
        cout<<temp->data<< " ";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

//link: https://www.youtube.com/watch?v=YsLko6sSKh8
void print_zig_zag(NODE root){
    if(root==NULL){
        return;
    }else{
        stack<NODE> s1;
        stack<NODE> s2;

        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){ //push children of popped node(left, then right) to s2
                NODE temp = s1.top();
                cout<< temp->data << " ";
                s1.pop();
                if(temp->left != NULL){
                    s2.push(temp->left);
                }
                if(temp->right != NULL){
                    s2.push(temp->right);
                }
            }

            while(!s2.empty()){ //push children of popped node(right, then left) to s1
                NODE temp = s2.top();
                cout << temp->data << " ";
                s2.pop();
                if(temp->right != NULL){
                    s1.push(temp->right);
                }
                if(temp->left != NULL){
                    s1.push(temp->left);
                }
            }
        }
    }    
}

int main(){
    NODE root = create_default_tree();
    print_inorder(root);
    cout<< endl;
    print_level_order(root);
    cout << endl;
    print_zig_zag(root);
    return 0;
}
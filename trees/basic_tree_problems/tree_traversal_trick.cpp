//iterative tree traversal
#include <iostream>
#include <vector>
#include <stack>
#include <utility> //pair, make_pair
#include <unordered_map>
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
    for(int i=0; i<n; i++){
        root = insert_rec(root, a[i]);
    }
    return root;
}

void print_inorder(NODE root){
    if(root == NULL) return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}
//NOTE: if you don't insert any pair in MAP, and will try to access it, it's initialised to zero
//eg: map<string, int> m;  m["hello"] will be zero. How?
//When do use [] operator with map, if value is not present, it adds it with zero.


//iterative traversal (inorder)
void traverse_trick(NODE root){
    if(root == NULL) return;
    //if inorder, states are as if recursive calls, 0-> dfs left, 1->print, 2->dfs right
    unordered_map<NODE, int> state_of_node; //maintains state of the node for traversal as if recursive
    stack<NODE> s;
   
    s.push(root);
    while(!s.empty()){
        if(s.top() != NULL){
            NODE curr = s.top();
            if(state_of_node[curr] == 0) s.push(curr->left);
            else if(state_of_node[curr] == 1) cout << curr->data << " ";
            else if(state_of_node[curr] == 2) s.push(curr->right);
            else s.pop(); //done with that node (state == 3)

            state_of_node[curr]++;
        }else{
            s.pop(); //NULL node
        }
    }
}

//again inorder
void traverse_trick2(NODE root){
    if(root == NULL) return;
    stack<pair<NODE, int> > s;
    s.push(make_pair(root, 0));
    while(!s.empty()){
        pair<NODE, int> p = s.top();
        NODE curr = p.first;
        int state = p.second;
        
        s.pop(); //pop this, as we will push it again with new_state
        if(curr == NULL || state >=3) continue;
        s.push(make_pair(curr, state + 1)); //increase state

        if(state == 0) s.push(make_pair(curr->left, 0));
        else if(state == 1) cout << curr->data << " ";
        else if(state == 2) s.push(make_pair(curr->right, 0));
    }
}


int main(){
    NODE root = create_default_tree();
    cout << "rec tree: "; print_inorder(root); cout << endl;
    cout << "itr tree: "; traverse_trick(root); cout << endl;
    cout << "itr tree: "; traverse_trick2(root); cout << endl;
    return 0;
}
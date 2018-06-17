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
NODE insert_rec(NODE, int);
NODE insert_itr(NODE, int);
void display_pre_order(NODE);  //root at first
void display_in_order(NODE);   //root at the middle
void display_post_order(NODE); //root at the end
NODE create_tree(NODE);
NODE create_default_tree(NODE);
bool lookup(NODE, int);


int main(){
    NODE root = NULL; //must
    root = create_default_tree(root);
    cout<<"Pre:  "; display_pre_order(root);  cout<< endl;
    cout<<"In:   "; display_in_order(root);   cout<< endl;
    cout<<"Post: "; display_post_order(root); cout<< endl;

    if(lookup(root , 5)){
        cout<<"Present\n";
    }
    if(!lookup(root , 100)){
        cout<<"Not present\n";
    }

    cout<<root->data <<endl;

    return 0;
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


NODE insert_itr(NODE root, int data){
    if(root == NULL){
        NODE temp = new_node(data);
        return temp;
    }else{
        NODE p = root;
        while(p != NULL){
            if(data <= p->data){
                if(p->left == NULL){
                    p->left = new_node(data);
                    break;
                }
                p = p->left;
            }else{
                if(p->right == NULL){
                    p->right = new_node(data);
                    break;
                }
                p = p->right;
            }
        }
    }
    return root;
}



void display_pre_order(NODE root){
    if(root == NULL){
        return;
    }else{
        cout<< root->data<< ' '; //pre -> first print
        display_pre_order(root->left);
        display_pre_order(root->right);
    }
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


void display_post_order(NODE root){
    if(root == NULL){
        return;
    }else{
        display_post_order(root->left);
        display_post_order(root->right);
        cout<< root->data<< ' '; //post ->print at the end
    }
}


NODE create_tree(NODE root){
    vector<int> elements;
    int n; cout<<"n(Nodes): "; cin>> n;
    for(int i=0; i<n; i++){
        int ele; cout<<"["<<i+1<<"]: "; cin>> ele;
        elements.push_back(ele);
    }

    for(int i=0; i< n; i++){
        root = insert_rec(root, elements[i]);
    }

    return root;
}


NODE create_default_tree(NODE root){
    int elements[] = {10,5,7,25,3,20,30,2,15,22};
    int elements_size = sizeof(elements)/sizeof(elements[0]);

    // vector<int> v_elements(begin(elements), end(elements));
    for(int i=0; i<elements_size; i++){
        root = insert_rec(root, elements[i]);
    }
    return root;
}


bool lookup(NODE root, int target){
    if(root == NULL){
        return false;
    }else{
        if(target == root->data){
            return true;
        }else if(target < root->data){
            return lookup(root->left, target); //we wrote RETURN, as lookup has a return type
        }else{
            return lookup(root->right, target) ;
        }
    }
}

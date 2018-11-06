//Goal: Faster than hashing, more flexible than BSTs.
//INCOMPLETE
#include <iostream>
#include <vector>
#include <cstdbool>
#include <string>
using namespace std;

struct node{
    char data;
    int value;
    bool isEndOfWord;
    struct node* left;
    struct node* eq;
    struct node* right;
};
typedef struct node* NODE;

NODE new_node(char data){
    NODE temp = new(struct node);
    temp->data = data;
    temp->isEndOfWord = false;
    temp->left = NULL;
    temp->eq = NULL;
    temp->right = NULL;
    return temp;
}

NODE insert(NODE root, string key, int value){
    NODE p = root; //used for traversing down the tst
    for(int i=0; i<key.length(); i++){ //for each char of word:
        if(root == NULL){
            root = new_node(key[0]);
            p = root;
        }else{
            if(key[i] < p->data){
                p->left = new_node(key[i]);
                p = p->left;
            }else if(key[i] > p->data){
                p->right = new_node(key[i]);
                p = p->right;
            }else{
                p->eq = new_node(key[i]);
                p = p->eq;
            }
        }
        if(i == key.length() - 1){
            p->value = value;
            p->isEndOfWord = true;
        } 
    }
    return root;
}

int get_value(NODE root, string key){
    if(root == NULL){
        cout << "Root is null.\n";
        return -1;
    }
    NODE p = root;
    int i = 0;
    while(i < key.length()){
        cout << p->data << " "; //CHECK

        if(p == NULL){
            return -1;
        }else if(i== key.length() - 1){
            if(p->isEndOfWord == true){
                cout << p->value << endl; //check
                return p->value;
            }else{
                return -1;
            }
        }else if(p->data == key[i]){
            p = p->eq;
        }else if(p->data < key[i]){
            p = p->left;
        }else{
            p = p->right;
        }
        i++;
    }
    return -1;
}

int main(){
    vector<string> s;
    s.push_back("cat");
    s.push_back("apple");
    s.push_back("car");

    NODE root = NULL;
    for(int i=0; i<s.size(); i++){
        root = insert(root, s[i], i+1);
    }

    cout << get_value(root, "cat") << endl;
    // cout << get_value(root, "prince") << endl;

    return 0;
}
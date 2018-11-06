#include <iostream>
#include <cstdbool>
#include <string>
#define ALPHABET_SIZE 26
using namespace std;

struct node{
    bool isEndofWord;
    struct node* children[ALPHABET_SIZE];
};
typedef struct node* NODE;


NODE new_node(){
    NODE temp = new(struct node);
    temp->isEndofWord = false;
    for(int i=0; i< ALPHABET_SIZE; i++){
        temp->children[i] = NULL;
    }
    return temp;
}

//Note: Root never changes. It doesn't follow tree-like-insert-elements. 
//Only path is there.
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(const NODE root, string key){
    NODE p = root; //will crawl through the trie.
    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if(p->children[index] == NULL){
            p->children[index] = new_node();
        }
        p = p->children[index];
    }
    p->isEndofWord = true; // mark last node as leaf
}

bool search(const NODE root, string key){
    NODE p = root;
    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if(p->children[index] == NULL){
            return false;
        }
        p = p->children[index];
    }
    return ((p != NULL) && (p->isEndofWord == true)); //check if leaf node exists and it marks the endofword flag
}

int main(){
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    NODE root = new_node(); //Note; in case of tree, we used to do, root = NULL; (not here)
    for(int i=0; i<n; i++){
        insert(root, keys[i]);
    }

    search(root, "the")? cout << "Yes\n" : cout << "No\n";
    search(root, "these")? cout << "Yes\n" : cout << "No\n";
    return 0;
}
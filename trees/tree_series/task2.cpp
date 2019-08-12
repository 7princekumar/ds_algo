// Given a binary tree, count the number of nodes in the tree.
//    2
//  /   \
// 1     3
#include <iostream>
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

void print_inorder(NODE root){
	if(root == NULL) return;
	print_inorder(root->left);
	cout << root->data << " ";
	print_inorder(root->right);
}

NODE create_default_tree(){
	NODE root = NULL;
	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(a[0]);
	for(int i=0; i<n; i++) {
		root = insert_rec(root, a[i]);
	}
	return root;
}

int sizeof_btree(NODE root){
	if(root == NULL) return 0;
	return 1 + sizeof_btree(root->left) + sizeof_btree(root->right);
}

int main(){
	NODE root = create_default_tree();
	print_inorder(root); cout << endl;
	cout << "Size of tree: " << sizeof_btree(root) << endl;
	return 0;
}
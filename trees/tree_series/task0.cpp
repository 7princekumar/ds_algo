//1. construct binary tree
//2. insert elements
//3. print it (in-order)

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
	cout << root->data << " |";
	print_inorder(root->right);
}

NODE create_default_tree(){
	int a[] = {1, 2, 3};
	int n = sizeof(a)/sizeof(a[0]);
	NODE root = NULL;
	for(int i=0; i< n; i++) {
		root = insert_rec(root, a[i]);
	}
	return root;
}

int main(){
	NODE root = create_default_tree();
	print_inorder(root);
	cout << endl;

	return 0;
}
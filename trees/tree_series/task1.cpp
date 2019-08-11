/*
     2
   /   \
  1		3
Write code that builds the following little 1-2-3 binary search tree...
a: by calling newNode() three times, and using three pointer variables
b: by calling newNode() three times, and using only one pointer variable
c: by calling insert() three times passing it the root pointer to build up the tree

a:   [1], [2], [3]
b:   [2] -> [1], [3]
c:  
*/

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

void print_inorder(NODE root){
	if(root == NULL) return;
	print_inorder(root->left);
	cout << root->data << " |";
	print_inorder(root->right);
}

void solution1(){
	//create nodes with 3 variables
	NODE node1 = new_node(1);
	NODE node2 = new_node(2); //becomes root
	NODE node3 = new_node(3);
	
	//connect them
	node2->left = node1;
	node2->right = node3;
	print_inorder(node2); cout << endl;
}

void solution2(){
	//create node
	NODE node2 = new_node(2);
	node2->left = new_node(1);
	node2->right = new_node(3);
	print_inorder(node2); cout << endl;
}


NODE insert_rec(NODE root, int data){
	if(root==NULL){
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

void solution3(){
	NODE root = NULL;
	root = insert_rec(root, 2);
	root = insert_rec(root, 1);
	root = insert_rec(root, 3);
	print_inorder(root); cout << endl;
}

int main(){
	solution1();
	solution2();
	solution3();
	return 0;
}
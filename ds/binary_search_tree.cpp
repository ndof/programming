#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;

class BinarySearchTree{
private:
	class Node{
		public:
			int data;
			Node *left, *right;
			Node(int d){
				data = d;
				left = right = NULL;
			}
	};
	Node *tree_root;
	void insert(Node *root,int data){
		if(tree_root == NULL){
			tree_root = new Node(data);
		}
		else{
			if(data < root->data){
				if( root->left == NULL ) root->left = new Node(data);
				else insert(root->left,data);
			}
			else if(data > root->data){
				if( root->right == NULL ) root->right = new Node(data);
				else insert(root->right,data);
			}
		}
	}
	void in_order(Node *root){
		if(root == NULL) return;
		in_order(root->left);
		cout << root->data << " ";
		in_order(root->right);
	}
	void pre_order(Node *root){
		if(root == NULL) return;
		cout << root->data << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
	void post_order(Node *root){
		if(root == NULL) return;
		post_order(root->left);
		post_order(root->right);
		cout << root->data << " ";
	}

public:
	BinarySearchTree(){ tree_root = NULL ;}
	void insert(int data){ insert(tree_root,data);}
	void in_order(){ cout << "inorder  : " ; in_order(tree_root); cout << endl ; }
	void pre_order(){ cout << "preorder : " ; pre_order(tree_root); cout << endl ; }
	void post_order(){ cout << "postorder : "  ; post_order(tree_root); cout << endl ; }
};



void test(){
	BinarySearchTree bst;
	bst.insert(4);
	bst.insert(1);
	bst.insert(5);
	bst.insert(2);
	bst.in_order();	
	bst.pre_order();
	bst.post_order();
}

int main(){
	test();
	return 0;
}

// C++ Program for the above approach
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		this->left = this->right = NULL;
	}
};

Node* newNode(int data){
	return new Node(data);
}

void storeInVector(Node* root, vector<int>&vec){
	if(root == NULL) return;
	storeInVector(root->left, vec);
	vec.push_back(root->data);
	storeInVector(root->right, vec);
}

void correctBSTUtil(Node* root, vector<int> &vec, int &index){
	if(root == NULL) return;
	correctBSTUtil(root->left, vec, index);
	root->data = vec[index];
	index++;
	correctBSTUtil(root->right, vec, index);
}

void correctBST(Node* root){
	// vector to store the inorder traversal of
	// given tree
	vector<int> vec;
	storeInVector(root, vec);
	sort(vec.begin(), vec.end());
	int index = 0;
	correctBSTUtil(root, vec, index);
}

void printInorder(Node* root){
	if(root == NULL) return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main(){
	/* 6
		/ \
	10 2
	/ \ / \
	1 3 7 12
	
	10 and 2 are swapped */
	struct Node *root = newNode(6);
	root->left = newNode(10);
	root->right = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(12);
	root->right->left = newNode(7);
	
	// Inorder traversal of the Original Tree
	cout <<"Inorder Traversal of the original tree \n";
	printInorder(root);

	correctBST(root);
	
	// inorder traversal of the fixed tree
	cout <<"\nInorder Traversal of the fixed tree \n";
	printInorder(root);

	return 0;
}
// THIS CODE IS CONTRIBUTED BY YASH AGARWAL(YASHAGARWAL2852002)

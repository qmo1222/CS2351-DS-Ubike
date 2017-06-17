#include "BikeTree.h"
#include <stdio.h>

string printInorder(Node *parent){
	string ans;
	if(parent->left!=NULL)
		ans += printInorder(parent->left);
	ans += parent->bike->license + "->" ;
	if(parent->right!=NULL)
		ans += printInorder(parent->right);
	return ans;
}

string printPreorder(Node *parent){
	string ans;
	
	ans += parent->bike->license + "->" ;
	if(parent->left!=NULL)
		ans += printPreorder(parent->left) ;
	if(parent->right!=NULL)
		ans += printPreorder(parent->right);
	return ans;
}

Node *Predecessor(Node *root){		//return the largest in left subtree
	Node *tmp=root;					//and remove the node from the tree
	Node *parent;
	if(tmp->right!=NULL){
		for(;tmp->right!=NULL; tmp=tmp->right){
			parent = tmp;
		}
		parent->right = tmp->left;
		return tmp;
	}
	else{
		root=root->left;
		return tmp;
	}
}

void BikeTree::addBike(Bike *bike){
	if(root==NULL){
		root = new Node();
		root->bike=bike;
		root->left=NULL;
		root->right=NULL;
	}
	else{
		Node *tmp=root;
		while(tmp!=NULL){

			if(tmp->bike->license == bike->license){
				printf("this license already exists\n");
				return;
			}

			if(bike->license > tmp->bike->license){		//bigger than root => go right
				if(tmp->right!=NULL){
					tmp=tmp->right;	
				}
				else {
					tmp->right = new Node();
					tmp->right->bike = bike;
					tmp = tmp->right;
					tmp->left=NULL;
					tmp->right=NULL;
					tmp = tmp->right;
				}
			}
			else if(bike->license < tmp->bike->license){
				if(tmp->left!=NULL){
					tmp=tmp->left;	
				}
				else {
					tmp->left = new Node();
					tmp->left->bike = bike;
					tmp = tmp->left;
					tmp->left=NULL;
					tmp->right=NULL;
					tmp = tmp->right;
				}
			}
		}
	}
}

void BikeTree::junkBike(string license){
	Node *tmp=root;
	Node *parent;
	Node *Prede;
	if(root->bike->license == license){
		if(root->left == NULL){
			if(root->right != NULL){
				root = root->right;
			}
			else root=NULL;
		}
		else if(root->left != NULL){
			printf("left!\n");
			Prede = Predecessor(root->left);
			Prede->left = root->left;
			Prede->right = root->right;
			root = Prede;
			printf("%c\n",root->bike->license[0]);
		}
		return;
	}
	while(tmp!=NULL){
		if(license > tmp->bike->license){		//bigger than root => go right
			if(tmp->right!=NULL){

				if(tmp->right->bike->license == license){
					parent = tmp;
					tmp=tmp->right;
					if(tmp->left == NULL){
						if(tmp->right != NULL){
							parent->right = tmp->right;
						}
						else parent->right=NULL;
					}
					else if(tmp->left != NULL){
						Prede = Predecessor(tmp->left);
						Prede->left = tmp->left;
						Prede->right = tmp->right;
						parent->right = Prede;
					}
					return;
				}
				else tmp=tmp->right;
			}
			else {
				printf("this license doesn't exists when junking\n");
				return;
			}
		}
		else if(license < tmp->bike->license){
			if(tmp->left!=NULL){

				if(tmp->left->bike->license == license){
					parent = tmp;
					tmp=tmp->left;
					if(tmp->left == NULL){
						if(tmp->right != NULL){
							parent->right = tmp->right;
						}
						else parent->right=NULL;
					}
					else if(tmp->left != NULL){
						Prede = Predecessor(tmp->left);
						Prede->left = tmp->left;
						Prede->right = tmp->right;
						parent->left = Prede;
					}
					return;
				}
				else tmp=tmp->left;
			}
			else {
				printf("this license doesn't exists\n");
				return;
			}
		}
	}
}

Bike* BikeTree::searchBike(string license){
	Node *tmp=root;
	while(tmp!=NULL){

		if(tmp->bike->license == license){
			return tmp->bike;
		}

		if(license > tmp->bike->license){		//bigger than root => go right
			if(tmp->right!=NULL){
				tmp=tmp->right;	
			}
			else {
				printf("this license doesn't exists\n");
				return NULL;
			}
		}
		else if(license < tmp->bike->license){
			if(tmp->left!=NULL){
				tmp=tmp->left;	
			}
			else {
				printf("this license doesn't exists\n");
				return NULL;
			}
		}
	}
	return NULL;
}

string BikeTree::inorder(){
	if(root!=NULL){
		string ansBefore=printInorder(root);
		string ans = ansBefore.substr(0,ansBefore.length()-2);
		return ans;
	}	
	else return "no bike (inorder)";
}

string BikeTree::preorder(){
	if(root!=NULL){
		string ansBefore=printPreorder(root);
		string ans = ansBefore.substr(0,ansBefore.length()-2);
		return ans;
	}	
	else return "no bike (preorder)";
}




#include "BikeTree.h"

using namespace std;
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

Node *predecessor(Node *root){		//return the largest in left subtree
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
		// root=root->left;
		return root;
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
	Node *prede;
	if(root->bike->license == license){
		if(root->left == NULL){
			if(root->right != NULL){
				root = root->right;
			}
			else root=NULL;
		}
		else if(root->left != NULL){
			prede = predecessor(root->left);
			prede->left = root->left;
			prede->right = root->right;
			root = prede;
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
						prede = predecessor(tmp->left);
						if(prede == tmp->left){
							prede->right = tmp->right;
							parent->right = prede;
						}
						else{
							prede->left = tmp->left;
							prede->right = tmp->right;
							parent->right = prede;		
						}
					}
					return;
				}
				else tmp=tmp->right;
			}
			else {
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
							parent->left = tmp->right;
						}
						else parent->left=NULL;
					}
					else if(tmp->left != NULL){
						prede = predecessor(tmp->left);
						if(prede == tmp->left){
							prede->right = tmp->right;
							parent->left = prede;
						}
						else{
							prede->left = tmp->left;
							prede->right = tmp->right;
							parent->left = prede;		
						}
					}
					return;
				}
				else tmp=tmp->left;
			}
			else {
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
		else if(license > tmp->bike->license){		//bigger than root => go right
			if(tmp->right!=NULL){
				tmp=tmp->right;	
			}
			else {
				return NULL;
			}
		}
		else if(license < tmp->bike->license){
			if(tmp->left!=NULL){
				tmp=tmp->left;	
			}
			else {
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




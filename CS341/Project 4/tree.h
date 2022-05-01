#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
#include "treenode.h"

template<typename NODETYPE> class Tree {
	private:
		TreeNode<NODETYPE> * root;
		
		typedef TreeNode<NODETYPE> * TreeNodePtr;
	
		// Helper functions
		void insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value);
		TreeNodePtr deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value);		
		
		void preOrderHelper(TreeNodePtr curr) const;
		void inOrderHelper(TreeNodePtr curr) const;
		void postOrderHelper(TreeNodePtr curr) const;
		void depthHelper(TreeNodePtr curr, int & total, int current) const;

        /*
        **********
        // Red/Black recoloring helper functions
        void doubleBlack(TreeNodePtr x);
		**********
        */
        
	public:
		// Class setup
		Tree() { root = NULL; }
		~Tree();
		
		// Core functionality
		void insertNode(const NODETYPE & value) { insertNodeHelper(root, value); }
		void deleteNode(const NODETYPE & value) { deleteNodeHelper(root, value); }
		void preOrder() const { preOrderHelper(root); }
		void inOrder() const { inOrderHelper(root); }
		void postOrder() const { postOrderHelper(root); }
		int depth() const {
			int total = 0, current = 0;
			depthHelper(root, total, current);
			return total;
		} // end function depth()
		void leftRotate(TreeNodePtr x);
	    void rightRotate(TreeNodePtr y);
		void recolor(TreeNodePtr k);
		void recolorpt2(TreeNodePtr k);
		//void leftRotate();
        
}; // end class Tree

template<typename NODETYPE>
Tree<NODETYPE>::~Tree() {
	while (root != NULL)
		deleteNode(root->data);
} // end destructor

template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
	// If the subtree is empty, then we have found our new nesting place.
	// This is the base case, so let's create the new node.
	//cout << 1 << endl;
	if (curr == NULL) {
		//cout << 2 << endl;
		curr = new TreeNode<NODETYPE>(value);
		//recolor(curr);
		//cout << 3 << endl;
		if(curr == root)
			recolor(curr);
		return;
	}
	if (value <= curr->data){
		//cout << 4 << endl;
		insertNodeHelper(curr->left, value);
		if(curr->left->data == value){
            curr->left->parent = curr;
			recolor(curr->left);
			//cout << 9 << endl;
		}
    }
	else{
		//cout << 5 << endl;
		insertNodeHelper(curr->right, value);
		if(curr->right->data == value){
            curr->right->parent = curr;
			recolor(curr->right);
			//cout << 10 << endl;
			//preOrder();
		}
	}
} // end insertNodeHelper

template<typename NODETYPE> //true = black, false = red
void Tree<NODETYPE>::recolor(TreeNodePtr k){
	cout << "Current K Value: " << k->data << endl;
	//cout << 6 << endl;
	if (k == root){
		k->color = true;
		//cout << 7 << endl;
	}
	else if(k->parent->color){
		//cout << 8 << endl;
		return;//drink heavily
	}
	else{
		cout << "big else" << endl;
		if(k->parent->parent->left!=nullptr && k->parent->parent->right!=nullptr){
			if(!(k->parent->parent->left->color) && !(k->parent->parent->right->color)){ //3.1
				cout << "3.1" << endl;
				//cout << "Here as well" << endl;
				k->parent->parent->left->color = true; //black
				k->parent->parent->right->color = true; //black
				//cout << "Almost at the end" << endl; 
				if(k->parent->parent != root)
					k->parent->parent->color = false; //red
				recolor(k->parent->parent);
				//cout << "You Did IT :D" << endl;
				return;
			}
		}
		recolorpt2(k);
	}
}

template<typename NODETYPE> //true = black, false = red
void Tree<NODETYPE>::recolorpt2(TreeNodePtr k){
	if(k->parent->parent->right == k->parent && k->parent->right == k){ //3.2.1
		cout << "3.2.1" << endl;
		cout << "k par: " << k->parent->data << " G pappy: " << k->parent->parent->data << endl; 
		leftRotate(k->parent->parent);
		//cout << 6 << endl;
		k->parent->left->color = false;
		//cout << 7 << endl;
		k->parent->color = true;
		//cout << 8 << endl;
	}
	else if(k->parent->parent->right == k->parent && k->parent->left == k){ //3.2.2
			cout << "3.2.2" << endl;
			rightRotate(k->parent);
			cout << "3.2.2 right: " << k->right->data << endl;
			recolor(k->right);
	}
	else if(k->parent->parent->left == k->parent && k->parent->left == k){ //3.2.3
			cout << "3.2.3" << endl;
			rightRotate(k->parent->parent);
			k->parent->right->color = false;
			k->parent->color = true;
	}
	else if(k->parent->parent->left == k->parent && k->parent->right == k){ //3.2.4
			cout << "3.2.4" << endl;
			leftRotate(k->parent);
			recolor(k->left);
	}
}

template<typename NODETYPE>
TreeNode<NODETYPE> * Tree<NODETYPE>::deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
	// If the subtree is empty, quit
	if (curr == NULL)
		return curr;
	else if (value < curr->data)
		curr->left = deleteNodeHelper(curr->left, value);
	else if (value > curr->data)
		curr->right = deleteNodeHelper(curr->right, value);
	else {
		// We know that curr->data == value, so we're ready to delete
		
		// Let's call the "node to be deleted" . . . . doomed
		// Case 1: (doomed has no children)
		if ((curr->left == NULL) && (curr->right == NULL)) {
			delete curr;
			curr = NULL;
		} // end case 1 if
		
		// Case 2: (doomed has one child)
		else if (curr->left == NULL) {
			TreeNodePtr temp = curr;
			curr = curr->right;
			delete temp;
		} // end case 2a if
		else if (curr->right == NULL) {
			TreeNodePtr temp = curr;
			curr = curr->left;
			delete temp;
		} // end case 2b if
		
		// Case 3: (doomed has two children)
		else {
			// Find the smallest element on the right side of the tree.
			TreeNodePtr smallestRight = curr->right;
			while (smallestRight->left != NULL)
				smallestRight = smallestRight->left;
			
            // Notice that you actually only ever delete a node with 0 or 1 child from the tree.
            // Nodes with two children are too big to fail.
			curr->data = smallestRight->data;
			curr->right = deleteNodeHelper(curr->right, smallestRight->data);
		} // end case 3
	} // end outside else

	return curr;
}	

template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
    cout << "Data: " << curr->data;
	if(curr!= root)
		cout << " Parent:" << curr->parent->data; 
	if(curr->color)
		cout << " color: Black";
	else
		cout << " color: Red";
	cout<< endl;
	//cout << curr->data << ' ';		// process the node
	preOrderHelper(curr->left);		// traverse the left subtree
	preOrderHelper(curr->right);		// traverse the right subtree
} // end preOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	inOrderHelper(curr->left);		// traverse the left subtree
	cout << curr->data << ' ';		// process the node
	inOrderHelper(curr->right);		// traverse the right subtree
} // end inOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	postOrderHelper(curr->left);		// traverse the left subtree
	postOrderHelper(curr->right);		// traverse the right subtree
	cout << curr->data << ' ';			// process the node
} // end postOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::depthHelper(TreeNodePtr curr, int & total, int current) const {
	// if tree is empty, quit
	if (curr == NULL)
		return;
	current++;
	
	// Update total if it's bigger.
	if (current > total)
		total = current;
	depthHelper(curr->left, total, current);
	depthHelper(curr->right, total, current);
} // end depthHelper

template<typename NODETYPE>
void Tree<NODETYPE>::leftRotate(TreeNodePtr x){
	//if (x == root)
		//return;
	//cout << "left Rotate Begin" << endl;
	if (x->right == nullptr)
		return;
	//cout << 1 << endl;
	TreeNodePtr y = x->right;
	x->right = y->left;
	//cout << 2 << endl;
	if (y->left != nullptr)
		y->left->parent = x;
	//y->parent = x->parent;
	//cout << 3 << endl;
	if(x == root){
		root = y;
		y->parent = nullptr;
		//cout << "Change Root"<< endl;
		//cout << root->data << endl;
	}
	else if(x->parent->left == x){
		y->parent = x->parent;
		x->parent->left = y;
	}
	else{
		x->parent->right = y;
		y->parent = x->parent;
	}
	//cout << 4 << endl;
	y->left = x;
	x->parent = y;
	//cout << 5 << endl;
}

template<typename NODETYPE>
void Tree<NODETYPE>::rightRotate(TreeNodePtr y){
	cout << "Right Rotate Begin" << endl;
	if (y->left == nullptr)
		return;
	TreeNodePtr x = y->left;
	y->left = x->right;
	if (x->right != nullptr)
		x->right->parent = y;
	x->parent = y->parent;
	if(y->parent == nullptr)
		root = x;
	else if(y->parent->right == y)
		y->parent->right = x;
	else
		y->parent->left = x;
	x->right = y;
	y->parent = x;
}

#endif
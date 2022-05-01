#ifendef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
#include "treenode.h"

template typename<NODETYPE> class TREE{
	private:
		TreeNode<NODETYPE> * root;
		
		void insertNodeHelper(TreeNode<NODETYPE> ** cur, const NODETYPE & value);
		void preOrderHelper(TreeNode<NODETYPE> * cur) const;
		void inOrderHelper(TreeNode<NODETYPE> * cur) const;
		void postOrderHelper(TreeNode<NODETYPE> * cur) const;
	public:
		Tree();
		~Tree();
		
		
		void insertNode(const NODETYPE & value){insertNodeHelper(&root, value)
		void preOrder() const {preOrderHelper(root);}
		void inOrder() const {inOrderHelper(root);}
		void postOrder() const{postOrderHelper(root);}

};

template typename<NODETYPE> 
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE> * cur) const{
	if(cur == NULL)
		return; 
	cout << cur->data << " ";
	preOrderHelper(cur->lPtr);
	preOrderHelper(cur->rPtr);	
}

template typename<NODETYPE> 
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE> * cur) const{
	if(cur == NULL)
		return; 
	inOrderHelper(cur->lPtr);
	cout << cur->data << " ";
	inOrderHelper(cur->rPtr);	
}

template typename<NODETYPE> 
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE> * cur) const{
	if(cur == NULL)
		return; 
	postOrderHelper(cur->lPtr);
	postOrderHelper(cur->rPtr);	
	cout << cur->data << " ";
}

template typename<NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE> ** cur, const NODETYPE & value){
	if(*cur == NULL){
		*cur = new TreeNode<NODETYPE>(value);
		return;
	}
	if (value <= (*cur)->data)
		insertNodeHelper(&((*cur)->lPtr),value
	else
		insertNodeHelper(&((*cur)->rPtr),value)	
}

#endif
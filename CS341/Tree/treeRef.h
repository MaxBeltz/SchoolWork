#ifendef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
#include "treenode.h"

template typename<NODETYPE> class TREE{
	private:
		TreeNode<NODETYPE> * root;
		
		typedef TreeNode<NODETYPE> * TreeNodePtr;
		
		void insertNodeHelper(TreeNodePtr & cur, const NODETYPE & value);
		TreeNodePtr deleteNodeHelper(TreeNodePtr & cur, const NODETYPE & value);
		
		void preOrderHelper(TreeNode<NODETYPE> * cur) const;
		void inOrderHelper(TreeNode<NODETYPE> * cur) const;
		void postOrderHelper(TreeNode<NODETYPE> * cur) const;
		void depthHelper(TreeNodePtr, int & total, int current) const;
	public:
		Tree();
		~Tree();
		
		
		void insertNode(const NODETYPE & value){insertNodeHelper(root, value);}
		void deleteNode(const NODETYPE & value){insertNodeHelper(root, value);}
		
		void preOrder() const {preOrderHelper(root);}
		void inOrder() const {inOrderHelper(root);}
		void postOrder() const{postOrderHelper(root);}
		int depth() const {
			int total = 0;
			int current = 0;
			depthHelper(root, total, current);
			return total;
			}

};

template typename<NODETYPE> 
Tree<NODETYPE>::~Tree(){
	while(root != NULL)
		deleteNode(root->data);

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
void Tree<NODETYPE>::insertNodeHelper(TreeNodePtr & cur, const NODETYPE & value){
	if(cur == NULL){
		cur = new TreeNode<NODETYPE>(value);
		return;
	}
	if (value <= cur->data)
		insertNodeHelper(cur->lPtr,value);
	else
		insertNodeHelper(cur->rPtr,value);	
}

TreeNodePtr Tree<NODETYPE>::deleteNodeHelper(TreeNodePtr & cur, const NODETYPE & value){
	if(cur == NULL)
		return cur;
	else if(value < curr->data)
		cur->lptr = deleteNodeHelper(cur->lptr, value);
	else if(value > curr->data)
		cur->rptr = deleteNodeHelper(cur->rptr, value);
	else{
		if(cur->lptr == NULL && cur->rptr == NULL){
			delete cur;
			cur = NULL;
		}
		else if(cur->lptr == NULL){
			TreeNodePtr temp = cur;
			cur = cur->rptr;
			delete temp;
		}
		else if(cur->rptr == NULL){
			TreeNodePtr temp = cur;
			cur = cur->lptr;
			delete temp;
		}
		else {
			TreeNodePtr smallestRight = cur->rptr;
			while(smallestRight->lptr != NULL)
				smallestRight = smallestRight->lptr;
			cur->data = smallestRight->data;
			cur->rptr = deleteNodeHelper(cur->rPtr, smallestRight->data);
		}
	}
	return cur
}

template typename<NODETYPE>
void Tree<NODETYPE>::depthHelper(TreeNodePtr cur, int & total, int current) const {
	if (curr = Null)
		return;
	current++;
	if(current > total)
		total = current;
	
	depthHelper(cur->lptr, total, current);
	depthHelper(cur->rptr, total, current);
}
#endif
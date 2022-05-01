#ifndef TREENODE_H
#define TREENODE_H

template<typename NODETYPE> class Tree;

template<typename NODETYPE> 
class TreeNode{
	friend class Tree<NODETYPE>;
	private:
		TreeNode<NODETYPE> * lPtr;
		TreeNode<NODETYPE> * rPtr;
		NODETYPE data;
	public: 
		TreeNode(const NODETYPE & d) : lPtr(NULL), rPtr(NULL), data(d){}
		
		NODETYPE getData() const {return data;};


#endif
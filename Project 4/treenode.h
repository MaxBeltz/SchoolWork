#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of a class Tree
template<typename NODETYPE> class Tree;

template<typename NODETYPE>
class TreeNode {
	friend class Tree<NODETYPE>;

	private:
		TreeNode<NODETYPE> * left;
		TreeNode<NODETYPE> * right;
        TreeNode<NODETYPE> * parent;
		NODETYPE data;
        bool color; //black = true, red = false

		
	public:
		// Class setup
		TreeNode(const NODETYPE & d) : left(nullptr), right(nullptr), parent(nullptr), data(d), color(false){}
		
		// Access function
		NODETYPE getData() const {return data;}
}; // end class TreeNode

#endif
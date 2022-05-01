#include <iostream>
#include <iomanip>
using namespace std;	// Ryan ** hi
#include "tree.h"

int main() {
	Tree<int> intTree;
	//int insertVal[10] = {50, 25, 75, 12, 33, 67, 88, 6, 13, 68};
	int insertVal[12] = {61, 52, 85, 93, 100, 115, 90, 18, 13, 68, 86, 1};
	//int insertVal[5] = {61, 52, 85, 93, 87};
	//int insertVal[12] = {50, 25, 78, 10, 35, 65, 90, 5, 15, 30, 40, 59, 75, 85, 100, 57, 60, 70, 76, 79, };
	
	for (int x = 1; x > -12; x--){
		intTree.insertNode(x);
		cout << "Preorder: ";
		intTree.preOrder();
		cout << endl << endl;
	}
	
	cout << "Preorder: ";
	intTree.preOrder();
	cout << endl;
	

	/*cout << "Inorder: ";
	intTree.inOrder();
	cout << endl;
	
	cout << "Postorder: ";
	intTree.postOrder();
	cout << endl;
	
	cout << intTree.depth() << endl; */
	
	return 0;
}
#include <iostream>
#include "tree.hxx"

using namespace ds::tree;

int main(void)
{
	Tree<int> treeObj;	// root becomes NULL
	treeObj.add(1);
	treeObj.add(0);
	treeObj.add(2);
	treeObj.add(3);
	std::cout << std::endl;
	treeObj.preorder();
	std::cout << std::endl;
	treeObj.inorder();
	std::cout << std::endl;
	treeObj.postorder();
	std::cout << std::endl;
	return 0;
}

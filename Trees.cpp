#include <iostream>
#include "Trees.h"

int main() {
	BTNode* root = new BTNode;
	root->data = 10;
	root->left = root->right = nullptr;
	Insert(root, 20);
	Insert(root, 30);
	Insert(root, 40);
	Insert(root, 50);
	Insert(root, 60);
	Insert(root, 70);
	//InOrder(root);
	PreOrderIterative(root);
	std::cout << "\n";

	//std::cout << FindHeightWithoutRecursion(root) << "\n";
	//verticalPrintBinaryTree(root);
	//FindMirror(root);
	//PreOrderIterative(root);
	//std::cout << (FindLCA(root, root->left->left, root->left->right))->data << std::endl;
}
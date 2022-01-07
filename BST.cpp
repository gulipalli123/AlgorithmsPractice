#include "BST.h"
#include <vector>

int main() {
	BSTNode* root = nullptr;;

	root = InsertinBST(root, 6);
	root = InsertinBST(root, 8);
	root = InsertinBST(root, 2);
	root = InsertinBST(root, 1);
	root = InsertinBST(root, 3);
	root = InsertinBST(root, 4);

	InorderBST(root);

	root = InsertinBST(root, 5);
	std::cout << "\n";
	InorderBST(root);
	root = DeleteANode(root, 3);
	std::cout << "\n";
	InorderBST(root);
	root = DeleteANode(root, 1);
	std::cout << "\n";
	InorderBST(root);


	std::cout << "vector print\n";
	std::vector<std::vector<int>> vec(10, std::vector<int>(10));
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			vec[i][j] = i + j;
			std::cout << vec[i][j] << " ";
		}

	vector<int> test{ 100, -4, 200,-1, 3,2, 0, 1 };

	std::cout << "lognest consucutive \n";
	int res = longestConsecutive(test);
	std::cout << "result = " << res << "\n";

}


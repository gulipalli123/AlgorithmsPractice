// BinarySearchTr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

struct BST
{
	int data;
	BST* left;
	BST* right;
};

BST* createNode(int data)
{
	BST* node = new BST;
	node->data = data;
	node->left = node->right = nullptr;
	return node;
}
BST* FindAnElement(BST* root, int data)
{
	if (root == nullptr)
		return nullptr;
	if (root->data == data)
		return root;
	else if (data < root->data)
		return FindAnElement(root->left, data);
	else
		return FindAnElement(root->right, data);
}
BST* FindMin(BST* root)
{
	if (root == nullptr)
		return nullptr;
	if (root->left == nullptr)
		return root;
	else
		return FindMin(root->left);
}

BST* FindMax(BST* root)
{
	if (root == nullptr)
		return nullptr;
	if (root->right == nullptr)
		return root;
	else
		return FindMax(root->right);
}
BST* InorderPredecessor(BST* root, int data)
{
	struct BST* node = FindAnElement(root, data);
	if (node == nullptr || node->left == nullptr)
		return nullptr;
	else
		return FindMax(node->left);
}

BST* InorderSuccessor(BST* root, int data)
{
	struct BST* node = FindAnElement(root, data);
	if (node == nullptr || node->right == nullptr)
		return nullptr;
	else
		return FindMin(node->right);
}

BST* InsertAnElement(BST* root, int data)
{
	if (root == nullptr)
	{
		root = createNode(data);
	}
	if (data < root->data)
		root->left = InsertAnElement(root->left, data);
	else if (data > root->data)
		root->right = InsertAnElement(root->right, data);
	return root;
}
void inorderTraversal(BST* root)
{
	if (root == nullptr)
		return;
	inorderTraversal(root->left);
	std::cout << root->data << " ";
	inorderTraversal(root->right);
}

BST* deleteHelper2(BST* root)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		delete root;
		return nullptr;
	}
	else if (root->left == nullptr)
	{
		BST* temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == nullptr)
	{
		BST* temp = root->left;
		delete root;
		return temp;
	}
	return nullptr;
}

BST* deleteHelper(BST* root, int& max)
{
	if (root == nullptr)
		return nullptr;
	if (root->right == nullptr)
	{
		max = root->data;
		root = deleteHelper2(root);
	}
	else
		root->right = deleteHelper(root->right, max);
	return root;
}

BST* deleteANode(BST* root, int data)
{
	if (root == nullptr)
		std::cout << "element is not present in the BST\n";
	else if (data < root->data)
		root->left = deleteANode(root->left, data);
	else if (data > root->data)
		root->right = deleteANode(root->right, data);
	else
	{
		if (root->left && root->right)
		{
			int max = 0;
			root->left = deleteHelper(root->left, max);
			root->data = max;
		}
		else
			root = deleteHelper2(root);
	}
	return root;
}

BST* findTheLowestCommonAncestor(BST* root, BST* node1, BST* node2)
{
	if (node1->data < root->data && root->data < node2->data)
		return root;
	else if (node1->data < root->data && node2->data < root->data)
	root->left = findTheLowestCommonAncestor(root->left, node1, node2);
	else
	root->right = findTheLowestCommonAncestor(root->right, node1, node2);
	return nullptr;
}

//Iterator version
BST* findLCA(BST* root, BST* node1, BST* node2)
{
	while (true)
	{
		if ((node1->data < root->data && root->data < node2->data) || (node1->data > root->data&& node2->data < root->data))
			return root;
		else if (node1->data < root->data)
			root = root->left;
		else
			root = root->right;
	}
}
int findDistanceFromRoot(BST* root, int key, std::vector<int>& path)
{
	//int left, right;
	if (root == nullptr)
		return 0;
	path.push_back(root->data);
	if (key == root->data)
		return 0;
	if (key < root->data)
		return findDistanceFromRoot(root->left, key, path) + 1;
	else if (key > root->data)
		return findDistanceFromRoot(root->right, key, path) + 1;
	return 0;
}


int findDistanceBetweenTwoNodes(BST* root, int key1, int key2)
{
	if (root == nullptr || key1 == root->data || key2 == root->data)
		return 0;
	if (key1 < root->data && key2 < root->data)
		return findDistanceBetweenTwoNodes(root->left, key1, key2);
	else if (key1 > root->data&& key2 > root->data)
		return findDistanceBetweenTwoNodes(root->right, key1, key2);
	else
	{
		std::vector<int> path1{}, path2{};
		int distance;
		distance = findDistanceFromRoot(root, key1, path1) + findDistanceFromRoot(root, key2, path2);
		//std::reverse_iterator<std::vector<int>> ritr;
		for (auto ritr = path1.rbegin(); ritr != path1.rend(); ritr++)
		{
			std::cout << *ritr << " ";
		}
		//std::cout << "\n";
		for (auto i : path2)
		{
			if (i == root->data)
				continue;
			std::cout << i << " ";
		}
		std::cout << "\n";
		return distance;
	}

}
bool IsBST(BST* root)
{
	if (root == nullptr)
		return true;
	if (root->left != nullptr && root->left->data > root->data)
		return false;
	if (root->right != nullptr && root->right->data < root->data)
		return false;
	return IsBST(root->left) && IsBST(root->right);
}

bool IsBSTUsingInorderTraversal(BST* root, int& prev)
{
	//prev = INT16_MIN;
	bool left = false;
	if (!root)
		return true;
	if (root->left)
		left = IsBSTUsingInorderTraversal(root->left, prev);
	if (root->data < prev)
		return false;
	prev = root->data;
	return IsBSTUsingInorderTraversal(root->right, prev);
}

//Two nodes of a BST are swapped, correct it
void swapBSTNodes(BST** root, BST** prev, BST**left, BST** right)
{
	if (root == nullptr)
		return;
	swapBSTNodes(&((*root)->left), prev, left, right);
	if ((*prev)->data > (*root)->data)
	{
		if(!left)
			left = prev;
		else if(!right)
		{
			right = prev;
		}

	}
	prev = root;
	swapBSTNodes(&((*root)->right), prev, left, right);
	
}
void find2ndLargest(BST* root, int& count)
{
	if (root == NULL)
		return;
	find2ndLargest(root->right, count);
	count++;
	if (count == 2)
	{
		std::cout << "2nd largest = " << root->data << "\n";
		return;
	}
	find2ndLargest(root->left, count);
}

int main()
{
	//Driver program
	BST* root = new BST;
	root->data = 10;
	root->left = new BST;
	root->left->data = 8;

	root->left->left = new BST;
	root->left->left->data = 6;
	root->left->left->left = nullptr;
	root->left->left->right = nullptr;

	root->left->right = new BST;
	root->left->right->data = 9;
	root->left->right->left = nullptr;
	root->left->right->right = nullptr;

	root->right = new BST;
	root->right->data = 12;

	root->right->left = new BST;
	root->right->left->data = 11;
	root->right->left->left = nullptr;
	root->right->left->right = nullptr;

	root->right->right = new BST;
	root->right->right->data = 13;
	root->right->right->left = nullptr;
	root->right->right->right = nullptr;
	struct BST* inorder_pred = InorderPredecessor(root, 10);
	std::cout << "Inorder Predecessor of 10 = " << inorder_pred->data << std::endl;
	struct BST* inorder_succ = InorderSuccessor(root, 10);
	std::cout << "Inorder Successor of 10 = " << inorder_succ->data << std::endl;
	inorderTraversal(root);
	std::cout << "\n";
	root = InsertAnElement(root, 7);
	inorderTraversal(root);
	std::cout << "\n";
	//std::cout << "root = " << root->data << "\n";
	//std::cout << "node = " << root->left->left->right->data << "\n";
	//root = deleteANode(root, 8);
	//inorderTraversal(root);
	//std::cout << "\n";
	BST* lca = findTheLowestCommonAncestor(root, root->left->left, root->right->left);
	std::cout << "lca = " << lca->data << "\n";
	BST* lca2 = findLCA(root, root->left->left->right, root->left->right);
	std::cout << "lca = " << lca2->data << "\n";
	//std::cout << "distance = " << findDistanceFromRoot(root, 6) << "\n";
	std::cout << "distance between 2 nodes = " << findDistanceBetweenTwoNodes(root, 7, 13) << "\n";
	//Insert a non BST node to make the tree nonBST
	/*root->right->right->right = new BST;
	root->right->right->right->data = 1;
	root->right->right->right->left = nullptr;
	root->right->right->right->right = nullptr;*/

	//auto prev = INT_MIN;
	//std::cout << IsBSTUsingInorderTraversal(root, prev) << std::endl;

	/*BST* left = nullptr;
	BST* right = nullptr;
	BST* prev = createNode(INT16_MIN);
	swapBSTNodes(&root, &prev, &left, &right);
	int temp = left->data;
	left->data = right->data;
	right->data = temp;*/

	BST* new_root = createNode(40);
	new_root = InsertAnElement(new_root, 35);
	new_root = InsertAnElement(new_root, 30);
	new_root = InsertAnElement(new_root, 39);
	int x = 0;
	find2ndLargest(new_root, x);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

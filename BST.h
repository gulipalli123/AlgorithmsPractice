
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
};

//Insert an Element in Binary Search Tree
BSTNode* InsertinBST(BSTNode* root, int data) {
	BSTNode* temp = new BSTNode;
	temp->data = data;
	temp->left = temp->right = nullptr;

	if (root == nullptr) {
		root = temp;
		return root;
	}

	if (data < root->data)
		root->left = InsertinBST(root->left, data);
	if (data > root->data)
		root->right = InsertinBST(root->right, data);
	return root;
}

void InorderBST(BSTNode* root) {
	if (root) {
		InorderBST(root->left);
		std::cout << root->data << " ";
		InorderBST(root->right);
	}
}

BSTNode* FindMax(BSTNode* root) {
	if (nullptr == root)
		return root;
	if (root->left == nullptr && root->right == nullptr)
		return root;
		root = FindMax(root->right);

}
BSTNode* DeleteANode(BSTNode* root, int data) {
	if (root == nullptr)
		std::cout << "element not found\n";
	else if (data < root->data)
		root->left = DeleteANode(root->left, data);
	else if (data > root->data)
		root->right = DeleteANode(root->right, data);
	else {
		// element found
		// both the child are present
		BSTNode* temp;
		if (root->left && root->right) {
			temp = FindMax(root->left);
			root->data = temp->data;
			root->left = DeleteANode(root->left, temp->data);
		}
		else {
			temp = root;
			if (nullptr == root->left)
				root = root->right;
			else if (nullptr == root->right)
				root = root->left;
			delete temp;
		}
	}
	return root;
}

BSTNode* FindLCA(BSTNode* root, int first, int second) {
	if (root == nullptr)
		return root;
	else if (first < root->data && second < root->data)
		return FindLCA(root->left, first, second);
	else if (first > root->data&& second > root->data)
		return FindLCA(root->right, first, second);
	else
		return root;
}

using namespace std;
int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return 1;

	map<int, int> temp_map;

	for (unsigned int i = 0; i < nums.size(); i++) {
		temp_map.insert(std::pair<int, int>(nums[i], nums[i]));
	}

	int count = 0, result = 0;
	map<int, int>::iterator itr, prev;
	prev = temp_map.begin();
	prev++;
	itr = temp_map.begin();
	for (; prev != temp_map.end(); prev++) {
		std::cout << itr->first << " " << prev->first << std::endl;
		if (prev->first - itr->first == 1) {
			count++;
			if (count > result)
				result = count;
		}
		else {
			count = 0;
		}
		itr++;
	}
	return result + 1;
}
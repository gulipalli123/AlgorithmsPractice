#include<iostream>
void convertBSTtoDLL(BST* root, BST** head)
{
	if (root == nullptr)
		return;
	BST& prev = nullptr;
	convertBSTtoDLL(root->left, head);
	if(prev == nullptr)
	{
		root->left = nullptr;
		head = root;
	}
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	convertBSTtoDLL(root->right, head);
	root->right = head;
	head->left = root;
}
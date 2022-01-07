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
		return nullptr;
	}
	if (data < root->data)
		root->left = InsertAnElement(root->left, data);
	else if (data > root->data)
		root->right = InsertAnElement(root->right, data);
	if (root->left == nullptr)
	{
		root->left = createNode(data);
	}
	else if (root->right == nullptr)
	{
		root->right = createNode(data);
	}
	return root;
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
	//root = InsertAnElement()

}
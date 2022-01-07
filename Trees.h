#include <queue>
#include <stack>
#include <map>

struct BTNode {
	int data;
	struct BTNode* left;
	struct BTNode* right;
};

void Insert(struct BTNode* root, int element) {
	struct BTNode* temp = new BTNode;
	temp->left = temp->right = nullptr;
	temp->data = element;
	std::queue<BTNode*> Q;

	if (root == nullptr) {
		root = new BTNode;
		root->data = element;
		root->left = root->right = nullptr;
	}
	else {
		Q.push(root);
		struct BTNode* node;
		while(false == Q.empty()){
			node = Q.front();
			Q.pop();
			if (!node->left) {
				node->left = temp;
				return;
			}
			else if (!node->right){
				node->right = temp;
				return;
			}
			else{
				Q.push(node->left);
				Q.push(node->right);
			}
		}

	}
}

void InOrder(BTNode* root) {
	if (root) {
		InOrder(root->left);
		std::cout << root->data << " ";
		InOrder(root->right);
	}
}
void PreOrder(BTNode* root) {
	if (root) {
		std::cout << root->data << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void PostOrder(BTNode* root) {
	if (root) {
		PostOrder(root->left);
		PostOrder(root->right);
		std::cout << root->data << " ";
	}
}

void InOrderIterative(BTNode* node) {
	std::stack<BTNode*> S;
	while (1) {
		while (node) {
			S.push(node);
			node = node->left;
		}
		if (true == S.empty())
			break;
		std::cout << node->data << " ";

		node = node->right;
	}
}

void PreOrderIterative(BTNode* node) {
	std::stack<BTNode*> S;
	while (1) {
		while (node) {
			std::cout << node->data << " ";
			S.push(node);
			node = node->left;
		}
		if (true == S.empty())
			break;
		node = S.top();
		S.pop();
		node = node->right;

	}
}

void LevelOrderTraversal(BTNode* node) {
	std::queue<BTNode*> Q;
	BTNode* temp;
	if (!node)
		return;
	Q.push(node);
	while (false == Q.empty()) {
		temp = Q.front();
		std::cout << temp->data << " ";
		Q.pop();
		if (temp->left)
			Q.push(temp->left);
		if (temp->right)
			Q.push(temp->right);
	}
}

//Find max element in binary tree
// Find max value in the left subtree, find max in the right subtree and compare with root to find the max

int FindMax(BTNode* root) {
	int left, right, root_val, max = INT_MIN;
	if (root) {
		root_val = root->data;
		left = FindMax(root->left);
		right = FindMax(root->right);
		if (left > right)
			max = left;
		else
			max = right;
		if (root_val > max)
			max = root_val;
	}
	return max;
}

// Find max without recursion

int FindMaxIterative(BTNode* root)
{
	int max = INT_MIN;
	std::queue<BTNode*> Q;
	BTNode* temp;
	if (!root)
		return 0;
	Q.push(root);
	while (false == Q.empty()) {
		temp = Q.front();
		Q.pop();
		if (temp->data > max)
			max = temp->data;
		if (temp->left)
			Q.push(temp->left);
		if (temp->right)
			Q.push(temp->right);
	}
	return max;
}


void PreOrderTraverseAndStore(BTNode* root, std::multimap<int, int>& mmap, int i) {
	if (root) {
		mmap.insert(std::pair<int,int>(i, root->data));
		PreOrderTraverseAndStore(root->left, mmap, i - 1);
		PreOrderTraverseAndStore(root->right, mmap, i + 1);
	}
}

void verticalPrintBinaryTree(BTNode* root) {
	int i = 0;
	std::multimap<int, int> mmap;
	int prev = INT_MIN;
	PreOrderTraverseAndStore(root, mmap, i);
	std::multimap<int, int>::iterator itr;
	for (itr = mmap.begin(); itr != mmap.end(); itr++) {
		if (prev != itr->first)
			std::cout << "\n" << itr->first << "->" << itr->second;
		else
			std::cout << " " << itr->first << "->" << itr->second ;
		prev = itr->first;
	}

}

int findElement(BTNode* root, int data) {
	int temp = 0;
	if (root == nullptr)
		return 0;
	if (root) {
		if (data == root->data)
			return 1;
		temp = findElement(root->left, data);
		if (temp == 1)
			return 1;
		else
			return findElement(root->right, data);
	}
	return 0;
}

//Find the height of the binary tree: which is nothing but max(leftsubtreeheight, rightsubTreeHeight) + 1(root)

int FindHeight(BTNode* root) {
	if (root == nullptr)
		return 0;
	else {
		int leftH = 0, rightH = 0;
		leftH = FindHeight(root->left);
		rightH = FindHeight(root->right);
		if (leftH > rightH)
			return leftH + 1;
		else
			return rightH + 1;
	}
}

// Find height without using recursion
int FindHeightWithoutRecursion(BTNode* root) {
	int level = 0;
	std::queue<BTNode*> Q;
	if (root == nullptr)
		return 0;
	Q.push(root);
	Q.push(nullptr);
	while (false == Q.empty()) {
		root = Q.front();
		Q.pop();
		if (root == nullptr) {
			level++;
			if(false == Q.empty())
				Q.push(nullptr);
		}
		else {
			if (root->left)
				Q.push(root->left);
			if (root->right)
				Q.push(root->right);
		}
	}
	return level;
	
}

int FindDiameter(BTNode* root) {
	int lheight = 0, rheight = 0, ldiameter = 0, rdiameter = 0;
	if (root == nullptr)
		return 0;
	lheight = FindHeight(root->left);
	rheight = FindHeight(root->right);
	ldiameter = FindDiameter(root->left);
	rdiameter = FindDiameter(root->right);
	return std::max((lheight + rheight + 1), std::max(ldiameter, rdiameter));
}

void FindMirror(BTNode* root) {
	BTNode* temp;
	if (root) {
		FindMirror(root->left);
		FindMirror(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

BTNode* FindLCA(BTNode* root, BTNode* one, BTNode* two) {
	BTNode *left, *right;
	if (root == nullptr)
		return root;
	if (root == one || root == two)
		return root;
	left = FindLCA(root->left, one, two);
	right = FindLCA(root->right, one, two);
	if (left && right)
		return root;
	else
		return left ? left : right;
}

void BTtoDLL(BTNode* root, BTNode* head) {
	if (root == nullptr)
		return;
	static* prev = nullptr;
	BTtoDLL(root->left, head);
	if (prev == nullptr) {
		head = root;
		prev = head;
	}
	else {
		prev->right = root;
		root->left = prev;
		prev = root;
	}
	
	BTtoDLL(root->right, head);
}
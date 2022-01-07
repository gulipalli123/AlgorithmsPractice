// BinaryTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include<unordered_map>
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode* leftNode;
    BinaryTreeNode* rightNode;
};

BinaryTreeNode* newNode(int key)
{
    BinaryTreeNode* temp = new BinaryTreeNode;
    temp->data = key;
    temp->leftNode = temp->rightNode = nullptr;
    return temp;
}

void insertNode(BinaryTreeNode* root, int data)
{
    
    //if (root == nullptr)
    //{
        BinaryTreeNode* newNode = new BinaryTreeNode;
        newNode->data = data;
        newNode->leftNode = newNode->rightNode = nullptr;
    //}
        if (root == nullptr)
            root = newNode;
        else
        {
            std::queue<BinaryTreeNode*> nodeQ;
            BinaryTreeNode* temp;
            nodeQ.push(root);
            while (!nodeQ.empty())
            {
                temp = nodeQ.front();
                nodeQ.pop();
                if (temp->leftNode != nullptr)
                    nodeQ.push(temp->leftNode);
                else
                {
                    temp->leftNode = newNode;

                    break;
                }
                if (temp->rightNode != nullptr)
                    nodeQ.push(temp->rightNode);
                else
                {
                    temp->rightNode = newNode;
                    break;
                }
            }
        }
}
void deleteDeepestNode(BinaryTreeNode* node, BinaryTreeNode* deepestNode)
{
    if (node == deepestNode)
        return;
    std::queue<BinaryTreeNode*> nodeQ;
    BinaryTreeNode* temp = nullptr;
    nodeQ.push(node);
    while (!nodeQ.empty())
    {
        temp = nodeQ.front();
        nodeQ.pop();
        if (temp == deepestNode)
        {
            temp = nullptr;
            delete deepestNode;
            return;
        }
        if (temp->leftNode)
        {
            if (temp->leftNode == deepestNode)
            {
                temp->leftNode = nullptr;
                delete deepestNode;
                return;
            }
            else
                nodeQ.push(temp->leftNode);
        }
        if (temp->rightNode)
        {
            if (temp->rightNode == deepestNode)
            {
                temp->rightNode = nullptr;
                delete deepestNode;
                return;
            }
            else
                nodeQ.push(temp->rightNode);
        }
    }
}

void deleteNode(BinaryTreeNode* node, int data)
{
    if (node == nullptr)
        return;
    std::queue<BinaryTreeNode*> nodeQ;
    nodeQ.push(node);
    BinaryTreeNode *temp, *key_node;
    key_node = nullptr;
    temp = nullptr;
    while (!nodeQ.empty())
    {
        temp = nodeQ.front();
        nodeQ.pop();
        if (temp->data == data)
        {
            key_node = temp;
        }
        if (temp->leftNode)
        {
            nodeQ.push(temp->leftNode);
        }
        if (temp->rightNode)
        {
            nodeQ.push(temp->rightNode);
        }
    }
    if (key_node != nullptr)
    {
        std::cout << "--------------\n";
        std::cout << temp->data << " "<< key_node->data << std::endl;
        std::cout << "--------------\n";
        int x = temp->data;
        deleteDeepestNode(node, temp);
        key_node->data = x;
    }

}

void inorderTraversal(BinaryTreeNode* root)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->leftNode);
    std::cout << root->data << " ";
    inorderTraversal(root->rightNode);
}
int heightOfBinaryTree(BinaryTreeNode* root)
{
    if (root == nullptr)
        return 0;
    auto leftHeight = heightOfBinaryTree(root->leftNode);
    auto rightHeight = heightOfBinaryTree(root->rightNode);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

BinaryTreeNode* mirrorOfBinaryTree(BinaryTreeNode* root)
{
    if (root)
    {
        mirrorOfBinaryTree(root->leftNode);
        mirrorOfBinaryTree(root->rightNode);
        BinaryTreeNode* temp;
        temp = root->leftNode;
        root->leftNode = root->rightNode;
        root->rightNode = temp;
    }
    return root;
}

BinaryTreeNode* lcaOfTwoNodes(BinaryTreeNode* root, BinaryTreeNode* node1, BinaryTreeNode* node2)
{
    if (root == nullptr)
        return root;
    if (node1 == root || node2 == root)
        return root;
    auto left = lcaOfTwoNodes(root->leftNode, node1, node2);
    auto right = lcaOfTwoNodes(root->rightNode, node1, node2);
    if (left && right)
        return root;
    else
        return left ? left : right;
}
void VerticalSumOfBinaryTree(BinaryTreeNode* root, int column, std::unordered_map<int, int>& umap)
{
    if (root == nullptr)
        return;
    VerticalSumOfBinaryTree(root->leftNode, column - 1, umap);
    umap[column] += root->data;
    VerticalSumOfBinaryTree(root->rightNode, column + 1, umap);
}

//Give an algorithm for finding the diameter of the binary tree.The diameter(width) of a tree is the number of nodes on the
// longest path between two leaves in the tree
int DiameterOfBinaryTree(BinaryTreeNode* root, int& ptr)
{
    int left, right;
    if (root == nullptr)
        return 0;
    left = DiameterOfBinaryTree(root->leftNode, ptr);
    right = DiameterOfBinaryTree(root->rightNode, ptr);
    if (left + right + 1> ptr)
        ptr = left + right + 1;
    return std::max(left, right) + 1;
}

bool HasPathSum(BinaryTreeNode* root, int sum)
{
    if (root == nullptr)
        return sum == 0;
    if (sum == 0)
        return true;
    else
    {
        sum = sum - root->data;
        return HasPathSum(root->leftNode, sum) || HasPathSum(root->rightNode, sum);
    }
}

int main()
{
    //driver program
    BinaryTreeNode* root = newNode(10);
    root->leftNode = newNode(5);
    root->leftNode->leftNode = newNode(2);
    root->leftNode->rightNode = newNode(3);
    root->rightNode = newNode(7);
    root->rightNode->leftNode = newNode(8);
    root->rightNode->rightNode = newNode(9);
    
    inorderTraversal(root);

    insertNode(root, 15);

    std::cout << "\n after insertion" << std::endl;

    inorderTraversal(root);
    deleteNode(root, 7);
    std::cout << "\n after deletion" << std::endl;
    inorderTraversal(root);
    std::cout << "\n heightofBinaryTree = " << heightOfBinaryTree(root) << "\n";
    root = mirrorOfBinaryTree(root);
    inorderTraversal(root);
    BinaryTreeNode* lcaNode = lcaOfTwoNodes(root, root->rightNode->leftNode, root->leftNode);
    std::cout << "\nleast common ancestor = " << lcaNode->data << "\n";
    std::unordered_map<int, int> umap;
    VerticalSumOfBinaryTree(root, 0, umap);
     std::cout << "\n Verical Sum Array = ";
    for (auto itr : umap)
    {
        std::cout <<  itr.second << " ";
    }
    std::cout << "\n";
    inorderTraversal(root);
    int p = 0;
    DiameterOfBinaryTree(root, p);
    std::cout << "\n Diameter of BinaryTree = " << p << "\n";
    /*insertNode(root, 20);
    insertNode(root, 25);
    insertNode(root, 16);
    inorderTraversal(root);
    p = 0;
    DiameterOfBinaryTree(root, p);
    std::cout << "\n Diameter of BinaryTree = " << p << "\n";*/
    int sum = 34;
    std::cout << "Has path sum = " << HasPathSum(root, sum) << "\n";

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

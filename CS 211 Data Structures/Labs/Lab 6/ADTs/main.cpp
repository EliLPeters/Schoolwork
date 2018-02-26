#include <iostream>
#include <string>
#include <queue>

#include "sorting\Sorting.h"
#include "ADTs\BinarySearchTree.h"
#include "ADTs\TreeTraversal.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

int getHeight(BinaryNode<int>* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	else if (node->isLeaf())
	{
		return 0;
	}
	int left_height = getHeight(node->getLeftChild());
	int right_height = getHeight(node->getRightChild());
	if (left_height > right_height)
	{
		return 1 + left_height;
	}
	else
	{
		return 1 + right_height;
	}
}

bool isAvl(BinarySearchTree<int> *tree)
{
	BinaryNode<int>* root = tree->getRoot();
	if (root != nullptr)
	{
		int left_height = getHeight(root->getLeftChild());
		int right_height = getHeight(root->getRightChild());
		int difference = right_height - left_height;

		if (difference >= -1 && difference <= 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

BinaryNode<int>* rotateLeft(BinaryNode<int>* original_root)
{
	BinaryNode<int>* temp = original_root->getRightChild;
	original_root->setRightChild(temp->getLeftChild());
	temp->setLeftChild(original_root);
	return temp;
}

bool isFull(BinarySearchTree<int> *tree)
{
	queue<BinaryNode<int>*> to_visit{};

	to_visit.push(tree->getRoot());

	while (to_visit.empty() == false)
	{
		BinaryNode<int>* curr = to_visit.front();
		to_visit.pop();

		if (curr != nullptr)
		{
			if ((curr->getRightChild() == nullptr && curr->getLeftChild() != nullptr) || (curr->getRightChild() != nullptr && curr->getLeftChild() == nullptr))
			{
				return false;
			}
			else if (curr->getRightChild() != nullptr && curr->getLeftChild() != nullptr)
			{
				to_visit.push(curr->getLeftChild());
				to_visit.push(curr->getRightChild());
			}
		}
	}

    return true;
}

bool isComplete(BinarySearchTree<int>* tree)
{
	queue<BinaryNode<int>*> to_visit{};

	bool has_seen_null = false;

	to_visit.push(tree->getRoot());

	// Begin BFS
	while (to_visit.empty() == false)
	{
		BinaryNode<int>* front = to_visit.front();
		to_visit.pop();

		if (front == nullptr)
		{
			has_seen_null = true;
		}
		else
		{
			// found a gap, therefore not complete
			if (has_seen_null == true)
			{
				return false;
			}
			// otherwise push on children
			to_visit.push(front->getLeftChild());
			to_visit.push(front->getRightChild());
		}
	}

	return true;
}

int main(void)
{
    BinarySearchTree<int> tree{};
     
    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;

    tree.addElement(10);
    tree.addElement(5);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;

    tree.addElement(15);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;

    tree.addElement(12);
    tree.addElement(20);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;

    tree.addElement(11);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: FALSE)" << endl;

    tree.addElement(13);
    tree.addElement(1);
    tree.addElement(7);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;


    //Note: this breaks the tree structure because our BST isn't informed of the new root.  Must be done last
    BinaryNode<int>* rotated = rotateLeft(tree.getRoot());
    RecursivePreOrderTraversal<int> traversal{};
    traversal.traverse(rotated);
    
    //rotate again just for fun
    rotated = rotateLeft(rotated);
    traversal.traverse(rotated);
    return 0;
}

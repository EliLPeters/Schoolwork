// ELI PETERS PROGRAMMING FINAL
// THE 5 PROBLEMS COMPLETED: Q1, Q3, Q4, Q5, Q6
// couldn't get Q2 working 100%

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

//Tree used in Q1 & Q2
class TreeNode
{
public:
    int value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int v = 0)
    {
        value = v;
    }
};

//Linked List used in Q3
class LinkedListNode
{
public:
    int value;
    LinkedListNode *next = nullptr;
    LinkedListNode(int v = 0)
    {
        value = v;
    }
};

//Q1
bool isBst(TreeNode* root)
{
	if (root == nullptr)
	{
		return true;
	}
    // If has no children then is BST by default
	if (root->left == nullptr && root->right == nullptr)
	{
		return true;
	}
	// If has no left child make sure right is OK
	else if(root->left == nullptr)
	{
		if (root->right->value < root->value)
		{
			// If not
			return false;
		}
		// If it is then make sure right subtree is BST
		else
		{
			return isBst(root->right);
		}
	}
	// Same deal as above
	else if (root->right == nullptr)
	{
		if (root->left->value >= root->value)
		{
			return false;
		}
		else
		{
			return isBst(root->left);
		}
	}
	//If has both children make sure they're OK,
	//Then check their subtrees for compliance
	else
	{
		if ((root->left->value >= root->value) || (root->right->value < root->value))
		{
			return false;
		}
		else
		{
			return (isBst(root->left) && isBst(root->right));
		}
	}
}

//Q2
bool isAvl(TreeNode* root)
{
	if (root == nullptr)
	{
		return true;
	}
    // NOTE: since I couldn't get this working properly I've left comments
	// explaining my thought process.
	if (root->left != nullptr && root->right != nullptr)
	{
		// If the node has both children, those need to be inspected.
		return (isAvl(root->left) && isAvl(root->right));
	}
	else if (root->right == nullptr && root->left != nullptr)
	{
		// If the node is missing its right child, then if its left child has any children
		// the tree cannot be AVL compliant
		if (root->left->right != nullptr || root->left->left != nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
		
	}
	else if(root->left == nullptr && root->right != nullptr)
	{
		// If the node is missing its left child, then if its right child has any children
		// the tree cannot be AVL compliant
		if (root->right->left != nullptr || root->right->right != nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
		
	}
	else
	{
		return true;
	}
    return false;
}

//Q3

LinkedListNode* reverseList(LinkedListNode* head, LinkedListNode* prev = nullptr) // Default values for parameters are useful!
{
	// Keep track of where the old next node is
	LinkedListNode* old = head->next;
	// makes the head point to where we came from, or nullptr if we're just starting.
	head->next = prev;
	// check if we've reached the end of the original list
	if (old != nullptr)
	{
		// if not then go on to old, and let it know where we came from
		return reverseList(old, head);
	}
	else
	{
		// if we've reached the original end then we return that as the new head
		return head;
	}	
}

//Q4
vector<string> fizzbuzz(int n)
{
	vector<string> result{};
	// push on results based on modulos
	for (int i = 0; i < n; i++)
	{
		if ((i % 5) == 0 && (i % 3) == 0)
		{
			result.push_back("fizzbuzz");
		}
		else if ((i % 5) == 0)
		{
			result.push_back("buzz");
		}
		else if ((i % 3) == 0)
		{
			result.push_back("fizz");
		}
		else
		{
			result.push_back(to_string(i));
		}
	}
	return result;
}

//Q5
string dayWithMostRain(vector<int> data)
{
	int rainiest = 0;

	// find index w/ biggest value
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] > data[rainiest])
		{
			rainiest = i;
		}
	}

	// modulo it and return week.
	switch (rainiest % 7)
	{
	case 0:
		return "Sunday";
		break;
	case 1:
		return "Monday";
		break;
	case 2:
		return "Tuesday";
		break;
	case 3:
		return "Wednesday";
		break;
	case 4:
		return "Thursday";
		break;
	case 5:
		return "Friday";
		break;
	case 6:
		return "Saturday";
		break;
	default:
		return "none";
	}
}

//Q6 (NOTE: no sorting allowed!)
int findNthLargest(vector<int> numbers, int n)
{
	int largest = -1;
	int prev_largest = -10;

	// find largest
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] > largest)
		{
			largest = numbers[i];
		}
	}

	// if n is bigger than 0, repeat n times with caveat that the number must be smaller than the old largest number.
	for (int i = 0; i < n; i++)
	{
		prev_largest = largest;
		largest = -1;

		for (int j = 0; j < numbers.size(); j++)
		{
			if ((numbers[j] > largest) && (numbers[j] < prev_largest))
			{
				largest = numbers[j];
			}
		}
	}
	return largest;
}

int main(void)
{
	cout << boolalpha;
    //Q1 & Q2: This IS AVL height compliant but NOT a BST
    TreeNode* root1 = new TreeNode{ 10 };
    root1->left = new TreeNode{ 5 };
    root1->left->left = new TreeNode{ 1 };
    root1->left->right = new TreeNode{ 3 };
    root1->left->right->right = new TreeNode{ 9 };
    root1->right = new TreeNode{ 15 };
    root1->right->right = new TreeNode{ 25 };
    root1->right->left = new TreeNode{ 12 };
    root1->right->right->right = new TreeNode{ 35 };
    root1->right->right->left = new TreeNode{ 20 };

    cout << "isBst: " << isBst(root1) << " (expected: false)" << endl;
    cout << "isAVL: " << isAvl(root1) << " (expected: true)" << endl;

    //Now, the tree is a valid BST
    root1->left->right->value = 7;
    cout << "isBst: " << isBst(root1) << " (expected: true)" << endl;

    //Now, the tree is not AVL and not BST
    root1->right->right->left->right = new TreeNode{ 11 };
    cout << "isAVL: " << isAvl(root1) << " (expected: false)" << endl;
    cout << "isBst: " << isBst(root1) << " (expected: false)" << endl;

    //Now, the tree is both AVL and BST
    root1->right->right->left->right->value = 22;
    root1->right->left->right = new TreeNode{ 14 };
    cout << "isAVL: " << isAvl(root1) << " (expected: true)" << endl;
    cout << "isBst: " << isBst(root1) << " (expected: true)" << endl;
    cout << endl << endl;

    //Q3:
    LinkedListNode* head = new LinkedListNode{ 1 };
    head->next = new LinkedListNode{ 2 };
    head->next->next = new LinkedListNode{ 1 };
    head->next->next->next = new LinkedListNode{ 3 };
    head->next->next->next->next = new LinkedListNode{ 5 };
    head->next->next->next->next->next = new LinkedListNode{ 4 };
    head = reverseList(head);
    cout << "Reversing LL: ";
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << "(expected: 4 5 3 1 2 1)";
    cout << endl << endl;

    //Q4 [MODIFIED BASED ON INFORMATION ON WHITEBOARD DURING CLASS (CHANGED [0] AND MADE >=)]
    vector<string> result = fizzbuzz(100);
    if (result.size() >= 100)
    {
        cout << "fizzbuzz: [0] = " << result[0] << "  [12] = " << result[12] << "  [20] = " << result[20] << "  [30] = " << result[30] <<
            "  [98] = " << result[98] << endl;
        cout << "expected: [0] = fizzbuzz  [12] = fizz  [20] = buzz  [30] = fizzbuzz  [98] = 98" << endl;
        cout << endl;
    }
    else
    {
        cout << "Fizzbuzz not attempted." << endl << endl;
    }

    //Q5
    vector<int> data = { 1, 1, 1, 1, 1, 1, 1,
                        1, 2, 1, 3, 2, 4, 9,
                        3, 0, 2, 1, 2, 1, 0,
                        4, 1, 1, 1, 1, 1, 1,
                        0, 0, 0, 1, 1, 0, 0,
                        1, 2, 1, 2, 1, 2, 1 };
    cout << "Day with most rain: " << dayWithMostRain(data) << " (expected: Saturday)";
    cout << endl << endl;
    
    //Q6
    data = vector<int>{100, 9, 10, 0, 11, 7, 9, 25, 61, 10, 13, 54, 12, 33};
    cout << "Largest: " << findNthLargest(data, 0) << " (expected: 100)" << endl;
    cout << "2nd Largest: " << findNthLargest(data, 1) << " (expected: 61)" << endl;
    cout << "3rd Largest: " << findNthLargest(data, 2) << " (expected: 54)" << endl;
    cout << "4th Largest: " << findNthLargest(data, 3) << " (expected: 33)" << endl;
}

#include <iostream>
#include <string>
#include <stack>
#include <fstream>

#include "StringSplitter.h"

using namespace std;

double evaluatePostfixExpression(string postfix_string)
{
	//string result = "";
	stack<double> postfix_stack{};
	vector<string> pieces = StringSplitter::split(postfix_string, " ");
	
	for (auto piece : pieces)
	{
		if (piece != "+" && piece != "-" && piece != "*" && piece != "/")
		{
			postfix_stack.push(stod(piece));
		}
		else if (piece == "+")
		{
			double val_2 = 0;
			double val_1 = 0;
			if (!postfix_stack.empty())
			{
				val_2 = postfix_stack.top();
				postfix_stack.pop();
			}
			else
			{
				cout << "An error occured,  Invalid Postfix syntax." << endl;
			}
			if (!postfix_stack.empty())
			{
				val_1 = postfix_stack.top();
				postfix_stack.pop();
			}
			else
			{
				cout << "An error occured,  Invalid Postfix syntax.";
				return 0;
			}
			postfix_stack.push(val_1 + val_2);
		}
		else if (piece == "-")
		{
			double val_2 = 0;
			double val_1 = 0;
			if (!postfix_stack.empty())
			{
				val_2 = postfix_stack.top();
				postfix_stack.pop();
			}
			else
			{
				cout << "An error occured,  Invalid Postfix syntax." << endl;
			}
			if (!postfix_stack.empty())
			{
				val_1 = postfix_stack.top();
				postfix_stack.pop();
			}
			else
			{
				cout << "An error occured,  Invalid Postfix syntax." << endl;
				return 0;
			}
			postfix_stack.push(val_1 - val_2);
		}
		else if (piece == "*")
		{
			double val_2 = 0;
			double val_1 = 0;
			if (!postfix_stack.empty())
			{
				val_2 = postfix_stack.top();
				postfix_stack.pop();
			}
			else
			{
				cout << "An error occured,  Invalid Postfix syntax." << endl;
			}
			if (!postfix_stack.empty())
			{
				val_1 = postfix_stack.top();
				postfix_stack.pop();
			}
			else
			{
				cout << "An error occured,  Invalid Postfix syntax." << endl;
				return 0;
			}
			postfix_stack.push(val_1 * val_2);
		}
		else if (piece == "/")
		{
			double val_2 = 0;
			double val_1 = 0;
			if (!postfix_stack.empty())
			{
				val_2 = postfix_stack.top();
				postfix_stack.pop();
			}
			else
			{
				cout << "An error occured,  Invalid Postfix syntax." << endl;
			}
			if (!postfix_stack.empty())
			{
				val_1 = postfix_stack.top();
				postfix_stack.pop();
			}
			else
			{
				cout << "An error occured,  Invalid Postfix syntax." << endl;
				return 0;
			}
			postfix_stack.push(val_1 / val_2);
		}
	}

	/*while (!postfix_stack.empty())
	{
		if (postfix_stack.top() == "+")
		{
			postfix_stack.pop();

			double val_1 = stod(postfix_stack.top());
			postfix_stack.pop();
			double val_2 = stod(postfix_stack.top());
			postfix_stack.pop();

			postfix_stack.push(to_string(val_2 + val_1));
		}
		if (postfix_stack.top() == "-")
		{
			postfix_stack.pop();

			double val_1 = stod(postfix_stack.top());
			postfix_stack.pop();
			double val_2 = stod(postfix_stack.top());
			postfix_stack.pop();

			postfix_stack.push(to_string(val_2 - val_1));
		}
		if (postfix_stack.top() == "*")
		{
			postfix_stack.pop();

			double val_1 = stod(postfix_stack.top());
			postfix_stack.pop();
			double val_2 = stod(postfix_stack.top());
			postfix_stack.pop();

			postfix_stack.push(to_string(val_2 * val_1));
		}
		if (postfix_stack.top() == "/")
		{
			postfix_stack.pop();

			double val_1 = stod(postfix_stack.top());
			postfix_stack.pop();
			double val_2 = stod(postfix_stack.top());
			postfix_stack.pop();

			postfix_stack.push(to_string(val_2 / val_1));
		}
		else
		{
			result = stod(postfix_stack.top());
			postfix_stack.pop();
		}
	}
	*/

	return postfix_stack.top();
}

int main(void)
{
	// Prompt the user for file to open
	string file_to_open;
	cout << "Enter file name: ";
	getline(cin, file_to_open);

	// Open the file
	ifstream input_file{ file_to_open };

	// Safety checking
	if (input_file.is_open())
	{
		// Read from the file as long as more content is available
		while (input_file.good())
		{
			string current_line;
			getline(input_file, current_line);

			double result = evaluatePostfixExpression(current_line);
			cout << current_line << " = " << result << endl;
		}
	}

	return 0;
}
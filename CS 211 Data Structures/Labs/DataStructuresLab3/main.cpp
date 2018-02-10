
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

#include "StringSplitter.h"

using namespace std;

double evaluatePostfixExpression(string postfix_string)
{
	double result = -1;
	stack<double> postfix_stack{};
	vector<string> pieces = StringSplitter::split(postfix_string, " ");
	
	for (auto piece : pieces)
	{
		
	}

	while (!postfix_stack.empty())
	{
		
	}

	return result;
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
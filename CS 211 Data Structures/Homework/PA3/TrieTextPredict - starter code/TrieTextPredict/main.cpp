#include <string>
#include <iostream>
#include <fstream>

#include "Trie.h"


using namespace std;

//PA #3 Checkin TODO: Implement!
void search(TrieNode *node, vector<string> &words, string current_word, string prefix)
{
	if (prefix.length() > 0)
	{
		char letter = prefix[0];

		current_word.append(string{ letter });

		search(node, words, current_word, prefix.substr(1));
	}
	else
	{
		words.push_back(current_word);
	}
}

//NOTE: You do not have to modify this function.  Its purpose is to call your checkin code
void pa3CheckinDriver()
{
    TrieNode *root = new TrieNode{};

    //build practice word ('apple')
    root->setChild('a', new TrieNode{ 'a' });
    root->getChild('a')->setChild('p', new TrieNode{ 'p' });
    root->getChild('a')->getChild('p')->setChild('p', new TrieNode{ 'p' });
    root->getChild('a')->getChild('p')->getChild('p')->setChild('l', new TrieNode{ 'l' });
    root->getChild('a')->getChild('p')->getChild('p')->getChild('l')->setChild('e', new TrieNode{ 'e' });

    //complete word
    root->getChild('a')->getChild('p')->getChild('p')->getChild('l')->getChild('e')->setChild('$', new TrieNode{ '$' });

    //add branch word ('apples')
    root->getChild('a')->getChild('p')->getChild('p')->getChild('l')->getChild('e')->setChild('s', new TrieNode{ 's' });

    //complete branch word
    root->getChild('a')->getChild('p')->getChild('p')->getChild('l')->getChild('e')->getChild('s')->setChild('$', new TrieNode{ '$' });

    //add 2nd practice word ('age')
    root->getChild('a')->setChild('g', new TrieNode{ 'g' });
    root->getChild('a')->getChild('g')->setChild('e', new TrieNode{ 'e' });
    root->getChild('a')->getChild('g')->getChild('e')->setChild('$', new TrieNode{ '$' });

    //search tree
    //EXPECTED: APPLE, APPLES
    vector<string> words{};
    search(root, words, "", "AP");
    for (string word : words)
    {
        cout << word << endl;
    }
}

int main(void)
{
    Trie dictionary{};

    string line = "";
	string dict_file = "";

    //PA #3 Checkin hook.  Remove before turning in your final PA3
    //pa3CheckinDriver();

    //First, prompt the user for a file containing all of the words to look up
	cout << "Please enter the name of the file you wish to add words from: " << endl;
	cin >> dict_file;

    //Next, add all words in the file into the Trie using the addWord() function
	ifstream recieving;
	recieving.open(dict_file);
	while (recieving.is_open() && recieving.good())
	{
		getline(recieving, line);
		dictionary.addWord(line);
	}
	recieving.close();

    //Then, prompt the user for a list of partial words to look up.  Display all matches on the screen.
	string sub = "";
	cout << "Enter the substring you wish to look up:" << endl;
	cin >> sub;

	if (sub != "")
	{
		vector<string> matches = dictionary.search(sub);

		if (matches.size() == 0)
		{
			cout << "No matches found" << endl;
		}

		int count = 0;
		for (auto match : matches)
		{
			count++;
			cout << count << ": " << match << endl;
		}
	}

	return 0;
}
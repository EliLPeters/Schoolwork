#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <cctype>
#include <vector>
#include <stack>

#include "TrieNode.h"

using namespace std;

class Trie
{
private:
    TrieNode *_root = nullptr;

	void addWordHelper(TrieNode* parent, string remaining)
	{
		char to_add = remaining[0];
		
		// If the first letter doesn't exist yet, create it
		if (parent->getChild(to_add) == nullptr)
		{
			parent->setChild(to_add, new TrieNode{ to_add });
		}

		// If it was passed a string longer than 1 recur with the remaining letters
		// Otherwise give it a sentinel as a child.
		if (remaining.length() > 1)
		{
			addWordHelper(parent->getChild(to_add), remaining.substr(1));
		}
		else
		{
			parent->getChild(to_add)->setChild('$', new TrieNode{ '$' });
		}
	}

	TrieNode* searchHelper(string word, TrieNode* parent)
	{
		if (parent == nullptr)
		{
			return nullptr;
		}
		else
		{
			if (word.length() > 1)
			{
				return searchHelper(word.substr(1), parent->getChild(word.at(0)));
			}
			else
			{
				return parent->getChild(word[0]);
			}
		}
	}

	void matchHelper(vector<string>& matches, string match, TrieNode* node)
	{
		if (node == nullptr)
		{
			cout << "matchHelper() was passed a nullptr." << endl;
			return;
		}

		stack<TrieNode*> matchStack;

		for (auto child : node->getChildren())
		{
			matchStack.push(child);
		}

		if (node->isSentinel())
		{
			matches.push_back(match);
		}
		else
		{
			match += node->getValue();
		}
	}

protected:

public:
    Trie()
    {
        _root = new TrieNode{};
    }

    virtual ~Trie()
    {
        //TODO: clean up memory
		
    }

	//TODO: implement
    void addWord(const string &word)
    {
		// if _root doesn't have the first letter as a child create it
		if (_root->getChild(word[0]) == nullptr)
		{
			_root->setChild(word[0], new TrieNode{ word[0] });
		}
		
		// then run the helper function on that child
		addWordHelper(_root->getChild(word[0]), word.substr(1));
		
    }

	//TODO: implement
    vector<string> search(const string &word)
    {
        vector<string> matches;

		string thingy = word;

		TrieNode* start = searchHelper(word, _root);
		// Navigate through the tree until we hit the final letter, then run the matchHelper function starting there.
		if (start != nullptr)
		{
			cout << "NOT NULL! :D" << endl;
			cout << start->getValue() << endl;
			//matchHelper(matches, thingy, start);
		}
		else
		{
			cout << "null" << endl;
		}

        return matches;
    }
};

#endif // !TRIE_H

#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <cctype>
#include <vector>
using namespace std;

class Trie
{
private:
    TrieNode *_root = nullptr;

	void addWordHelper(TrieNode* parent, string remaining)
	{
		char to_add = remaining[0];
		
		if (parent->getChild(to_add) == nullptr)
		{
			parent->setChild(to_add, new TrieNode{ to_add });
		}

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
		return nullptr;
	}

	void matchHelper(vector<string>& matches, string& match, TrieNode* node)
	{
		if (node == nullptr)
		{
			cout << "matchHelper() was passed a nullptr." << endl;
			return;
		}

		if (node->getValue() == '$')
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
		if (_root->getChild(word[0]) == nullptr)
		{
			_root->setChild(word[0], new TrieNode{ word[0] });
		}

		addWordHelper(_root->getChild(word[0]), word.substr(1));
    }

	//TODO: implement
    vector<string> search(const string &word)
    {
        vector<string> matches;

		string thingy = "";

		TrieNode* start = searchHelper(word, _root);
		// Navigate through the tree until we hit the final letter, then run the matchHelper function starting there.
		if (start != nullptr)
		{
			matchHelper(matches, thingy, start);
		}

        return matches;
    }
};

#endif // !TRIE_H

#include <unordered_map> //hash table
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//LAB EXTRA CREDIT
void concordance(string text)
{
	//TODO
}

bool hasUniqueChars(string text)
{
	unordered_map<char, int> frequency{};

	for (int i = 0; i < text.length(); i++)
	{
		frequency[text.at(i)]++;
		if (frequency[text.at(i)] > 1)
		{
			return false;
		}
	}
	return true;
}

bool isAnagram(string first, string second)
{
	if (first.length() != second.length())
	{
		return false; // can't be anagrams if different lengths
	}
	// First we'll check if they have the same characters
	unordered_map<char, int> f_first{};
	unordered_map<char, int> f_second{};

	for (int i = 0; i < first.length(); i++) // which parameter's length we use is arbitrary
	{
		f_first[first.at(i)]++;
		f_second[second.at(i)]++;
	}

	for (auto item : f_first)
	{
		if (f_second[item.first] != item.second)
		{
			return false;
		}
	}

	return true;
}

string mostCommonSubstring(string text, int size)
{
	if (text.length() < size)
	{
		return "NULL";
	}
	if (size < 1)
	{
		return "NULL";
	}

	//HT tracks frequency distribution
	//KEY is the string
	//VALUE is the number of times we see KEY
	unordered_map<string, int> frequencies{};

	string most_common = "NULL";
	int most_common_count = -1;

	for (int i = 0; i < text.length() - (size - 1); i++)
	{
		string bit = text.substr(i, size);
		frequencies[bit]++;

		if (frequencies[bit] > most_common_count)
		{
			most_common = bit;
			most_common_count = frequencies[bit];
		}
	}

	/* THIS WON'T WORK
	for (auto item : frequencies)
	{
		if (item.second > most_common_count)
		{
			most_common = item.first;
			most_common_count = item.second;
		}
	}
	*/

	return most_common;
}

int main(void)
{
	//unique chars test
	cout << boolalpha;
	cout << "***unique characters test***" << endl;

	//test case #1
	cout << "abcde: " <<
		hasUniqueChars("abcde") 
		<< " (expected: true)"
		<< endl;
 
	//test case #2:
	cout << "aaaa: " <<
		hasUniqueChars("aaaa")
		<< " (expected: false)"
		<< endl;

	//test case #3:
	cout << "(empty string): " <<
		hasUniqueChars("")
		<< " (expected: true)"
		<< endl;

	//test case #4:
	cout << "abcdea: " <<
		hasUniqueChars("abcdea")
		<< " (expected: false)"
		<< endl;

	//anagram tests
	cout << endl << endl;
	cout << "***anagram tests***" << endl;

	//test case #1:
	cout << "tab, bat: " <<
		isAnagram("tab", "bat")
		<< " (expected: true)"
		<< endl;

	//test case #2
	cout << "bat, tab: " <<
		isAnagram("bat", "tab")
		<< " (expected: true)"
		<< endl;

	//test case #3
	cout << "(empty), (empty): " <<
		isAnagram("", "")
		<< " (expected: true)"
		<< endl;

	//test case #4
	cout << "dog, cat: " <<
		isAnagram("dog", "cat")
		<< " (expected: false)"
		<< endl;

	//test case #5
	cout << "castles, castle: " <<
		isAnagram("castles", "castle")
		<< " (expected: false)"
		<< endl;

	//test case #6
	cout << "bat, tabb: " <<
		isAnagram("bat", "tabb")
		<< " (expected: false)"
		<< endl;

	//most common substring
	cout << endl << endl << "***Most common substring***" << endl;

	//test case #1
	cout << "abcabcdefdefabc, 3: " <<
		mostCommonSubstring("abcabcdefdefabc", 3)
		<< " (expected: abc)"
		<< endl;

	//test case #2
	cout << "defdefabcabc, 3: " <<
		mostCommonSubstring("defdefabcabc", 3)
		<< " (expected: def)"
		<< endl;

	//test case #3
	cout << "aaabbcccc, 1: " <<
		mostCommonSubstring("aaabbcccc", 1)
		<< " (expected: c)"
		<< endl;

	//test case #4
	cout << "abcdefhijklmnopqrstuvwxyz, 4: " <<
		mostCommonSubstring("abcdefhijklmnopqrstuvwxyz", 4)
		<< " (expected: abcd)"
		<< endl;

	//test case #5
	cout << "abc, 5: " <<
		mostCommonSubstring("abc", 5)
		<< " (expected: NULL)"
		<< endl;

	//test case #6
	cout << "(Empty), 1: " <<
		mostCommonSubstring("", 1)
		<< " (expected: NULL)"
		<< endl;

	//test case #7
	cout << "abcabcab, 3: " <<
		mostCommonSubstring("abcabcab", 3)
		<< " (expected: abc)"
		<< endl;

	//test case #7
	cout << "abcabcab, 0: " <<
		mostCommonSubstring("abcabcab", 0)
		<< " (expected: NULL)"
		<< endl;

	return 0;
}
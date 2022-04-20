/*
	anagramagator - COP3530 Project 3

	util.cpp

	Anagram utility functions
*/

#include <vector>
#include <string>
#include <cctype>
using namespace std;

/* countLetters: returns a vector with the count of each letter in given word;
	ignores case; does not count numbers or special characters */
vector<int> countLetters(string word)
{
	vector<int> count(26, 0);	// 26 letters; initialize counts to 0

	for (char c : word)
		if (isalpha(c))
			count[tolower(c) - 'a']++;

	return count;
}

/* containsAllLetters: returns true if the counts of each letter in a are
	greater than those of b */
bool containsAllLetters(vector<int> a, vector<int> b)
{
	for (int i = 0; i < 26; i++)
		if (a[i] < b[i])
			return false;

	return true;
}


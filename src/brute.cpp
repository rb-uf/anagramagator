/*
	anagramagator - COP3530 Project 3

	brute.cpp

	Brute-force anagram-finding algorithm
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "util.h"
#include "brute.h"
using namespace std;

/* validWords: returns a vector containing all dictionary words that could be
	a valid component of an anagram */
vector<string> validWords(string input, vector<string>& dict)
{
	vector<string> v;
	vector<int> letters = countLetters(input);

	for (string dictWord : dict) {
		if (dictWord.length() == 1 || dictWord.find("'") != string::npos)
			continue;
		if (containsAllLetters(letters, countLetters(dictWord)))
			v.push_back(dictWord);
	}

	return v;
}

list<string> bruteAnagramAssembler(string input, string current,
	vector<string>& wordList, int pos)
{
	vector<int> inputLetters = countLetters(input);
	string test;
	list<string> anagrams;

	for (int i = pos; i < wordList.size(); i++) {
		test = current;
		test.append(wordList[i]);
		test.append(" ");
		vector<int> testLetters = countLetters(test);

		if (testLetters == inputLetters)	// anagram found
			anagrams.emplace_front(test);
		else if (containsAllLetters(inputLetters, testLetters))
			anagrams.splice(anagrams.end(),
				bruteAnagramAssembler(input, test, wordList, i));
	}

	return anagrams;
}

void brute_printAnagrams(string input, vector<string>& dict)
{
	vector<string> wordList = validWords(input, dict);

	list<string> anagrams = bruteAnagramAssembler(input, "",
		wordList, 0);

	for (string s : anagrams)
		cout << s << endl;
}







/* filter: removes list entries whose letter counts exceed that of the rule */
void filter_exceed(string rule, list<string>& list)
{
	
}

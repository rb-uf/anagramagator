/*
	anagramagator - COP3530 Project 3
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

void loadDict(vector<string>& dict);
vector<int> countLetters(string word);
bool containsAllLetters(vector<int> a, vector<int> b);
void printAnagramWords(string word, vector<string> dict);



int main(int argc, char const *argv[])
{
	vector<string> dict;
	loadDict(dict);

	string input;
	while (cin >> input)
		printAnagramWords(input, dict);

    return 0;
}

/* loadDict: loads dictionary into given string vector */
void loadDict(vector<string>& dict)
{
	string word;
	ifstream file("dict");

	while (!file.eof()) {
		file >> word;
		dict.push_back(word);
	}
}

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

/* printAnagramWords: prints all words from dictionary that can be made only
	from letters in given word */
void printAnagramWords(string word, vector<string> dict)
{
	vector<int> letters = countLetters(word);

	for (string dictWord : dict)
		if (containsAllLetters(letters, countLetters(dictWord)))
			cout << dictWord << endl;
}

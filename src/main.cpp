/*
	anagramagator - COP3530 Project 3
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include "util.h"
#include "brute.h"
#include "filterAlg.h"
#include "anatree.h"
using namespace std;

void loadDict(vector<string>& dict);
void printAnagramWords(string word, vector<string> dict);

int main(int argc, char const *argv[])
{
	vector<string> dict;
	loadDict(dict);
    Anatree anatree(dict);

	string input;
	while (getline(cin, input))
		anatree.printAnagramPhrases(input);

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



/* printAnagramWords: prints all words from dictionary that can be made only
	from letters in given word */
void printAnagramWords(string word, vector<string> dict)
{
	vector<int> letters = countLetters(word);

	for (string dictWord : dict)
		if (containsAllLetters(letters, countLetters(dictWord)))
			cout << dictWord << endl;
}

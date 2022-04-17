/*
	anagramagator - COP3530 Project 3
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <cctype>
#include "util.h"
#include "filterAlg.h"
#include "anatree.h"
using namespace std;

void loadDict(set<string>& dict);

int main(int argc, char const *argv[])
{
	set<string> dict;
	loadDict(dict);
    Anatree anatree(dict);

	string input;
    if (argc > 1 && string(argv[1]) == "anatree")
        while (getline(cin, input))
    		anatree.printAnagramPhrases(input);
    else
    	while (getline(cin, input))
            findSolutions(input, dict);

    return 0;
}

/* loadDict: loads dictionary into given string vector */
void loadDict(set<string> &dict)
{
	string word;
	ifstream file("dict");

	while (!file.eof()) {
		file >> word;
	    if (word.find("'") != string::npos || word.length() <= 2 ||
            word.find("é") != string::npos)
            continue;
        for (int i = 0; i < word.length(); i++)
            word[i] = tolower(word[i]);
		dict.emplace(word);
	}
}

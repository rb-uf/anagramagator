/*
    anagramagator - COP3530 Project 3

    anatree.cpp

    Implementation of a mixed anatree data structure, described here:
    https://en.wikipedia.org/wiki/Anatree
*/

#include <iostream>
#include <string>
#include <list>
#include <set>
#include <cctype>
#include <climits>
#include "util.h"
using namespace std;

class Anatree
{
private:
    list<string> words;
    string charList;
    vector<Anatree *> links;

    Anatree(string charList);  /* for adding nodes internally */
    void addToAnatree(string word);
    void printAnagramPhrasesRecur(Anatree *prevLocation,
        Anatree *currLocation, string partSolution, vector<int> remaining);
    bool alreadyProcessed(Anatree *current, Anatree *mark);

public:
    Anatree(set<string> &dict);
    void printAnagramPhrases(string input);
};


Anatree::Anatree(string charList)
{
    this->charList = charList;
    links = vector<Anatree *>(26, NULL);
}

/* addToAnatree: adds <word> to this Anatree */
void Anatree::addToAnatree(string word)
{
    if (word.find("'") != string::npos || word.length() <= 2 ||
        word.find("é") != string::npos)
        return;

    for (int i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);

    Anatree *currentNode = this;
    vector<int> remaining = countLetters(word);
    string charList = "";

    /* go through each letter of the alphabet */
    for (int i = 0; i < 26; ) {
        /* if <word> has this letter and it remains to be processed... */
        if (remaining[i] > 0) {
            charList += (char) (i + 'a');
            /* (add new node if it does not already exist) */
            if (currentNode->links[i] == NULL)
                currentNode->links[i] = new Anatree(charList);
            /* ...go to that branch of the tree */
            currentNode = currentNode->links[i];
            remaining[i] -= 1;  /* and don't check this letter instance again */
        } else {
            /* check the next letter */
            i += 1;
        }
    }

    /* there are no letters remaining to be checked, which means <currentNode>
        is the exact position in the tree where <word> should be placed */
    for (string existingWord : currentNode->words) {
        if (existingWord == word)
            return;
    }
    currentNode->words.emplace_front(word);
    currentNode->charList = charList;
}

Anatree::Anatree(set<string> &dict)
{
    links = vector<Anatree *>(26, NULL);

    for (string word : dict)
        addToAnatree(word);
}

bool Anatree::alreadyProcessed(Anatree *current, Anatree *mark)
{
    if (mark == NULL) {
        return false;
    } else if (current->charList.length() < mark->charList.length()) {
        return false;
    } else if (current->charList.length() > mark->charList.length()) {
        return true;
    } else {    // same length
        return (current->charList.compare(mark->charList) < 0) ? true : false;
    }
}

void Anatree::printAnagramPhrases(string input)
{
    vector<int> remaining = countLetters(input);
    printAnagramPhrasesRecur(NULL, this, "", remaining);
}
void Anatree::printAnagramPhrasesRecur(Anatree *prevLocation,
    Anatree *currLocation, string partSolution, vector<int> remaining)
{
    if (currLocation == NULL || alreadyProcessed(currLocation, prevLocation))
        return;

    bool complete = true;
    for (int c = 0; c < 26; c++) {
        if (remaining[c] > 0) {
            vector<int> newRemaining = remaining;
            newRemaining[c]--;
            printAnagramPhrasesRecur(prevLocation, currLocation->links[c],
                partSolution, newRemaining);
            complete = false;
        }
    }

    for (string word : currLocation->words) {
        if (complete)
            cout << (partSolution + word) << endl;
        else
            printAnagramPhrasesRecur(currLocation, this,
                (partSolution + word + " "), remaining);
    }
}

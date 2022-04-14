/*
    anagramagator - COP3530 Project 3

    anatree.cpp

    Implementation of a mixed anatree data structure, described here:
    https://en.wikipedia.org/wiki/Anatree
*/

#include <iostream>
#include <string>
#include <list>
#include <cctype>
#include "util.h"
using namespace std;

class Anatree
{
private:
    list<string> words;
    vector<Anatree *> links;

    Anatree();  /* for adding nodes internally */
    void addToAnatree(string word);
    void printAnatreeRecur(Anatree *a);
    void printAnagramPhrasesRecur(Anatree *currLocation,
        string partialSolution, vector<int> remaining);

public:
    Anatree(vector<string> &dict);
    void printAnagramWords(string word);
    void printAnatree();
    void printAnagramPhrases(string input);
};

Anatree::Anatree()
{
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

    /* go through each letter of the alphabet */
    for (int i = 0; i < 26; ) {
        /* if <word> has this letter and it remains to be processed... */
        if (remaining[i] > 0) {
            /* (add new node if it does not already exist) */
            if (currentNode->links[i] == NULL)
                currentNode->links[i] = new Anatree();
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
}

Anatree::Anatree(vector<string> &dict)
{
    links = vector<Anatree *>(26, NULL);

    for (string word : dict)
        addToAnatree(word);
}

/* printAnagramWords: prints all single words that are complete anagrams of
    the given word */
void Anatree::printAnagramWords(string word)
{
    vector<int> remaining = countLetters(word);
    Anatree *currentNode = this;

    for (int i = 0; i < 26; ) {
        if (remaining[i] > 0) {
            if (currentNode->links[i] == NULL)
                return; /* no anagrams found */
            currentNode = currentNode->links[i];
            remaining[i] -= 1;
        } else {
            i += 1;
        }
    }

    for (string word : currentNode->words)
        cout << word << endl;
}


void Anatree::printAnagramPhrases(string input)
{
    vector<int> remaining = countLetters(input);
    printAnagramPhrasesRecur(this, "", remaining);
}
void Anatree::printAnagramPhrasesRecur(Anatree *currLocation,
    string partialSolution, vector<int> remaining)
{
    bool complete = true;
    bool endOfPath = true;

    for (int i = 0; i < 26; i++) {
        if (remaining[i] > 0) {
            complete = false;
            if (currLocation->links[i] != NULL) {
                endOfPath = false;
                vector<int> v = remaining;
                v[i] -= 1;
                printAnagramPhrasesRecur(currLocation->links[i],
                    partialSolution, v);
            }
        }
    }

    string s;
    if (endOfPath) {
        for (string word : currLocation->words) {
            s = partialSolution;
            if (partialSolution != "")
                s.append(" ");
            s.append(word);
            if (complete)
                cout << s << endl;
            else
                printAnagramPhrasesRecur(this, s, remaining);
        }
    }
}


void Anatree::printAnatree()
{
    printAnatreeRecur(this);
}
void Anatree::printAnatreeRecur(Anatree *a)
{
    if (a == NULL)
        return;

    if (a->words.size() >= 2) {
        for (string word : a->words)
            cout << word << "    ";
        cout << endl;
    }

    for (Anatree *link : a->links)
        printAnatreeRecur(link);
}

/*
    anagramagator - COP3530 Project 3

    filterAlg.cpp

    An anagram finding algorithm that builds solutions by recursively appending
    words to partial solutions and filtering word lists based on the partial
    solution.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <iterator>
#include "util.h"
using namespace std;

struct solution
{
    string s;
    vector<int> remaining;     // remaining letters from input

    solution() { s = ""; remaining = vector<int>(26,0); }
};

struct word
{
    string s;
    vector<int> count;        // letter counts for word

    word() { s = ""; count = vector<int>(26,0); }
};


list<word *> filter(list<word *> &oldList, vector<int> remaining,
                        list<word *>::iterator &from, bool inclusive);
void findSolutions(string input, set<string> &dict);
void findSolutionsRecur(solution partialSolution, list<word *> wordList);
solution append(solution existingSolution, word wordToAdd);
list<word *> initialWordList(string input, set<string> &dict);
bool compare_longer(word *w1, word *w2);


/* filter: returns a new word list that is a copy of <oldList>, starting from
    iterator <from>, only including words with letter counts not exceeding
    those of <remaining>; if <inclusive> is false, the returned list will not
    include the word at <from> */
list<word *> filter(list<word *> &oldList, vector<int> remaining,
                        list<word *>::iterator &from, bool inclusive)
{
    list<word *> newList;

    auto iter = from;
    if (!inclusive)
        iter++;

    for (; iter != oldList.end(); iter++) {
        /* iter points to a pointer to a word */
        if (containsAllLetters(remaining, (**iter).count))
                newList.emplace_back(*iter);
    }

    return newList;
}

/* findSolutions: finds anagram solutions and prints them out */
void findSolutions(string input, set<string> &dict)
{
    solution emptySolution;
    emptySolution.remaining = countLetters(input);

    findSolutionsRecur(emptySolution, initialWordList(input, dict));
}
void findSolutionsRecur(solution partialSolution, list<word *> wordList)
{
    /* check if partialSolution is a complete solution; if so, print and exit */
    bool allZero = true;
    for (int count : partialSolution.remaining)
        if (count != 0)
            allZero = false;

    if (allZero) {
        cout << partialSolution.s << endl;
        return;
    }

    /* otherwise, construct every possible solution;
        NOTE: if wordList is empty, that means that there are no words in the
        dictionary that could be used to complete this partial solution;
        in this case, the loop does not run and the partialSolution is
        abandoned */
    for (auto iter = wordList.begin(); iter != wordList.end(); iter++) {
        solution attempt = append(partialSolution, **iter);
        findSolutionsRecur(attempt,
            filter(wordList, attempt.remaining, iter, false));
    }
}

/* append: returns a new (partial) solution with the word added to it */
solution append(solution existingSolution, word wordToAdd)
{
    solution newSolution;
    newSolution.s = existingSolution.s;
    if (existingSolution.s.length() > 0)
        newSolution.s.append(" ");
    newSolution.s.append(wordToAdd.s);

    for (int i = 0; i < newSolution.remaining.size(); i++)
        newSolution.remaining[i] = existingSolution.remaining[i]
            - wordToAdd.count[i];

    return newSolution;
}

/* initialWordList: construct and initial word list according to input string
    and given dictionary vector */
list<word *> initialWordList(string input, set<string> &dict)
{
    list<word *> wordList;
    vector<int> inputLetterCount = countLetters(input);

    for (string s : dict) {
        /* ignore words with length = 1 or with an apostrophe */
        if (s.length() > 2 && s.find("'") == string::npos
            && s.find("é") == string::npos) {
            vector<int> count = countLetters(s);
            if (containsAllLetters(inputLetterCount, count)) {
                word *newWord = new word;
                newWord->s = s;
                newWord->count = count;
                wordList.emplace_back(newWord);
            }
        }
    }

    wordList.sort(compare_longer);
    return wordList;
}

bool compare_longer(word *w1, word *w2)
{
    return w1->s.length() > w2->s.length();
}

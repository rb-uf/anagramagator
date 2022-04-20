# anagramagator
An anagram finder. Created for COP3530 Project 3.



Instructions for Linux:

  Enter "make" to compile. Requires g++.

  To run interactively:
    Enter "./anagram" to run the program using the FilterAlg algorithm (default).
    Enter "./anagram --anatree" to run the program using the Anatree algorithm.
    Enter a word or short phrase. Anagrams will be outputted.
    Ctrl-D to exit.

  To run a single input:
    echo 'input phrase' | ./anagram

  To count the number of anagrams outputted:
    echo 'input phrase' | ./anagram | wc

  To clock the program run time:
    time echo 'input phrase' | ./anagram

  To paginate the program output:
    echo 'input phrase' | ./anagram | less

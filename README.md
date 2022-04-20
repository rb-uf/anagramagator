# anagramagator
An anagram finder. Created for COP3530 Project 3.



### Instructions for Linux:

Enter "make" to compile. Requires g++.

To run interactively:
<br /> - Enter ```./anagram``` to run the program using the FilterAlg algorithm (default).
<br /> - Enter ```./anagram --anatree``` to run the program using the Anatree algorithm.
<br /> - Enter a word or short phrase.
<br /> - ```Ctrl-D``` to exit.

To run a single input:
<br />```echo 'input phrase' | ./anagram```

To count the number of anagrams outputted:
<br />```echo 'input phrase' | ./anagram | wc```

To clock the program run time:
<br />```time echo 'input phrase' | ./anagram```

To paginate the program output:
<br />```echo 'input phrase' | ./anagram | less```

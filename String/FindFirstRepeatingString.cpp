
// CPP program for finding first repeated
// word in a string
#include <bits/stdc++.h>
using namespace std;
 
// returns first repeated word
string findFirstRepeated(string s)
{
    // break string into tokens
    // and then each string into set
    // if a word appeared before appears
    // again, return the word and break
 
    istringstream iss(s);
    string token;
 
    // hashset for storing word and its count
    // in sentence
    set<string> setOfWords;
 
    // store all the words of string
    // and the count of word in hashset
 
    while (getline(iss, token, ' ')) {
        // if word exists return
        if (setOfWords.find(token) != setOfWords.end()) {
            return token;
        }
 
        // insert new word to set
        setOfWords.insert(token);
    }
 
    return "NoRepetition";
}
 
// driver program
int main()
{
    string s("Ravi had been saying that he had been there");
    string firstWord = findFirstRepeated(s);
    if (firstWord != "NoRepetition")
        cout << "First repeated word :: " << firstWord
             << endl;
    else
        cout << "No Repetitionn";
    return 0;
}
/*
Time complexity: O(M)

Space Complexity: O(M) 'M' is the ith index from where the string is repeated 

*/
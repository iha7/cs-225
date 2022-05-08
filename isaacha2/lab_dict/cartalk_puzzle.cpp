/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;
    /* Your code goes here! */
	ifstream wordsFile(word_list_fname);
	string inputWord;
	if(wordsFile.is_open()) {
   		while(getline(wordsFile, inputWord)) {
            if(inputWord.length() == 5) {
                string firstString = inputWord.substr(1);
                string temp;
                temp.append(inputWord.begin(), inputWord.begin() + 1);
                temp.append(firstString.begin() + 1, firstString.end());
                if(d.homophones(inputWord, firstString) && d.homophones(inputWord, temp)) {	
                    ret.push_back(tuple<string, string, string>(inputWord, firstString, temp));
                }
            }
	    }
    }
    return ret;
}

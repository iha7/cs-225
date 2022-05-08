/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    ifstream wordsFile(filename);
    string currentWord;
	if(wordsFile.is_open() == true) {
    	while(getline(wordsFile, currentWord)) {
			string inOrder = currentWord; 
			sort(inOrder.begin(), inOrder.end());
			if(dict.find(inOrder) == dict.end()) {
                vector<string> newVect;
				newVect.push_back(currentWord);
                dict.insert(std::pair<string, vector<string> >(inOrder, newVect));
			} else {
				dict.find(inOrder)->second.push_back(currentWord);

			}
 		}
	}
}



/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
        for(string currentWord : words) {
        string inOrder = currentWord; 
        sort(inOrder.begin(), inOrder.end());
        if(dict.find(inOrder) != dict.end()) {
            dict.find(inOrder)->second.push_back(currentWord);
        } else {
            vector<string> newVect;
            newVect.push_back(currentWord);
            dict.insert(std::pair<string, vector<string> >(inOrder, newVect));
        }
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    string inOrder = word;
   	sort(inOrder.begin(), inOrder.end());
    if(dict.find(inOrder) != dict.end()) {
        return dict.find(inOrder)->second;
    } 
    return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
   	vector<vector<string> > anagrams;
    for(auto lookup = dict.begin(); lookup != dict.end(); ++lookup) {
    	if(1 < lookup->second.size()) {
            anagrams.push_back(lookup->second);
        }
    }
    return anagrams;}
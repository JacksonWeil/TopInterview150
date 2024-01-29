/*

First attempt: --- naive
SPEED: 0 ms
 BEAT: 100.00%
  MEM: 6.75 MB
 BEAT: 72.34% --- woohoo
              

Jackson Weil 1/12/2024

DESC: given 'pattern' and 's' (strings), return whether s follows the pattern
      To follow means to fully match, such that there is a bijection b/t a letter in pattern and a non-empty word in s
    ---
      pattern = 'abba' | s = 'dog cat cat dog' ---> true
      pattern = 'abba' | s = 'dog cat cat fish' --> false b/c a cannot map to fish if it already mapped to dog



CREDIT: myself


INTUITION: --- seems like same idea as 205 Isomorphic Strings (which I happened to do 5 minutes ago) except we map a char to a string rather than another char

            make an unordered_map that maps chars to strings
           for each char in pattern:
                while we see chars of s that are not ' ':
                    form the word
                if (m.find(char) == m.end()):
                    create a key-val pair on the map where the char of s is key and word is the val
                else (i.e. the mapping exists):
                    the val should be the word --- if it is not, s breaks the pattern
            
            make sure j reached the end, i.e. the # words == # pattern chars

NOTES: easy peasy lemon squeezy after doing the Isomorphic Strings exercise first --- basically 'bijected' onto this problem (see w... nvm)

*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
using namespace std;

class Solution {

    public:
        bool wordPattern(string pattern, string s) {

            // iterators for pattern and s, resp.
            int i, j;

            // the ith word of s
            string word;

            // mapping
            unordered_map<char, string> m;

            // set to make sure vals of m are unique
            unordered_set<string> used;

            j = 0;

            // for each character of pattern
            for (i = 0; i < pattern.size(); i++) {

                word = "";
                while (j < s.size() && s[j] != ' ') { // till we see a space or run out of chars, append the word
                    word.push_back(s[j]);
                    j++;
                }
                // we are at a space with j now, so increment for next time
                j++;

                if (m.find(pattern[i]) == m.end()) { // if we haven't mapped it, map it

                    // if we have previously used t[i] in a mapping, we cannot use it again --- return false
                    if (used.find(word) != used.end()) return false;

                    // map it and track the word we have added --- w/ O(1) lookup time in unordered_set
                    m[pattern[i]] = word;
                    used.insert(word);

                } else {
                    // don't actually need strcmp here --- but I'll leave it for the sake of Dr. Plank's old soul
                    if (strcmp(m.find(pattern[i])->second.c_str(), word.c_str()) != 0) { // if we have mapped it, it better be consistent with the current chars we see
                        return false;
                    }
                }
            }

            // I did not ponder the constraints initially --- if s simply has more words than pattern has chars, it breaks the pattern --- good thing we tracked j
            if (j != s.size() + 1) return false;

            return true; // if we finish the loop without returning false, s and t are isomorphs
        }
};
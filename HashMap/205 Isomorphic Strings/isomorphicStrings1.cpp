/*

First attempt: --- naive
SPEED: 7 ms
 BEAT: 53.15%
  MEM: 7.53 MB
 BEAT: 29.08% --- my assumption is that using the set to track the reverse mappings is not optimal for memory but is decent for speed
              

Jackson Weil 1/12/2024

DESC: given two strings 't' and 's', return whether they are isomorphic --- i.e. one can be turned into the other by a 1-to-1 character mapping
      s and t are guaranteed to be equal in length
      a character can map to itself but each character may only map to one other character (or none)


CREDIT: myself


INTUITION: make an unordered_map that maps chars to chars
           for each char in s and t:
                if (m.find(char) == m.end()):
                    create a key-val pair on the map where the char of s is key and char of t is the val
                else (i.e. the mapping exists):
                    the val should be the char of t --- if it is not, the strings are not isomorphic
        ---
            I am not good at pseudocode lol I just combine python and c++ w/ lengthy comments

NOTES: naive solution seems quite decent

*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {

    public:
        bool isIsomorphic(string s, string t) {

            // iterator
            int i;

            // mapping
            unordered_map<char, char> m;

            // set to make sure vals of m are unique
            unordered_set<char> used;

            // for each character
            for (i = 0; i < s.size(); i++) {
                if (m.find(s[i]) == m.end()) { // if we haven't mapped it, map it

                    // if we have previously used t[i] in a mapping, we cannot use it again --- return false
                    if (used.find(t[i]) != used.end()) return false;

                    m[s[i]] = t[i];
                    used.insert(t[i]);
                } else {
                    if (m.find(s[i])->second != t[i]) { // if we have mapped it, it better be consistent with the current chars we see
                        return false;
                    }
                }
            }


            return true; // if we finish the loop without returning false, s and t are isomorphs
        }
};
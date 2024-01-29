/*

second attempt: --- naive plus very minor change to bottom of for loop and getting rid of matched variable
SPEED: 0 ms
 BEAT: 100.00% --- WOOHOO --- to burst my own bubble: 48.61% of solutions to date have achieved 0 ms
  MEM: 6.88 MB --- same as prev...
 BEAT: 23.27% --- welp... I guess removing a boolean and spending 20 minutes reapplying its functionality in its absence with no improvement to mem usage means it's time for lunch
              

Jackson Weil 1/10/2024

DESC: given strings s and t, return whether s is a subsequence of t
      subsequence:  series of characters formed out of one string such that any amount of characters can be deleted, but the relative positions of remaining characters must remain the same
      

CREDIT: myself and chatGPT for incorrectly advising me to use goto to accomplish a break and continue statement in one fell swoop. but hey, now I know goto is a thing


INTUITION: simply go through s and try to match to the corresponding letter in t sequentially
    *** must maintain an index to the working char of t --- call this index
    for each char in s:
        until we exhaust t or find a match:
            if (t[index] == char) --- increment index, break inner loop, continue outer loop
            else --- increment index and try again
    ---
    if we ever get out of the while loop and remain inside the for loop, that means that we exhausted t and could not match all chars in s --- return false here
    return true after for loop


NOTES:

*/

#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {

    public:
        bool isSubsequence(string s, string t) {

            int i, index; // iterator for s | " " t

            index = 0;

            if (s.size() > t.size()) return false;

            // if (t.size() == s.size() && strcmp(t.c_str(), s.c_str()) != 0) return false; // if s and t are the same size, they must be identical for s to be a subsequence

            for (i = 0; i < s.size(); i++) {
                
                if (index >= t.size()) return false; // this is another way to handle what the area after the while loop handled w/o extra lines or use of matched variable 

                while (index <= t.size()) {
                    index++;
                    if (s[i] == t[index - 1]) {
                        break;
                    }
                    if (index == t.size()) return false;
                }
            }

            return true; // if we completed the for loop without returning false, then s was indeed a substring of t
        }
};
/*

First attempt: --- naive 
SPEED: 0 ms
 BEAT: 100.00% --- WOOHOO --- to burst my own bubble: 48.61% of solutions to date have achieved 0 ms
  MEM: 6.88 MB
 BEAT: 23.27% --- a bit disappointing but not bad for a first try --- I probably don't actually need a matched variable; correspondingly, I could clean up the bottom of the for loop body
              

Jackson Weil 1/10/2024

DESC: given strings s and t, return whether s is a subsequence of t
      subsequence:  series of characters formed out of one string such that any amount of characters can be deleted, but the relative positions of remaining characters must remain the same
      

CREDIT: myself 


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
using namespace std;

class Solution {

    public:
        bool isSubsequence(string s, string t) {

            int i, index; // iterator for s | " " t
            bool matched; // set to true if we match a char in s to a char in t

            index = 0;
            matched = false;

            for (i = 0; i < s.size(); i++) {
                while (index < t.size()) {
                    if (s[i] == t[index]) {
                        matched = true;
                        break;
                    } else {
                        index++;
                    }
                }
                // here is where 'break' will take us --- if matched is true, simply reset matched to false and continue --- if matched is false, we exhausted t before finding the ith match --- return false
                if (matched) {
                    matched = false;
                    index++; // whoops --- forgot this at first --- upon matching, we must move to the next element of both s and t
                    continue;
                } else {
                    return false;
                }
            }

            return true; // if we completed the for loop without returning false, then s was indeed a substring of t
        }
};
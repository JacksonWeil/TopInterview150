/*

First attempt: --- naive
SPEED: 92 ms
 BEAT: 5.16%
  MEM: 39.78 MB
 BEAT: 7.37%    --- not sure why this is so slow and inefficient... perhaps I'm actually supposed to just use a different data structure or not use extra O(n) space at all 
              

Jackson Weil 1/12/2024

DESC: given 'ransomNote' and 'magazine' return true if ransomNote can be constructed from the characters of the magazine (using each up to one time)
      return false otherwise


CREDIT:


INTUITION: since this problem is in the HashMap section, I assume I create a hashMap of the chars of magazine (allowing repeats) and
           proceed to find all the chars of ransomNote in that HashMap --- if I find it, delete it, if I don't return false b/c we cannot form the ransomNote


NOTES:

*/

#include <vector>
#include <unordered_set>
#include <iostream>    
using namespace std;

class Solution {

    public:
        bool canConstruct(string ransomNote, string magazine) {

            int i;
            unordered_multiset<char> ums;
            unordered_multiset<char>::iterator it;

            for (i = 0; i < magazine.size(); i++) {
                ums.insert(magazine[i]);
            }

            // find the chars of ransomNote
            for (i = 0; i < ransomNote.size(); i++) {
                it = ums.find(ransomNote[i]);
                if (it != ums.end()) {
                    ums.erase(it);
                } else {
                    return false;
                }
            }
            return true;
        }

};
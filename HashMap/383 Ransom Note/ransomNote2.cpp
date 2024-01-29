/*

First attempt: --- naive
SPEED: 16 ms
 BEAT: 55.93%
  MEM: 9.03 MB
 BEAT: 85.30%    --- much better tc and sc
              

Jackson Weil 1/12/2024

DESC: given 'ransomNote' and 'magazine' return true if ransomNote can be constructed from the characters of the magazine (using each up to one time)
      return false otherwise


CREDIT: binayshaw7777 on leetcode for idea to use vector the length of the alphabet and elements be the quantity of that letter in magazine --- O(26) ---> O(1) extra space, same tc


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
            vector<int> hm;
            
            hm.resize(26, 0); // only english lowercase letters

            for (i = 0; i < magazine.size(); i++) {
                hm[magazine[i] - 'a']++;
            }

            // find the chars of ransomNote
            for (i = 0; i < ransomNote.size(); i++) {
                if (hm[ransomNote[i] - 'a'] > 0) {
                    hm[ransomNote[i] - 'a']--;
                } else {
                    return false;
                }
            }
            return true;
        }

};
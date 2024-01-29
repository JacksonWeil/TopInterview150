/*

First attempt: --- good speed, mid mem usage
SPEED: 4 ms
 BEAT: 85.64%
  MEM: 7.71
 BEAT: 44.72% 
              

Jackson Weil 1/13/2024

DESC: given two strings s and t, return whether t is an anagram of s --- anagram means letters can be rearranged but must all be accounted for


CREDIT: myself


INTUITION: if I create a 'histogram' w/ character labels on the x-axis and frequencies on the y, they should be identical for s and t


NOTES: rahulvarma5297 on leetcode mentions sorting t and s --- if they are not identical after sorting, return false
       while this makes sense, it is O(nlogn) to sort, rather than my O(n) solution
       It is worth noting, however, that the O(nlogn) solution would not require the vector of size 26 (or, more generally, the size of the valid alphabet)
       I do believe, though, that sorting generally requires O(logn) extra space, which is generally worse than O(26) ---> O(1)

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {

    public:
        bool isAnagram(string s, string t) {

            // check for equal sizes of s and t
            if (s.size() != t.size()) return false;

            // iterator
            int i;

            // 'hashmap' or 'histogram'
            vector<int> hist;


            hist.resize(26, 0); // english lowercase letters are guaranteed

            for (i = 0; i < s.size(); i++) { // if we see 'c' in s, increment the third slot of the vector --- if we see it in t, decrement the third slot
                hist[s[i] - 'a']++;
                hist[t[i] - 'a']--;
            }

            for (i = 0; i < hist.size(); i++) {
                if (hist[i] != 0) return false;
            }

            return true;


        }

};
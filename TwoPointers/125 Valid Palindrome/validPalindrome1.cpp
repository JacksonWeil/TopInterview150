/*

First attempt: --- naive
SPEED: 8 ms
 BEAT: 38.01%
  MEM: 8.01 MB
 BEAT: 20.11% 
              

Jackson Weil 1/10/2024

DESC:
given a string s, if you remove non-alphanumeric characters (only keeping a-z, A-Z, and 0-9) and normalize case (A-Z shifts to a-z), is s a palindrome?


CREDIT: myself


INTUITION:
first I plan to create a new string with only the valid, normalized characters
then I will assign a pointer to the front and back and move them inward:
    so long as these pointers do not cross, their characters must be the same
    if corresponding characters differ, return false
return true


NOTES:

*/

#include <vector>
#include <iostream> // allows for 'string' objects
#include <cstdio>
using namespace std;

class Solution {

    public:
        bool isPalindrome(string s) {

            // for cleaning
            string clean_s;
            size_t i;
            char c;

            // for checking if palindrome
            int left, right;

            clean_s = "";
            
            // clean input
            for (i = 0; i < s.size(); i++) {
                // only add the ith char of s to clean_s if it lies in a-z, A-Z, or 0-9 --- turn A-Z chars into a-z chars
                c = s[i];
                if (c >= 'a' && c <= 'z') {
                    clean_s.push_back(c);
                } else if (c >= 'A' && c <= 'Z') {
                    clean_s.push_back(c - ('A' - 'a')); // shift uppercase to lowercase
                } else if (c >= '0' && c <= '9') {
                    clean_s.push_back(c);
                } else { // c is non-alphanumeric
                    continue;
                }
            }

            left = 0;
            right = clean_s.size() - 1;

            // check if clean_s is a palindrome
            while (right >= left) {

                if (clean_s[left] != clean_s[right]) {
                    return false;
                }

                left++;
                right--;
            }

            return true;
        }
};
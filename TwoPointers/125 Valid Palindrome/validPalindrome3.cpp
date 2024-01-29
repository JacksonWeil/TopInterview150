/*

second attempt: --- slight update from naive --- no input cleaning, only refined second stage where unimportant chars are ignored
SPEED: 4 ms - same as before but I was told by ChatGPT that standard library functions are generally optimized far better than my naive solutions will be
 BEAT: 80.94%
  MEM: 7.68 MB - previously 7.89 MB 
 BEAT: 62.07% - previously 20.11% --- decent improvement
              

Jackson Weil 1/10/2024

DESC:
given a string s, if you remove non-alphanumeric characters (only keeping a-z, A-Z, and 0-9) and normalize case (A-Z shifts to a-z), is s a palindrome?


CREDIT: msfxvenom on leetcode for providing the names of two useful functions - isalnum(char c) and tolower(char c) 


INTUITION:
same idea as validPalindrome2.cpp --- I merely replaced length conditionals with isalnum and tolower


NOTES:
I could perhaps make code shorter and possibly faster by using a char c and assigning s[left/right] to c before working with those values, rather than accessing repeatedly,
but I imagine this is somewhat negligible and perhaps I just do not understand the tradeoff b/t vector access and an added variable --- compiler may treat these similarly
at any rate, there is surely room for improvement, but this is good enough for me

*/

#include <vector>
#include <iostream> // allows for 'string' objects
#include <cstdio>
using namespace std;

#include <cctype> // houses functions isalnum(char c) and tolower(char c)

class Solution {

    public:
        bool isPalindrome(string s) {

            // for cleaning
            size_t i;
            char c;

            // for checking if palindrome
            int left, right;

            left = 0;
            right = s.size() - 1;

            // check if clean_s is a palindrome
            while (right >= left) {

                // first thing is first --- if left or right are not pointing to a valid character, let's move them till they are
                while (!isalnum(s[left])) { // this line shortened dramatically
                    left++;
                    if (left > right) return true;
                }

                while (!isalnum(s[right])) { // " " " "
                    right--;
                    if (left > right) return true;
                }

                // now I assume left and right are both pointing to either a lowercase letter, an uppercase letter, or a numerical digit --- let's compare first... if it fails, check if we need to change the case
                if (s[left] != s[right]) {

                    // compare again
                    if (tolower(s[left]) != tolower(s[right])) return false;
                }

                left++;
                right--;
            }

            return true;
        }
};
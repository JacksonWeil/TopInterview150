/*

second attempt: --- slight update from naive --- no input cleaning, only refined second stage where unimportant chars are ignored
SPEED: 4 ms - cut the (more) naive runtime in half
 BEAT: 80.94%
  MEM: 7.89 MB - previously 8.01 MB
 BEAT: 20.11% 
              

Jackson Weil 1/10/2024

DESC:
given a string s, if you remove non-alphanumeric characters (only keeping a-z, A-Z, and 0-9) and normalize case (A-Z shifts to a-z), is s a palindrome?


CREDIT: myself


INTUITION:
same idea as validPalindrome1.cpp, but now I shall not clean the data --- I'll simply ignore invalid chars and adjust uppercase to lowercase as needed


NOTES:
I could perhaps make code shorter and possibly faster by using a char c and assigning s[left/right] to c before working with those values, rather than accessing repeatedly,
but I imagine this is somewhat negligible and perhaps I just do not understand the tradeoff b/t vector access and an added variable --- compiler may treat these similarly
at any rate, there is surely room for improvement, but this is good enough for me

*/

#include <vector>
#include <iostream> // allows for 'string' objects
#include <cstdio>
using namespace std;

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
                while (!(s[left] >= 'a' && s[left] <= 'z') && !(s[left] >= 'A' && s[left] <= 'Z') && !(s[left] >= '0' && s[left] <= '9')) {
                    left++;
                    if (left > right) return true;
                }

                while (!(s[right] >= 'a' && s[right] <= 'z') && !(s[right] >= 'A' && s[right] <= 'Z') && !(s[right] >= '0' && s[right] <= '9')) {
                    right--;
                    if (left > right) return true;
                }

                // now I assume left and right are both pointing to either a lowercase letter, an uppercase letter, or a numerical digit --- let's compare first... if it fails, check if we need to change the case
                if (s[left] != s[right]) {
                    // there are two possibilites now: they are the same letter in different cases, or they simply do not match --- attempt to convert both to lowercase and try again --- if that fails, return false
                    if (s[left] >= 'A' && s[left] <= 'Z') s[left] = s[left] - ('A' - 'a');
                    if (s[right] >= 'A' && s[right] <= 'Z') s[right] = s[right] - ('A' - 'a');

                    // compare again
                    if (s[left] != s[right]) return false;
                }

                left++;
                right--;
            }

            return true;
        }
};
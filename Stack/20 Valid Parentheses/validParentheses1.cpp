/*

First attempt: --- naive --- used Leetcode hints
SPEED: 0 ms
 BEAT: 100%
  MEM: 8.36 MB
 BEAT: 8.09% --- I really did not need either of the sets or maps, but it was good practice for me --- and cleaned up my subsequent code
              

Jackson Weil 1/23/2024

DESC: given a string s containing only the three types of parentheses --- (), {}, [] --- return whether s is valid --- i.e. proper syntax


CREDIT: myself and leetcode hints


INTUITION: make a stack of characters
           when we encounter an opener, push it onto the top of the stack
           when we encounter a closer, see if the right opener is at the top of the stack
                --- valid? pop it
                --- invalid? ret false


NOTES:

*/

#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <map> // map openers to closers
using namespace std;

class Solution {

    public:
        bool isValid(string s) {
            stack<char> stack;
            set<char> openers;
            set<char> closers;
            map<char, char> o_to_c;
            int i;

            openers = {'(', '{', '['};
            closers = {')', '}', ']'};

            o_to_c = {
                {'(', ')'},
                {'{', '}'},
                {'[', ']'}
            };

            // iterate over s, using the stack to check validity
            for (i = 0; i < s.size(); i++) {
                // check for opener
                if (openers.find(s[i]) != openers.end()) {
                    stack.push(s[i]);
                }

                // based on constraints, I now assume I have a closer, so I won't check explicitly
                else {

                    // if we have a closer but the stack is empty, ret false
                    if (stack.empty()) return false;

                    // make sure the corresponding opener is atop the stack
                    if (o_to_c[stack.top()] == s[i]) {
                        stack.pop();
                    } else {
                        return false;
                    }
                }
            }

            // if stack is not empty, i.e. we have more openers than closers, ret false, else, ret true
            return stack.empty();
        }


};
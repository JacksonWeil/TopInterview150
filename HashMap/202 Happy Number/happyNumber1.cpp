/*

First attempt: ---
SPEED: 4 ms
 BEAT: 28.62%
  MEM: 6.81 MB
 BEAT: 12.05%
              

Jackson Weil 1/16/2024

DESC: given a number n, return whether n is 'happy'
      a happy number is a number whose digits can be recursively squared and summed
      eventually resulting in 1 (steady state)
      if a number gets caught in a loop, it is not happy


CREDIT:


INTUITION: make a hashmap of the values we are getting after each square-summation
           if we have seen a value before, return false
           if we end up with 1, return true


NOTES:

*/

#include <vector>
#include <set>
using namespace std;

class Solution {

    public:

        int digSqSum(int& n) {
            int ret = 0;
            int tmp = 0;
            while (n > 0) {
                tmp = n % 10;
                tmp *= tmp;
                ret += tmp;
                n /= 10;
            }
            return ret;
        }

        bool isHappy(int n) {

            set<int> s;
            int tmp;

            while(1) {

                tmp = n;

                while(n > 0) {
                    tmp = digSqSum(tmp);
                    if (tmp == 1) return true;
                    if (s.find(tmp) != s.end()) {
                        return false;
                    } else {
                        s.insert(tmp);
                    }
                }
            }
        }
};
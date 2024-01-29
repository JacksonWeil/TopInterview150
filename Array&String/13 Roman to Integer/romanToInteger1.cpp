/*

First attempt: --- roundabout process --- ended up with something quite simple and readable with one small (* 2) trick
SPEED: 7 ms
 BEAT: 77 %
  MEM: 13.90 MB
 BEAT: 5.06 % --- mapping and ints vector are unnecessary, but I do believe they make the actual calculation exceptionally readable
              

Jackson Weil 1/24/2024

DESC: convert a roman-numeral string to an integer


Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

1 can precede 5 and 10
10 can precede 50 and 100
100 can precede 500 and 1000

"MCMXCIV" ---> {1000, 100, 1000, 10, 100, 1, 5}
I'd like to add 1000 to buffer, see the 100 next and 

CREDIT:


INTUITION: create a mapping of the roman numerical symbols to their corresponding arabic integers
           loop over s (the Roman representation) and create a vector of the mapped integer values
           loop over the integer vector, and form the final answer
           if a smaller int precedes a larger int, the smaller int will be subtracted from the larger
           if a larger int is followed by a smaller int, the smaller int will be added to the larger


NOTES:

*/

#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {

    public:
        int romanToInt(string s) {

            int i;
            int ret;
            int prev;
            map<char, int> r_to_i;
            vector<int> ints;

            // set up mapping
            r_to_i = {
                {'I', 1},
                {'V',5},
                {'X',10},
                {'L',50},
                {'C',100},
                {'D',500},
                {'M',1000}
            };

            // create ints through mapping
            for (i = 0; i < s.size(); i++) {
                ints.push_back(r_to_i[s[i]]);
            }

            // now, if s was "XI..." ints should be {10, 1, ...}

            // follow roman numeral rules to craft our ret value
            prev = ints[0];
            ret = prev;
            
            
            for (i = 1; i < ints.size(); i++) {

                // check for 1, 5, and 100 cases in prev where the following int (ints[i]) is larger
                if (prev == 1 || prev == 10 || prev == 100) {
                    if (ints[i] > prev) {
                        ints[i] -= (2 * prev); // subtracting prev does what you expect --- subtracting again undoes the addition of prev to ret that necessarily happened on the previous iteration
                    }
                } 
                ret += ints[i];

                prev = ints[i];
            }

            return ret;
        }
};
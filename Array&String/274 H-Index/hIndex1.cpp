/*

First attempt: --- naive --- accepted on leetcode, but very poor time and mem complexity
SPEED: 11 ms
 BEAT: 7.07%
  MEM: 9.34 MB
 BEAT: 6.29%
              

Jackson Weil 1/9/2024

DESC: we have array (vector here) called citations of length (1 <= n <= 5000) of ints in range (1 <= citations[n] <= 1000)
    element 'i' represents how many citations a researcher has accrued on their ith paper
    H-index is defined as the max value of h such that the researcher has published at least h papers that have been cited h times
    ex: [3, 0, 6, 1, 5] ---> H-index = 3 b/c 3 papers have been cited at least 3 times
    ---
    return H-index given the array


CREDIT: myself


INTUITION: create a vector of length 1000, called at_least
           for each element of citatations:
             for each index (1 --> citations[n]):
                increment at_least[index]
           go through at_least, maintaining the highest h-h index-value pairing
           return h


NOTES:

*/

#include <vector>
using namespace std;

class Solution {

    public:
        int hIndex(vector<int>& citations) {
            int i, index, h, min;

            // init at_least vector
            vector<int> at_least;
            at_least.resize(1000, 0);

            // for each citation element, go through at_least and increment up to that element's value (in indices)
            for (i = 0; i < citations.size(); i++) {
                for (index = 0; index <= citations[i]; index++) {
                    at_least[index]++;
                }
            }

            h = 0;

            // find the H-index by looking through the entire at_least vector
            for (i = 0; i < at_least.size(); i++) {

                // if any element of at_least is less than the current h-value, we can break, b/c at_least is monotonically non-increasing
                if (at_least[i] < h) break;

                min = at_least[i] < i ? at_least[i] : i;
                if (min > h) h = min;
            }

            return h;
        }

};
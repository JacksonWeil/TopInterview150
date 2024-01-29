/*

First attempt: --- naive --- lightning fast w/ O(nlogn) tc --- mem usage is middle of the pack
SPEED: 0 ms
 BEAT: 100%
  MEM: 8.91 MB
 BEAT: 42.46%
              

Jackson Weil 1/9/2024

DESC: we have array (vector here) called citations of length (1 <= n <= 5000) of ints in range (1 <= citations[n] <= 1000)
    element 'i' represents how many citations a researcher has accrued on their ith paper
    H-index is defined as the max value of h such that the researcher has published at least h papers that have been cited h times
    ex: [3, 0, 6, 1, 5] ---> H-index = 3 b/c 3 papers have been cited at least 3 times
    ---
    return H-index given the array


CREDIT: Gaurav_Tomar on leetcode


INTUITION: sort citations
           initialize a 'length' integer to be 0
           for each elmnt of citations, beginning at the end:
                increment length
                if the elmnt < length:
                    return length - 1
           return length (size of vector now)
        ---
           essentially, we are moving from O((max_citation#)^2) to O(nlogn) + O(n) ---> O(nlogn), where n is guaranteed to be less than max_citation# AND nlogn is faster than n^2
           this works b/c when sorted and you maintain length starting from the end, you know if an element is sufficiently high to continue searching or
            sufficiently low to quit

NOTES:

one may also consider using a binary search approach where instead of starting at the end of the array, we start at the middle and find where citations[i] == i or is closest
this would not change the big O from O(nlogn) b/c we still must sort, and frankly the code is slightly more complex with no obvious significant time or space boost
credit for considering binary search on sorted array --- KKumarMay2003 on leetcode

*/

#include <vector>
#include <algorithm> // for sort()
using namespace std;

class Solution {

    public:
        int hIndex(vector<int>& citations) {

            int length, ri; // length from end | reverse iterator

            // sort
            sort(begin(citations), end(citations));

            length = 0;

            // go thr/ sorted vector, starting at the end (higher elmnts)
            for (ri = citations.size() - 1; ri >= 0; ri--) {

                length++;

                // we know that if this elmnt is smaller than length, then all elmnts to the left will be equal or smaller and therefore not raise our H-index above 'length'
                if (citations[ri] < length) {
                    return length - 1;
                }
            }
            return length;
        }
};
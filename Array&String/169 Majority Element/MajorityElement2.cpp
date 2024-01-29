/*

Second attempt --- beats 98.59% users in speed (6 ms) --- more than twice as fast as before... not sure why
               --- beats 66.05% users in mem  (19.99 MB)

Jackson Weil 1/5/2024

find the element of the array (vector here) that appears more than n/2 times

CREDIT: rahulvarma5297 on leetcode

INTUITION: same as my first thought, but he calls it "Moore's Voting Algorithm"
           and his code seems a bit cleaner

NOTE: rahul uses a weird python-like loop syntax that would make Dr. Plank's blood curdle

*/
#include <vector>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int confidence;
        int elmnt;
        // int i; rahul doesn't use an iterator b/c the weird syntax you're about to see

        elmnt = 0;
        confidence = 0;

        for (int n : nums) { // python cheese
            if (confidence == 0) {
                elmnt = n;
            }
            if (n == elmnt) {
                confidence++;
            } else {
                confidence--;
            }
        }

        return elmnt;
    }
};
/*

First attempt --- beats 45.00% users in speed (16 ms)
              --- beats 66.05% users in mem  (19.96 MB)

Jackson Weil 1/5/2024

find the element of the array (vector here) that appears more than n/2 times

*/
#include <vector>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int confidence;
        int elmnt;
        int i;

        elmnt = nums.at(0);
        confidence = 1;

        for (i = 1; i < nums.size(); i++) { // new element overtakes past winner
            if (confidence == 0 && nums[i] != elmnt) {
                confidence = 1;
                elmnt = nums[i];
            } else if (nums[i] == elmnt) { // we see the current majority element again --- confidence increases
                confidence++;
            } else {                       // we see a different element but confidence is nonzero --- confidence decreases
                confidence--;
            }
        }

        return elmnt;
    }
};
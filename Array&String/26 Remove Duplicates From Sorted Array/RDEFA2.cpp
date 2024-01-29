/*

Second attempt --- beats 63.69% users in speed (8 ms)
               --- beats 54.47% users in mem  (18.73 MB)

Jackson Weil 1/4/2024

remove all duplicates from a vector of integers in-place and return the number 'k' of elements that are unique;
the resulting vector should have the first k elements unique;
the remaining elements are not important;

CREDIT: all credit to rahulvarma5297 on leetcode

INTUITION:

simple change: don't need last b/c it is always at index i - 1

NOTES:

- no appreciable difference in memory
- somehow this is faster by 2 ms, but that might not be signficant
- in fact, I would have suspicions that adding the variable is faster b/c
    that seems like we are cutting the index accessing in half and instead just
    copying an integer that we already found within the contiguous block (vector here)

*/

#include <vector>


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i;
        int u;

        if (nums.size() == 0) return 0;

        u = 1;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[u] = nums[i];
                u++;
            }
        }

        return u;
    }
};
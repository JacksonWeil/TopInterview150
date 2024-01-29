/*

First attempt --- beats 51.45% users in speed (10 ms)
              --- beats 54.47% users in mem  (18.80 MB)

Jackson Weil 1/4/2024

remove all duplicates from a vector of integers in-place and return the number 'k' of elements that are unique;
the resulting vector should have the first k elements unique;
the remaining elements are not important;

*/

#include <vector>


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i;
        int u;
        int last;

        if (nums.size() == 0) return 0;

        u = 1;
        last = nums[0];
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] != last) {
                nums[u] = nums[i];
                u++;
            }
            last = nums[i];
        }

        return u;
    }
};
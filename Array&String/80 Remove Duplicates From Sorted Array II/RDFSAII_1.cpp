/*

First attempt --- beats 70.08% users in speed (4 ms)
              --- beats 31.38% users in mem  (11.34 MB)

Jackson Weil 1/4/2024

remove some duplicates from a vector of integers in-place 
such that each element appears at most twice
and return the number 'k' of elements that are unique;
the resulting vector should have the first k elements unique;
the remaining elements are not important;

INTUITION:

same as RDEFA I except we must maintain how many times an element has appeared
and reset that variable whenever we see a new element

*/

#include <vector>


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i;
        int u;
        int seen;

        if (nums.size() == 0) return 0;

        u = 1;
        seen = 1;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1] || seen < 2) {

                if (nums[i] != nums[i-1]) {
                    seen = 1;
                } else {
                    seen++;
                }

                nums[u] = nums[i];
                u++;
                
            }
        }

        return u;
    }
};
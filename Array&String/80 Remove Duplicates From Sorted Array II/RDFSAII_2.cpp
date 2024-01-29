/*

Second attempt --- beats 100.00% users in speed (0 ms)
               --- beats 94.43% users in mem  (11.20 MB)

Jackson Weil 1/4/2024

remove some duplicates from a vector of integers in-place 
such that each element appears at most twice
and return the number 'k' of elements that are unique;
the resulting vector should have the first k elements unique;
the remaining elements are not important;

CREDIT: L005er22 on leetcode

INTUITION:

same idea as mine except the count ("seen" in mine) is calculated first
and then insertion is based on the count after - a bit cleaner

NOTES:

could be due solely to how simple the problem and tests are, but speed and mem are better

*/

#include <vector>


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i;
        int u;
        int seen;

        if (nums.size() == 0) return 0;

        u = 1; // first lmnt always unique
        seen = 0;
        for (i = 1; i < nums.size(); i++) {
            // determine whether to increment or reset seen
            if (nums[i] == nums[i - 1]) {
                seen++;
            } else {
                seen = 0;
            }

            // add or skip over depending solely on seen
            if (seen <= 1) {
                nums[u] = nums[i];
                u++;
            }
        }
        return u;
    }
};
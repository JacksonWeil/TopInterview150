/*

First attempt --- beats 100.00% users in speed (0 ms) --- imprecise, of course; varies b/t 0 and 8 ms
              --- beats 17.83% users in mem  (9.32 MB) -- also varies greatly, but always seems bad

Jackson Weil 1/2/2024

remove all elements of value 'val' from a vector of integers and return the number 'k' of elements that do not equal val
the resulting vector should have the first k elements equal to the elements of the vector that are not val
the remaining elements are not important

*/

// [3, 2, 2, 3] --> [2, 2, _, _] but mine is [2, 3...]
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right;
        int i;
        int tmp;

        right = nums.size() - 1;

        for (i = 0; i <= right; i++) {
            if (nums[i] == val) {
                while ((nums[right] == val) && (right > i)) { // we don't want to move an element of value 'val' to replace another element of value 'val', so we will keep looking for a non-val element
                    right--; // pretend that you swapped this element since is equals val and happens to already be at the end
                }
                if (right == -1) return 0;
                nums[i] = nums[right];
                right--;

            }
        }
        return right + 1;
    }
};
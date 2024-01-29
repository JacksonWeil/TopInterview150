/*

Second attempt --- beats 30.72% users in speed (4 ms) --- imprecise, of course; varies b/t 0 and 8 ms
              --- beats 80.41% users in mem  (9.05 MB) -- also varies greatly, but always seems bad

Jackson Weil 1/2/2024

remove all elements of value 'val' from a vector of integers and return the number 'k' of elements that do not equal val
the resulting vector should have the first k elements equal to the elements of the vector that are not val
the remaining elements are not important

CREDIT: all credit to rahulvarma5297 on leetcode

INTUITION:

since it does not matter what the last elements are (the ones that equal val)
we can simply overwrite them and maintain how many elements are not equal to val (index)
if all elements are not equal to val, this will simply replace them with the value that is
already there

NOTES:

- memory usage seems much better, and the code is far simpler than in my first attempt
- runtime doesn't do any wonders but that is probably just because Leetcode's tests are tiny

*/

// [3, 2, 2, 3] --> [2, 2, _, _] but mine is [2, 3...]
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i;
        int index;

        index = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
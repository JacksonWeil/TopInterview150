/*

Third attempt: --- easy O(n) approach that I overlooked --- at least I anticipated that there would be a simpler way... just didn't see it - very similar to Jump Game I
SPEED: 7 ms
 BEAT: 93.94%
  MEM: 16.89 ms
 BEAT: 75.92%
              

Jackson Weil 1/8/2024

you have an integer vector called nums
each element of nums represents the maximum length you can jump forward through nums at that position
return the minimum number of jumps to reach the end --- it is guaranteed that you can reach the end

ex: [1, 3, 0, 1, 4] returns 2 b/c you can jump one position from 0 to 1 and three positions from 3 to 4
ex: [3, 3, 1, 0, 7] returns 2 b/c you can do a little jump and a big jump

CREDIT: mr_kamran on leetcode

INTUITION: do a pass through  i = 1 to i = nums.size() - 1 of nums in which you reset each element to be the max of the following 2 options:
                i) the maximum index you can jump to from this element
                ii) the maximum index you can reach from one element prior
           in this way, you will set up the following pass such that you are always jumping to the 'correct' index
            ---
           do another pass in which you maintain index and the number of jumps you have taken, both starting at 0
           simply jump to (updated)nums[index] until you fall off the end or reach the end exactly
           with each jump, increment the number of jumps variable
           when you reach the end, return the number of jumps --- it will be optimal due to that concise yet powerful first pass of pre-processing
*/

#include <vector>
using namespace std;

// [2  3  1  1  4]
/*
2 should go to 3 and the first 1 --- neither are the end or past, so we recurse, maintaining the jumps to 3 and the first 1 as being 1
    3 checks the first 1, the second 1, and 4 --- 4 is at or past the end, so we return the number of jumps to 3 (1) plus the jump it takes to 4 (1 + 1 = 2)
    note: it may be worth pruning out 3's jump to the first 1 b/c we already know that 1 can be reached in 1 jump rather than 2 --- sort of DP idea
*/

class Solution {
    public:
        int jump(vector<int>& nums) {

            int i;
            int ind;
            int jumps;

            // first pass --- 'pre-processing'
            for (i = 1; i < nums.size(); i++) {
                nums[i] = nums[i] + i > nums[i - 1] ? nums[i] + i : nums[i - 1];
            }

            ind = 0;
            jumps = 0;

            // second pass --- make the optimal jump easily thanks to the preprocessing
            while (ind < nums.size() - 1) {
                ind = nums[ind];
                jumps++;
            }

            return jumps;

        }
};
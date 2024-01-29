/*

First attempt --- too slow for leetcode, but I believe it is correct --- example of bad big-O: O(kn) where n and k can both be 10^5 --- 10^10 is too slow
              

Jackson Weil 1/6/2024

rotate an array (vector here) 'nums' by k places
try doing it in place and with O(1) extra space... seems like the time complexity will be O(kn) where n is the size of the vector
*** I'm wrong - I exceed the time limit here. There must be an O(n) solution that is also small in memory usage

*/

#include <vector>

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int i, j;
            int cur, next;

            cur = nums[0];

            for (i = 0; i < k; i++) { // for each step k
                for (j = 0; j < nums.size(); j++) { // for each integer of the vector, move it forward by 1 place
                    next = nums[(j+1) % nums.size()];
                    nums[(j+1) % nums.size()] = cur;
                    cur = next;
                }
                cur = nums[0];
            }


            return;
        }
};
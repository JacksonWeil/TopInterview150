/*

First attempt: --- TIME LIMIT EXCEEDED --- O(n^2) time complexity... time for some dynamic programming
SPEED: 
 BEAT: 
  MEM: 
 BEAT:  
              

Jackson Weil 1/7/2024

you have an integer vector called nums
each element of nums represents the maximum length you can jump forward through nums at that position
return true if the last index can be reached, and false otherwise

ex: [1, 3, 0, 1, 4] returns true b/c you can jump one position from 0 to 1 and three positions from 3 to 4
ex: [3, 2, 1, 0, 7] returns false b/c you can never get past that pesky 0

INTUITION: recursively try to jump to the end using the farthest jump length and work your way down --- if the total length falls of vector, return true
*/

class Solution {
    public:
        bool canJump(vector<int>& nums) {

            return recJump(nums, 0, nums[0]);

        }
        bool recJump(vector<int>&nums, int current_position, int jump_length) {

            // base case --- we jumped to the end
            if (current_position >= nums.size() - 1) return true;

            int i;

            // recursive step --- try lesser jumps
            for (i = jump_length; i > 0; i--) {
                if (current_position + i >= nums.size()) {
                    return true;
                }
                if (recJump(nums, current_position + i, nums[current_position + i])) {
                    return true;
                }
            }

            return false;
        }
};
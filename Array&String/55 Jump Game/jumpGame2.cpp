/*

Second attempt: --- add cache (dynamic programming step 2?) --- slower than Christmas and even worse in memory usage... but it passes
SPEED: 595 ms
 BEAT: 13.14%
  MEM: 52.00
 BEAT: 6.00%
              

Jackson Weil 1/7/2024

you have an integer vector called nums
each element of nums represents the maximum length you can jump forward through nums at that position
return true if the last index can be reached, and false otherwise

ex: [1, 3, 0, 1, 4] returns true b/c you can jump one position from 0 to 1 and three positions from 3 to 4
ex: [3, 2, 1, 0, 7] returns false b/c you can never get past that pesky 0

CREDIT: user2085X on leetcode --- dynamic programming in 2 ways --- this code reflects the first --- he also mentions weird Kadane algo stuff at the end that I don't understand right now

INTUITION: recursively try to jump to the end using the farthest jump length and work your way down --- if the total length falls of vector, return true
           *** use cache to save time by cutting out repeat calls
*/

#include <vector>

class Solution {
    public:
        bool canJump(vector<int>& nums) {

            vector<int> cache;
            cache.resize(nums.size(), -1);

            return recJump(nums, 0, nums[0], cache);

        }
        bool recJump(vector<int>&nums, int current_position, int jump_length, vector<int>& cache) {

            // base case --- we jumped to the end
            if (current_position >= nums.size() - 1) return true;

            if (cache[current_position] != -1) return cache[current_position]; // dynamic programming to ameliorate repeat calls

            int i;

            // recursive step --- try lesser jumps
            for (i = jump_length; i > 0; i--) {
                if (current_position + i >= nums.size()) {
                    return true;
                }
                if (recJump(nums, current_position + i, nums[current_position + i], cache)) {
                    return cache[current_position] = true; // dynamic programming to ameliorate repeat calls
                }
            }

            return cache[current_position] = false; // dynamic programming to ameliorate repeat calls
        }
};
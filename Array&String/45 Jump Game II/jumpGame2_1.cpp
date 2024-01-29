/*

First attempt: --- use cache as in Jump Game (I) --- but rather than booleans we will cache the min jumps from this element to element at n - 1 ?
SPEED:
 BEAT: 
  MEM: 
 BEAT: 
              

Jackson Weil 1/8/2024

you have an integer vector called nums
each element of nums represents the maximum length you can jump forward through nums at that position
return the minimum number of jumps to reach the end --- it is guaranteed that you can reach the end

ex: [1, 3, 0, 1, 4] returns 2 b/c you can jump one position from 0 to 1 and three positions from 3 to 4
ex: [3, 3, 1, 0, 7] returns 2 b/c you can do a little jump and a big jump

NOTE: I realized my solution below is on a faulty track --- I am essentially doing DFS, but I need to do something more again to BFS if I wish to go the recursive route
      my solution will just chase the path it starts on and if it reaches the end, it will return however many jumps it has taken, w/o considering shorter paths
      if I instead do a BFS approach and jump to all children, check if any are at or past the end, and then recurse on the children, I may at least arrive at the right answer
      I ought to also consider the possibility that I am overlooking a simpler solution, as I did in the first Jump Game problem
        ---
      the code below outputs 1 instead of 2 on the leetcode test cases --- I may come back to it, but for now, I'm going to leave this code and try a BFS approach
*/

#include <vector>

// [2  3  1  1  4]
/*
2 should go to the first 1, the first 1 to the second 1, and the second 1 to the end
*/

class Solution {
    public:
        
        int jump(vector<int>& nums) {

            vector<int> cache;
            cache.resize(nums.size(), -1);

            return recJump(nums, 0, nums[0], cache, 0);

        }
        int recJump(vector<int>&nums, int current_position, int jump_length, vector<int>& cache, int past_jumps) {

            // base case --- we jumped to the end
            if (current_position >= nums.size() - 1) return cache[current_position] = past_jumps;

            if (cache[current_position] != -1) return cache[current_position]; // dynamic programming to ameliorate repeat calls

            int i;

            // recursive step --- try lesser jumps
            for (i = jump_length; i > 0; i--) {
                if (current_position + i >= nums.size() - 1) {
                    return cache[current_position] = past_jumps + 1;
                }
                if (recJump(nums, current_position + i, nums[current_position + i], cache, past_jumps + 1)) {
                    return cache[current_position] = past_jumps + 1; // dynamic programming to ameliorate repeat calls
                }
            }

            return cache[current_position] = false; // dynamic programming to ameliorate repeat calls
        }
};
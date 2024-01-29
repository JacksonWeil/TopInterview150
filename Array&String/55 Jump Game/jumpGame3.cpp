/*
Second attempt: --- apparently dynamic programming is completely unnecessary --- this solution is extremely simple, and I overlooked it
SPEED: 43 ms
 BEAT: 84.53%
  MEM: 48.97 MB
 BEAT: 26.65%
              

Jackson Weil 1/7/2024

you have an integer vector called nums
each element of nums represents the maximum length you can jump forward through nums at that position
return true if the last index can be reached, and false otherwise

ex: [1, 3, 0, 1, 4] returns true b/c you can jump one position from 0 to 1 and three positions from 3 to 4
ex: [3, 2, 1, 0, 7] returns false b/c you can never get past that pesky 0

CREDIT: Jugantar2020 on leetcode --- easy peasy lemon squeezy

INTUITION: maintain your reach as you iterate through nums
           if at any point you reach an index of nums greater than reach, return false
           at each point, update reach if your reach from the current element is greater than the current reach
*/


#include <vector>

class Solution {
    public:
        bool canJump(vector<int>& nums) {
        int reachable = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(i > reachable) return false; // if we cannot reach any intermediate index, then we certainly cannot reach the end
            reachable = reachable > i + nums[i] ? reachable : i + nums[i]; // update reachable if necessary
        } 
        return true;
    }
};
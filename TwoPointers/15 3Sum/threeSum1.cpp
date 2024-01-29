/*

First attempt: --- naive plus help from leetcode hints
SPEED: 
 BEAT: 
  MEM: 
 BEAT:  
              

Jackson Weil 1/11/2024

DESC: given integer array nums, return all triplets (the values) such that the values add to 0. The indices of these values within a triplet much be unique from one another


CREDIT: myself and leetcode hints


INTUITION:
- if we fix one number, it turns into a 2sum problem where we search for 2 other numbers that add to -(first number)
- if we fix a second number, it turns into a simple search for a number equaling -(num1 + num2)
- perhaps we could search for this third number faster with either a binary search or a hashmap --- hashmap would likely be faster but more mem usage

NOTES:

*/

#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {

    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ret;


        }

};
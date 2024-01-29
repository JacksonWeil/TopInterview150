/*

Second attempt: --- similar to first approach, but trying to develop a more sophisticated search
SPEED: 11 ms
 BEAT: 52.73%
  MEM: 15.92 MB
 BEAT: 59.35%
              

Jackson Weil 1/10/2024

DESC: given a 1-indexed array of ints 'numbers' sorted in non-decreasing order, find two elements that add to a 'target'
      return the indices added by one (to achieve this weird '1-indexed' criteria) of the two elements that add to target
      *** solution must use only constant extra space

CREDIT: Aryan_Marwaha on leetcode --- start 2 pointers at beginning and end, if their elements sum to less than target, increment the left; greater? incr right; equal? done


INTUITION: /\

NOTES: I am a silly goose

*/

#include <vector>
using namespace std;

class Solution {

    public:
        vector<int> twoSum(vector<int>& numbers, int target) {

            vector<int> ret;
            int left, right; // my two 'pointers'

            left = 0;
            right = numbers.size() - 1;

            while (left < right) {
                if (numbers[left] + numbers[right] == target) {
                    ret.push_back(left + 1) ;
                    ret.push_back(right + 1);
                    return ret;
                } else if (numbers[left] + numbers[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }

        ret.push_back(-1);

        return ret;
        }
};
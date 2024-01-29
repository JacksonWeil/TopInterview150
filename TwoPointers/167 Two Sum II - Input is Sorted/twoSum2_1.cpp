/*

First attempt: --- time limit exceeded --- it fails to finish in time on long inputs where the correct indices are near the end --- I need to sophisticate my approach
SPEED: 
 BEAT: 
  MEM: 
 BEAT:  
              

Jackson Weil 1/10/2024

DESC: given a 1-indexed array of ints 'numbers' sorted in non-decreasing order, find two elements that add to a 'target'
      return the indices added by one (to achieve this weird '1-indexed' criteria) of the two elements that add to target
      *** solution must use only constant extra space

CREDIT:


INTUITION: since solution must use only constant extra space (and since this problem is in the '2 pointers' category)
           I am just going to start my pointers at the first and second element --- the non-decreasing property of the vector will become important
           I know my left pointer will start at the lowest element
           increment my right pointer so long as it does not sum with the left pointer's element to target
           if the right pointer element's sum with the left pointer element exceeds target,
           I know that farther increases to the right pointer are fruitless
           At this point, it is not immediately obvious what I should do with the pointers at this point
           My most naive idea is to increment left by one, set right to be one past that, and start the process over
           of course, this is O(n^2) --- it seems likely that we could do much better, even with the space constraint, but I'm not sure

NOTES:

*/

#include <vector>
using namespace std;

class Solution {

    public:
        vector<int> twoSum(vector<int>& numbers, int target) {

            vector<int> ret;
            int left, right; // my two 'pointers'

            left = 0;
            right = 1;

            while (numbers[left] <= target / 2 && right < numbers.size()) { // if left reaches a value that is more than half of the target, we know the solution is not there --- note that a solution is guaranteed, however

                while (right < numbers.size() && numbers[left] + numbers[right] <= target) {
                    // check the sum
                    if (numbers[left] + numbers[right] == target) {
                        ret.push_back(left + 1);
                        ret.push_back(right + 1);
                        return ret;
                    }
                    right++;
                }

                // we did not find our target sum --- increment left and set right one index farther
                left++;
                right = left + 1;
            }

        ret.push_back(-1);

        return ret;
        }


};
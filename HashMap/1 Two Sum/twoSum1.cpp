/*

First attempt: --- naive hashmap
SPEED: 11 ms
 BEAT: 70.40%
  MEM: 11.34 MB
 BEAT: 26.57%
              

Jackson Weil 1/16/2024

DESC: given array (vector here) nums and a target, return the indices of two (unique) elements in nums that add to target --- solution is guaranteed and unique


CREDIT:


INTUITION: maintain a hashmap (unordered_map here) of value_needed-index pairs as we go through the vector nums
           say target is 8 and we see a 3 at index 0 --> (5, 0) will go on the unordered_map
           for each element we will call find --- if it does not equal the end of the mm, we've got our twoSum pair!
           if it does equal the end (i.e. not on the mm), we will insert < (target - this_element), index > onto the mm and continue


NOTES:

*/

#include <vector>
#include <unordered_map> // don't need a multimap b/c in the case we NEED two of the same number, we will be able to conclude which ones w/o inserting the second
using namespace std;

class Solution {

    public:
        vector<int> twoSum(vector<int>& nums, int target) {

            vector<int> ret;
            unordered_map<int, int> lf_idx;
            int i;

            for (i = 0; i < nums.size(); i++) {
                if (lf_idx.find(nums[i]) != lf_idx.end()) {
                    ret.push_back(lf_idx.find(nums[i])->second);
                    ret.push_back(i);
                    return ret;
                } else {
                    lf_idx[target - nums[i]] = i;
                }
            }

            return ret;
        }

};
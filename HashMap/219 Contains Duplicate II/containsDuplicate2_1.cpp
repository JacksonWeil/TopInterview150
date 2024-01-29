/*

First attempt: --- naive --- good tc, subpar mem usage
SPEED: 121 ms
 BEAT: 89.18%
  MEM: 80.95 MB
 BEAT: 16.22% 
              

Jackson Weil 1/20/2024

DESC: given int array nums and int k, return whether there exist two distinct indices i and j such that nums[i] == nums[j] and abs(i - j) <= k


CREDIT:


INTUITION: hashmap with (value, index) pairs --- if we see a repeat value, check to see if it exists w/in k places
           if values do match but they are more than k spaces apart, update the map entry keyed on the value to have the new index in its second slot


NOTES: we really only ever need to store k elements on our hashmap, but I probably will not worry about removing unneeded values

*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {

    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {

            int i;
            unordered_map<int, int> m;
            unordered_multimap<int, int>::iterator mit;

            // loop through nums
            for (i = 0; i < nums.size(); i++) {

                // see if this value exists on the multimap
                mit = m.find(nums[i]);

                // if mit is m.end(), we didn't find the value
                if (mit == m.end()) {

                    m[nums[i]] = i;

                } else { // it was on the map --- see if it's w/in k spaces. if yes, return true, otherwise, update the entry w/ recent index

                    if (i - mit->second <= k) {
                        return true;
                    } else {
                        mit->second = i;
                    }
                }
            }

            return false;
        }

};
/*

Second attempt: --- use a set --- never maintain more than k elements
SPEED: 157 ms
 BEAT: 30.8%
  MEM: 83.01 MB
 BEAT: 8.39% 
              

Jackson Weil 1/20/2024

DESC: given int array nums and int k, return whether there exist two distinct indices i and j such that nums[i] == nums[j] and abs(i - j) <= k


CREDIT: sambhav22435 --- sliding window idea so that we only ever store k elements


INTUITION: multiset that stores the elements of nums --- if i surpasses k, erase nums[i - k - 1] from the multiset
           if the count of an element nums[i] equals 1 in the multiset, return true
           add nums[i] to the multiset

NOTES: sambhav uses a multiset but I just used a set b/c I realized if we are ever about to insert a duplicate, we will just return true
       *** although this conceptually has better big-Oh space complexity, it turns out not to be great

*/

#include <vector>
#include <set>
using namespace std;

class Solution {

    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {

            int i;
            set<int> s;

            // loop
            for (i = 0; i < nums.size(); i++) {

                // never store more than k elements --- get rid of the oldest one
                if (i > k) {
                    s.erase(nums[i - k - 1]);
                }

                // check the count
                if (s.find(nums[i]) != s.end()) return true;

                // insert nums[i] in set
                s.insert(nums[i]);

            }

            return false;
        }

};
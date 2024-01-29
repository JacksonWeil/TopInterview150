/*

First attempt: --- naive
SPEED: 3 ms
 BEAT: 41.85%
  MEM: 8.24 MB
 BEAT: 9.47% 
              

Jackson Weil 1/19/2024

DESC: given a sorted unique int array (vector here) nums,
      return a list of ranges such that each int in nums is covered by one of the ranges, and no range accounts for ints not present in nums
      if a range spans more than one int, do
      "a->b"
      else
      "a"


CREDIT: chatGPT for refreshing me on sprintf and memset


INTUITION: maintain all the ranges and a temporary string that will hold the current range of interest
           if the next int in nums is one greater than the previous, we are expanding our range
           if the next int in nums is more than one greater than the previous, create a range for the previous and start a new range on this number


NOTES:

memset(myString, 0, sizeof(myString));
-- alternatively --
myString[0] = '\0';

*/

#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

class Solution {

    public:
        vector<string> summaryRanges(vector<int>& nums) {

            vector<string> ranges;
            int low, high; // low and high ends of the range --- if they turn out to be equal before appending them to our vector, condense into a single number
            char r[67];
            int i;
            int prev;

            if (nums.size() == 0) {
                return ranges;
            }

            low = nums[0];
            high = nums[0];
            prev = nums[0];

            

            for (i = 1; i < nums.size(); i++) {
                // if we incremented by 1, this number can be part of the current range
                if (nums[i] == prev + 1) {
                    high = nums[i];
                } else { // otherwise, append the current range to ranges and start a new range

                    // handle the case where low and high are the same; then handle case where they differ
                    if (low == high) {
                        sprintf(r, "%d", low);
                    } else {
                        sprintf(r, "%d->%d", low, high);
                    }
                    // append on ranges
                    std::string s(r);
                    ranges.push_back(s);

                    // clear r
                    memset(r, 0, sizeof(r));

                    // start new range
                    low = nums[i];
                    high = nums[i];

                }
                prev = nums[i];
            }

            // add the last range if necessary!
            if (low == high) {
                    sprintf(r, "%d", low);
            } else {
                    sprintf(r, "%d->%d", low, high);
            }
            // append on ranges
            std::string s(r);
            ranges.push_back(s);

            return ranges;
        }


};
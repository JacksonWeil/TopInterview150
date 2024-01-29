/*

Second attempt w/ stripped printing: --- BFS approach
SPEED:
 BEAT: 
  MEM: 
 BEAT:  --- passes 92 / 109 of leetcode test cases but the time limit is exceeded...
              

Jackson Weil 1/8/2024

you have an integer vector called nums
each element of nums represents the maximum length you can jump forward through nums at that position
return the minimum number of jumps to reach the end --- it is guaranteed that you can reach the end

ex: [1, 3, 0, 1, 4] returns 2 b/c you can jump one position from 0 to 1 and three positions from 3 to 4
ex: [3, 3, 1, 0, 7] returns 2 b/c you can do a little jump and a big jump

NOTE: There is likely a more obvious and naive solution that I cannot see, but I realized BFS may work, so here goes nothing
*/

#include <vector>
#include <map>
#include <cstdio>
using namespace std;

// [2  3  1  1  4]
/*
2 should go to 3 and the first 1 --- neither are the end or past, so we recurse, maintaining the jumps to 3 and the first 1 as being 1
    3 checks the first 1, the second 1, and 4 --- 4 is at or past the end, so we return the number of jumps to 3 (1) plus the jump it takes to 4 (1 + 1 = 2)
    note: it may be worth pruning out 3's jump to the first 1 b/c we already know that 1 can be reached in 1 jump rather than 2 --- sort of DP idea
*/



class Solution {
    public:
        multimap<int, int> jumps_pos;
        multimap<int, int>::iterator mmit;
        vector<int> shortest_path_to_index;

        int jump(vector<int>& nums) {

            shortest_path_to_index.resize(nums.size(), -1);

            int index;
            int i;
            int jumps_to_here;
            multimap<int, int>::const_iterator check_iter;

            jumps_pos.insert(make_pair(0, 0));

            while (!(jumps_pos.empty())) {

                mmit = jumps_pos.begin();

                // memoize
                shortest_path_to_index[mmit->second] = mmit->first;

                if (mmit->second >= nums.size() - 1) return mmit->first; // we found the length of the quickest path

                index = mmit->second;
                jumps_to_here = mmit->first;
                jumps_pos.erase(jumps_pos.begin());

                for (i = nums[index]; i > 0; i--) {
                    if (index + i >= nums.size() - 1) return jumps_to_here + 1;
                    if (shortest_path_to_index[index + i] == -1) {
                        jumps_pos.insert(make_pair(jumps_to_here + 1, index + i)); // put all the 'children' or 'reachable indices' on the mm
                    }
                }
            }
            return -1;
        }
};
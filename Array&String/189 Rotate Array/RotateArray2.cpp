/*

Second attempt: --- as expected, the speed is decent and the mem usage is pretty bad
SPEED: 20 ms
 BEAT: 78.51%
  MEM: 26.04 MB
 BEAT: 15.29% 
              

Jackson Weil 1/6/2024

rotate an array (vector here) 'nums' by k places
try doing it in place and with O(1) extra space... seems like the time complexity will be O(kn) where n is the size of the vector
*** In my first solution, I exceeded the time limit. Now I'm just going to try to solve it fast enough and use extra mem

*/

#include <vector>

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            vector<int> v_copy;

            int i, s;

            s = nums.size(); // I'm going to save this to a var b/c it will be called a lot

            v_copy.resize(s);

            for (i = 0; i < s; i++) { // make v_copy the shifted version of nums
                v_copy[(i + k) % s] = nums[i];
            }

            for (i = 0; i < s; i++) { // copy v_copy back into nums
                nums[i] = v_copy[i];
            }


            return;
        }
};
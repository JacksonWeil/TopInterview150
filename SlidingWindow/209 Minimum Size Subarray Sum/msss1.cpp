/*

First attempt: --- naive
SPEED: 
 BEAT: 
  MEM: 
 BEAT:  
              

Jackson Weil 1/_/2024

DESC: given array of positive integers nums and positive target 'target', return minimal length of a subarray whose sum is gte target. if there is not one, ret 0


CREDIT: myself


INTUITION: I will start my window at the beginning of the array
           I will always keep i1 to the left of i2 or on top of it
           so long as the elements between i1 and i2 (inclusive) sum below target, I will move my i2 rightward, i.e. expanding the window
           when I reach the sum (or exceed it) I'll set min to (i2 - i1 + 1) --- the size of the subarray made by the window
           I'll proceed to scoot i1 toward i2 until the sum of elements they encompass falls below target
           I'll then repeat from the 'so' line (3 lines above) until either i2 reaches the end w/o the sum >= target
           note --- if the minimum window to reach target is 1, I can return 1 immediately, as it cannot be beat


NOTES:

*/

#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

class Solution {

    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int min, cur, sum;
            int i1, i2; // i1 starts as the left side of window, i2 as right

            min = 0; sum = nums[0];

            i1 = 0; i2 = 0;

            while (i2 < nums.size()) { // not actually sure if this should be my condition

                printf("big while\n");

                while (sum < target) { // expand window rightward till we reach target
printf("   little while\n");
                    if (i2 >= nums.size()) return min; // if i2 falls off vector --- we are done
                    i2++;
                    sum += nums[i2];
                }

                // once we break that while loop, we need to calculate how wide our window is --- if our window is currently 0 or this new window is smaller than the last, update min
                cur = i2 - i1 + 1;
                if (min == 0 || cur < min) min = cur;

                if (min == 1) return min;

                // now let's reel in the window from the left to see if we can make it smaller while still summing gte target
                while (sum >= target) {
printf("   2nd little while\n");
                    if (i1 - 1 >= i2) return 1;
                    sum -= nums[i1];
                    i1++;
                }

                // once we break that while loop, we will actually want to undo the last window shift --- we might have passed by an optimal solution
                i1--; // might need to make sure this is gte 0
                sum += nums[i1];

                // let's check how wide the window is again
                cur = i2 - i1 + 1;
                if (cur < min) min = cur;

                i1++;
                sum -= nums[i1]; // I think we actually have to redo this to avoid infinite loop

                if (min == 1) return min;
            }

            return min;
        }

};


int main() {

    vector<int> v = {2, 3, 1, 2, 4, 3};
    int target = 7;
    Solution s;

    printf("%d\n\n", s.minSubArrayLen(target, v));

}
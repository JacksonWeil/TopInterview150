/*

First attempt: ---
SPEED: 61 ms -- varies but always in the green or black
 BEAT: 90.96% 
  MEM: 59.37 MB
 BEAT: 51.44%
              

Jackson Weil 1/10/2024

DESC: array 'height' of length n
      imagine n vertical lines drawn one unit away from each other
      the two endpoints of the ith vertical line are (i, 0) and (i, height[i])
      find two lines that, w/ x-axis, form the largest container by area
      return max amount of 'water' (area defined by these lines and x-axis, with the top barrier being at the height of the shorter bar)


CREDIT: --- leetcode hints, lol I couldn't resist


INTUITION: classic 2 pointer problem --- init pointers to beginning and end
           calculate the initial container area --- this will be the working maximum area
           always move the pointer that points to the shorter bar
           if the moved pointer now points to a taller bar, recalculate the area
           if the newly calculated area exceeds the maximum area, set the maximum area to be the new area
           stop when bars meet
           return max area


NOTES: probably could save some mem, esp. by getting rid of 'limiter' but I am satisfied with this --- pretty neat problem

*/

#include <vector>
using namespace std;

class Solution {

    public:
        int maxArea(vector<int>& height) {
            int max_a, a;
            int l, r;
            int limiter; // height of the shorter bar --- used for area calculation --- unnecessary but explanatory

            l = 0;
            r = height.size() - 1;
            limiter = height[l] > height[r] ? height[r] : height[l];

            max_a = (r - l) * limiter;

            while (r > l) { // till pointers meet (when they meet, area is necessarily 0 b/c l - r == 0)
                if (height[l] > height[r]) { // if left bar is taller
                    while (r > l && height[r] > height[r - 1]) { // if the neighboring bar is shorter, there is no shot area increases --- just keep goin
                        r--;
                    }
                    
                    r--;
                    // calc this new area
                    limiter = height[l] > height[r] ? height[r] : height[l];

                    a = (r - l) * limiter;
                    if (a > max_a) max_a = a;
                } else { // right bar is taller or equal to left bar
                    while (r > l && height[l] > height[l + 1]) {
                        l++;
                    }
                   
                    l++;
                    // calc this new area
                    limiter = height[l] > height[r] ? height[r] : height[l];

                    a = (r - l) * limiter;
                    if (a > max_a) max_a = a;
                }
            }
            return max_a;  
        }
};
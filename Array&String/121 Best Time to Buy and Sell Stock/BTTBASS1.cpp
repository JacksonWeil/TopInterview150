/*

First attempt: --- 
SPEED: 96 ms
 BEAT: 62.93%
  MEM: 93.63 MB
 BEAT: 58.78% 
              

Jackson Weil 1/7/2024

you have prices where prices[i] is a stock price on the ith day
return the maximum profit from buying on a single day and selling on a single day in the future
return 0 if the stock is non-increasing

NOTE: I completed this one a few months back for an English project. The solution is pretty clean
      I am not sure where I got the idea from --- I know I did not come up with it myself.
      It is decently efficient and O(n), so I am going to leave this and move to the next leetcode Top 150 problem.

*/

#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low;
        int cur;
        int cur_val;
        int max_profit;

        low = prices[0];
        max_profit = 0;

        for (cur = 0; cur < prices.size(); cur++) {
            cur_val = prices[cur];
            if (cur_val < low) {
                low = cur_val;
                continue;
            }
            if (cur_val - low > max_profit) {
                max_profit = cur_val - low;
            }
        }
        return max_profit;
        
    }
};
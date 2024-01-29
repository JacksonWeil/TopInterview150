/*

First attempt: --- 
SPEED: 4 ms
 BEAT: 73.30%
  MEM: 13.36 MB
 BEAT: 65.54% 
              

Jackson Weil 1/7/2024

you have prices where prices[i] is a stock price on the ith day
return the maximum profit from buying as often as you like and selling as often as you like
with the restriction that you may only own 1 or 0 shares at a time

INTUITION: there are 2 interesting cases (if cur_val == low, we do nothing)
1) cur_val > low --- sell the stock to gain profit of cur_val - low, but buy it back immediately, anticipating the possibility of a higher number after
2) cur_val < low --- pretend like you did NOT actually repurchase the stock as in case 1 and instead buy on this newly found low --- if only it worked like this IRL
*/

#include <vector>

class Solution {

    public:
        int maxProfit(vector<int>& prices) {
            int total_prof;
            int i;
            int cur_val;
            int low;

            total_prof = 0;
            low = prices[0];

            for (i = 1; i < prices.size(); i++) {
                cur_val = prices[i];

                // case 1 --- cur_val > low --- we sell here because we make a profit, but then we immediately buy again
                if (cur_val > low) {
                    total_prof += (cur_val - low);
                    low = cur_val;
                } else if (cur_val == low) {
                    continue;
                } else { // case 2 --- cur_val < low --- pretend like you went back in time and sold on the previous low and then buy this new low
                    low = cur_val;
                }
            }

            return total_prof;
        }
};
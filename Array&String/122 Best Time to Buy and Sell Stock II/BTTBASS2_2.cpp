/*

First attempt: --- 
SPEED: 0 ms
 BEAT: 100.00%
  MEM: 13.25 MB
 BEAT: 94.01% 
              

Jackson Weil 1/7/2024

you have prices where prices[i] is a stock price on the ith day
return the maximum profit from buying as often as you like and selling as often as you like
with the restriction that you may only own 1 or 0 shares at a time

CREDIT: AtinRoy on leetcode

INTUITION:
maintain buy_day, sell_day, and profit --- all initialized to 0
start buy_day and sell_day at the day
as long as you don't run sell_day off the prices vector and the next price is more than the current selling price (prices[sell_day]), postpone selling by incrementing sell_day
when this is no longer true (the next price is less than the current sell price), sell the stock and add this local profit to your total profit
set buy_day to be the day after the current sell_day and buy_day to be the same
return the profit

NOTE:
sort of like my solution, except this seems faster because when the selling price goes up, instead of having code to sell and buy again immediately,
    AtinRoy simply changes the selling day and moves on --- same big(O) but a bit less unnecessary calculation
*/

#include <vector>

class Solution {

    public:
        int maxProfit(vector<int>& prices) {
            int buy_day, sell_day;
            int profit;

            profit = 0;
            buy_day = 0;
            sell_day = 0;

            while (buy_day < prices.size() && sell_day < prices.size()) {
                while (sell_day + 1 < prices.size() && prices[sell_day + 1] > prices[sell_day]) {
                    sell_day++;
                }

                profit += (prices[sell_day] - prices[buy_day]);

                buy_day = sell_day + 1;
                sell_day = buy_day;

            }
            return profit;
        }
};
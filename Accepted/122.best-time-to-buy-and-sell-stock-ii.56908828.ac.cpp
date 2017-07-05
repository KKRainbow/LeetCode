/*
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 *
 * Easy (46.65%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at the
 * same time (ie, you must sell the stock before you buy again).
 */
class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			if (prices.empty()) {
				return 0;
			}
			int oldi = prices[0];
			int ret = 0;
			for (auto i : prices) {
				int tmp = i - oldi;
				if (tmp > 0) {
					ret += tmp;
				}
				oldi = i;
			}
			return ret;
		}
};

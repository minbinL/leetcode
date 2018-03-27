// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
#include "all_header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxValue = 0;
        if (len <= 1) {
            return maxValue;
        }
        int lowest = prices[0];
        for (int i = 1; i < len; i++) {
            if (prices[i] - lowest > maxValue) {
                maxValue = prices[i] - lowest;
            }
            if (lowest > prices[i]) {
                lowest = prices[i];
            }
        }
        return maxValue;
    }
};

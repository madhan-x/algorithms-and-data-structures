#include <stdio.h>

// Best Time to Buy and Sell Stock
// Time Complexity: O(n)
// Space Complexity: O(1)

int maxProfit(int prices[], int n) {
    int min_price = prices[0];
    int max_profit = 0;

    for(int i = 1; i < n; i++) {
        if(prices[i] < min_price) {
            min_price = prices[i];
        }

        int profit = prices[i] - min_price;

        if(profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}

int main() {
    int n;
    scanf("%d", &n);

    int prices[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    printf("%d\n", maxProfit(prices, n));
    return 0;
}

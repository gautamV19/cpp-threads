#include <stdio.h>

// Function to find the maximum profit earned by buying and
// selling shares any number of times
int findMaxProfit(int price[], int n, int x)
{
    int profit = 0;

    // initialize the local minimum to the first element's index
    int j = 0;

    for (int i = 1; i < n; i++)
    {
        if (price[i - 1] - price[i - 1] * x * 0.01 > price[i] - price[i] * x * 0.01)
        {
            j = i;
        }
        if (price[i - 1] - price[i - 1] * x * 0.01 <= price[i] - price[i] * x * 0.01 &&
            (i + 1 == n || price[i] - price[i] * x * 0.01 > price[i + 1] - price[i + 1] * x * 0.01))
        {
            profit += (price[i] - price[j] - price[i] * x * 0.01 - price[j] * x * 0.01);
        }
    }

    return profit;
}

int main()
{
    int price[] = {1, 5, 2, 3, 7, 6, 4, 5};
    int n = sizeof(price) / sizeof(price[0]);

    printf("\nTotal profit earned is %d", findMaxProfit(price, n, 1));

    return 0;
}

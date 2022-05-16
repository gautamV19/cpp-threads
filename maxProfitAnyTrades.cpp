#include <stdio.h>

// Function to find the maximum profit earned by buying and
// selling shares any number of times
int findMaxProfit(int price[], int n)
{
    int profit = 0;

    // initialize the local minimum to the first element's index
    int j = 0;

    for (int i = 1; i < n; i++)
    {
        if (price[i - 1] > price[i])
        {
            j = i;
        }
        if (price[i - 1] <= price[i] &&
            (i + 1 == n || price[i] > price[i + 1]))
        {
            profit += (price[i] - price[j]);
        }
    }

    return profit;
}

int main()
{
    int price[] = {1, 5, 2, 3, 7, 6, 4, 5};
    int n = sizeof(price) / sizeof(price[0]);

    printf("\nTotal profit earned is %d", findMaxProfit(price, n));

    return 0;
}

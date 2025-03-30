#include <stdio.h>

void sortDescending(double ratio[], float weight[], float value[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                float tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                float tempValue = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempValue;
            }
        }
    }
}

float knapsack(int capacity, float pw[], float weight[], float profit[], int n)
{
    double ratio[n];
    double totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        ratio[i] = (double)profit[i] / weight[i];
    }

    sortDescending(ratio, weight, profit, n);

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        if (weight[i] <= capacity)
        {
            capacity -= weight[i];
            totalValue += profit[i];
        }
        else
        {
            totalValue += profit[i] * ((double)capacity / weight[i]);
            capacity = 0;
        }
    }

    return totalValue;
}
int main()
{
    int n, c;
    printf("Enter the number of the objects: \n");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: \n");
    scanf("%d", &c);
    float pw[n], profit[n], weight[n];
    printf("Enter the value of profit and weight table: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f", &profit[i], &weight[i]);
    }

    for (int i = 0; i < n; i++)
    {
        pw[i] = (profit[i] / weight[i]);
    }
    printf("The total profit is: %.1f", knapsack(c, pw, weight, profit, n));
    return 0;
}
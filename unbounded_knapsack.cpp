#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[], int val[], int w, int n)
{
    int t[n + 1][w + 1];
    if (n == 0 || w == 0)
        return 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - wt[i-1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
  return t[n][w];
}
int main()
{
    int a[4] = {1, 2, 3, 4};
    int b[4] = {1, 3, 5, 8};
    int w = 7;
    int c = knapsack(a, b, w, 4);
    cout << c;
}
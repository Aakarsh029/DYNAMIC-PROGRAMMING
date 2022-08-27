#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[], int w, int n)
{
    int t[n + 1][w + 1];
    if (n == 0 || w == 0)
        return 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;

            if(j==0)
            t[i][j]=1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] =  t[i-1][j - wt[i-1]] + t[i - 1][j];
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
    int a[4] = {1,1,2,3};
    int diff = 1;
    int sum=0;
    for(int i=0;i<4;i++)
    {
        sum+=a[i];
    }
    int s1=(diff+sum)/2;
    int s2=(sum-diff)/2;
    int c = knapsack(a,  s1, 4);
    int d = knapsack(a , s2 , 4);
    cout << c*d<<endl;
} 
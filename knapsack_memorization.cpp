#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int knapsack(int wt[], int val[], int w, int n)
{
    int t[n+1][w+1];
    memset(t, -1, sizeof(t));
    if(t[n][w]!=-1)
    return t[n][w];
    if(wt[n-1]<=w)
    return t[n][w]=max(val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    else if(wt[n-1]>w)
    return t[n][w]=(knapsack(wt,val,w,n-1));
} 
int main()
{
    int a[4]={1,2,3,4};
    int b[4]={1,3,5,7};
    int w=7;
    int c=knapsack(a,b,w,4);
    cout<<c;
}
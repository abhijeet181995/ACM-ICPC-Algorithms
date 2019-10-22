#include <iostream>
using namespace std;
int mincoins(int coins[],int m,int n)
{   int dp[1000]={0};
    for(int i=0;i<m;i++)
    {
        dp[coins[i]]=1;
    }
    for (int i=1,i<=n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (i>=coins[i])
            dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }
    }
    return dp[n];
}

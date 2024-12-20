/*
     lets see the reccurance relation of the fibonacci is
     f(n)=f(n-1)+f(n-2) for all n >=2; f(1)=1,f(0)=1 1 1 2 3 5 8...
     now the tree will be

             f(5)
         f(4)     f(3)
      f(3)  f(2) f(2) f(1)
    f(2) f(1)

    so the
*/
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int fiboRec(int n)
{
    if (n <= 1)
        return 1;
    return fiboRec(n - 1) + fiboRec(n - 2);
}
// Now we observe that in the recusrsion tree there are many repateting values so we can memoize the solution 
// for memoization we can use the DP array if we have alreay visited one we'll use the same and optimise the solution
// to T.C O(N), S.C O(N)

int fiboMemo(int n,vector<int>&dp)
{
    if(n<=1) return n;
    if(dp[n]!= -1) return dp[n];
    return dp[n]=fiboMemo(n-1,dp)+fiboMemo(n-2,dp);
}

//Tabulation 
int fibTab(int n)
{
    vector<int>dp(n+1,-1);
    dp[0]=0,dp[1]=1; // base cases
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// Space Optimization 
// as we can see d[i] = dp[i-1]+dp[i-2] which is nothing but curr=prev + prev2
int fibSpace(int n)
{
    if(n<=1) return n;
    int prev1=0,prev2=1;
    int curr;
    for(int i=2;i<=n;i++)
    {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main()
{
    int n;
    cin >> n;
    vector<int>dp(n+1,-1);
    // cout<<fiboMemo(n,dp);
    // cout<<fibTab(n);
    // cout<<fiboRec(n);
       cout<<fibSpace(n);
    return 0;
}
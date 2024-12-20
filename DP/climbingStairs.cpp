/*
 You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?
*/

#include<iostream>
#include<vector>
using namespace std;

    int climbStairsRec(int n) {
        // Base Case if Stars are less than equal to two
        if(n<2) return 1;
        int st1=climbStairsRec(n-1); // One Step
        int st2=climbStairsRec(n-2); // Two step;
        return st1+st2;
    }
    //Now we need to optimise the above solution we can do the
    // same by using the memoization i.e dp array
    int helper(int n,vector<int>&dp)
    {
        if(n<2) return 1;
        if(dp[n]!= -1) return dp[n];
        int l=helper(n-1,dp);
        int r=helper(n-2,dp);
        return dp[n]=l+r;
    }
    int climbStairsMemo(int n) {
        vector<int>dp(n+1,-1); // Dp array
        return helper(n,dp);
    }
    
// Tabulation approach 
    int climbStairsTab(int n)
    {
        if(n<2) return n;
        vector<int>dp(n+1,-1);
        dp[1]= 1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int main()
    {
        int n;
        cin>>n;
        cout<<climbStairsRec(n);
        cout<<climbStairsMemo(n);
        cout<<climbStairsTab(n);
        return 0;
    }
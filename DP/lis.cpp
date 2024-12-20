/*
     Longest increasing subsequence
     let's say we have a array [10,9,4,6,11,22] so the increasing sub seq could be 10,11,22 or 9,11,22 or 4,6,11,22 th longest
     which is incresing is 4,6,11,22
     Now for each and every index we've choice to either pick or not pick the value a the index but here is a catch
     like we also take care of the condtion that the prev one should be smaller than of the curr ind then we have to
     find the longest of such

*/
#include <iostream>
#include <vector>

using namespace std;
int lis_recur(int ind, int prev, vector<int> &arr)
{
    if (ind == arr.size())
        return 0;                            // i.e we exhausted the array aka base case here
    int len = lis_recur(ind + 1, prev, arr); // Not pick
    if (prev == -1 || arr[prev] <= arr[ind])
        len = max(len, 1 + lis_recur(ind + 1, ind, arr)); // pick condition
    return len;
}
// Now we need to optimise the above solution
// We've observed that ind 1->n and prev -1 -> n-1
// We can think of 2D DP with dp[ind][prev]
// But here is catch that prev ind can't be negative as in array we cant have the negative ind
// So we'll just shift the inded by +1
int lis_memo(int ind, int prev, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == arr.size())
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int len = lis_memo(ind + 1, prev, arr, dp);
    if (prev == -1 || arr[prev] <= arr[ind])
    {
        len = max(len, 1 + lis_memo(ind + 1, ind, arr, dp));
    }
    return dp[ind][prev + 1] = len;
}
// Now we need to further optimise the solution to the Tabulation  Approach
int lis_tab(vector<int>&arr,vector<vector<int>>&dp)
{
    if(arr.size()==0) return 0;
    int n=arr.size();
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev=ind-1;prev>= -1;prev--)
        {
            int notTake=dp[ind+1][prev+1];
            int take = 0;
            if(prev== -1|| arr[ind]>=arr[prev])
            {
                take=1+dp[ind+1][ind+1];
            }
             dp[ind][prev+1]=max(take,notTake);
        }
    }
    return dp[0][0];
}
int main()
{
    vector<int> vec = {10, 9, 4, 6, 11, 22};
    /*
         Let's try to make a recursion tree of the same
                            f(0,-1) lis=0
                lis=1  f(1,0)       f(1,-1) lis=0
                     f(2,0)     {9}f(2,1) f(2,-1){}
                    f(3,0)   {9}f(3,1)   f(3,-1){}
                   f(4,0)   {9}f(4,1)
       {10,11}  f(5,1)    {9,11}f(5,4)
     {10,11,22} f(6,5)  {9,11,22}f(6,5)
    */
    // cout << lis_recur(0, -1, vec);
    int n=vec.size();
    // vector<vector<int>>dp(n,vector<int>((n+1),-1));
    // cout<<lis_memo(0,-1,vec,dp);
    vector<vector<int>>dp(n+1,vector<int>((n+1),0));
    cout<<lis_tab(vec,dp);
    return 0;
}
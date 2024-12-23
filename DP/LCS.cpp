/*
    Longest common subsequence 
    Approach we can think of two indexes ind1 and ind2
    of two respective array arr1,arr2 the we compare
    it with both from back side  if they are equal then we increment
    otherwise we call them separately 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int lcs_recur(int ind1,int ind2,string &s1,string &s2)
{
    if(ind1<0 || ind2<0) return 0;
    if(s1[ind1]==s1[ind2]) 
    return 1+lcs_recur(ind1-1,ind2-1,s1,s2);//If both matched then we 
    // move both pointer together
    else 
    return max(lcs_recur(ind1-1,ind2,s1,s2),lcs_recur(ind1,ind2-1,s1,s2));
}
int lcs_memo(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp)
{
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!= -1 )return dp[ind1][ind2];
    if(s1[ind1]==s1[ind2]) 
    return dp[ind1][ind2]=1+lcs_recur(ind1-1,ind2-1,s1,s2);//If both matched then we 
    // move both pointer together
    else 
    return dp[ind1][ind2]=max(lcs_recur(ind1-1,ind2,s1,s2),lcs_recur(ind1,ind2-1,s1,s2));
}
int main()
{
    string s1="aab";
    string s2="ccd";
    int n1=s1.length();
    int n2=s2.length();
    // cout<<lcs_recur(n1-1,n2-1,s1,s2);
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    cout<<lcs_memo(n1-1,n2-1,s1,s2,dp);
    return 0;
}
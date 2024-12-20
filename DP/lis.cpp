/*
     Longest increasing subsequence
     let's say we have a array [10,9,4,6,11,22] so the increasing sub seq could be 10,11,22 or 9,11,22 or 4,6,11,22 th longest 
     which is incresing is 4,6,11,22
     Now for each and every index we've choice to either pick or not pick the value a the index but here is a catch
     like we also take care of the condtion that the prev one should be smaller than of the curr ind then we have to 
     find the longest of such 

*/
#include<iostream>
#include<vector>

using namespace std;
int lis_recur(int ind,int prev,vector<int>&arr)
{
    if(ind == arr.size()) return 0; //i.e we exhausted the array aka base case here 
    int len= lis_recur(ind+1,prev,arr); // Not pick 
    if(prev== -1||arr[prev]<=arr[ind]) 
    len=max(len,1+lis_recur(ind+1,ind,arr)); // pick condition 
    return len;
}
int main()
{  
    vector<int>vec={10,9,4,6,11,22};
    cout<<lis_recur(0,-1,vec);
    return 0;
}
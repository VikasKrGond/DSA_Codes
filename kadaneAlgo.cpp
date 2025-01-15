/*
   The Problem is for the Maximum subarray sum
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int kadaneAlgo(vector<int>&arr)
{
    int n=arr.size();
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum > maxi)
        {
            maxi=sum;
        }
        if(sum<0){
           sum=0;
        }
    }
    return maxi;
}
int main()
{
    vector<int>arr={ -2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<kadaneAlgo(arr);
    return 0;
}
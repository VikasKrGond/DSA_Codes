#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void subSeqKSum(int ind, vector<int> &arr, vector<int> &ds, int target, int sum, vector<vector<int>> &ans)
{
    if (ind >= arr.size())
    {
        if (sum == target)
        {
            ans.push_back(ds);
        }
        return;
    }
    ds.push_back(arr[ind]);
    subSeqKSum(ind + 1, arr, ds, target, sum + arr[ind], ans);
    ds.pop_back();
    subSeqKSum(ind + 1, arr, ds, target, sum, ans);
}

// Count total number of sub Seq with K sum

int countSubSeqKSum(int ind,int sum,int k,vector<int>&arr)
{
    if(ind==arr.size())
    {
        if(sum == k) return 1;
        else return 0;
    }
    sum+=arr[ind];
    int l=countSubSeqKSum(ind+1,sum,k,arr);
    sum-=arr[ind];
    int r=countSubSeqKSum(ind+1,sum,k,arr);
    return l+r;
}
int main()
{
    vector<int> arr = {2, 4, 3, 6, 1};
    vector<int> ds;
    vector<vector<int>> ans;
    subSeqKSum(0, arr, ds, 7, 0, ans);
    int k=7;
    cout<<"Total Subsequence  with sum "<<k<<" are : "<<countSubSeqKSum(0,0,k,arr)<<'\n';
    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
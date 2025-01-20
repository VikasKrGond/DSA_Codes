/*
   Given array we need to find the pair with the 
   Target Value
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> twoSum(vector<int>&arr,int target)
{
    sort(arr.begin(),arr.end());
    int l=0,r=arr.size()-1;
    vector<vector<int>>ans;
    while(l<=r)
    {
        if(target ==arr[l]+arr[r]) ans.push_back({arr[l],arr[r]});
        else if(target<arr[l]+arr[r])
        {
            r--;
        }
        else{
            l++;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={1,2,3,4,5,6,7};
    int target=7;
    vector<vector<int>>ans=twoSum(arr,target);
    for(auto i:ans)
    {
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;
}

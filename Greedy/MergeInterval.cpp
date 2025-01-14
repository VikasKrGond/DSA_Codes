/*
   Given two arrays arrival and departure arrays 
   we need to find the minimum number of platform
   requred to accomodate the trains 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Approach is simple just sort the arrays then
// Check if arrival time is less than the departure time
// then we need another platform 

int minPlat(vector<int>&arrival,vector<int>&departure)
{
    int cnt=1;
    int ans=1;
    int i=0,j=1;
    int n=arrival.size();
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    while(i<n && j<n)
    {
        if(arrival[i] <=departure[j])
        {
            cnt++;
            i++;
        }
        else{
            cnt--; 
            j++;
        }
        ans=max(cnt,ans);
    }
    return ans;
}
int main()
{
    vector<int>arrival={10,12,12,15,16},departure={14,27,13,17,11};
    cout<<minPlat(arrival,departure);
    return 0;
}
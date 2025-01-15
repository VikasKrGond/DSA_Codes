/*
   You have given an array which has repeating and some missing elements you  need to return the pair 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<numeric>
using namespace std;
int op(int a,int b)
{
    return a^b;
}
pair<int,int> missAndRepeat(vector<int>&arr)
{
    int miss= -1,repeat= -1;
    int res=0;
    int n=arr.size();
    unordered_map<int,int>ump;
    int sum= accumulate(arr.begin(),arr.end(),0);
    int xoR=accumulate(arr.begin(),arr.end(),0,op); // Custom op for perpoming XOR
    for(int &i: arr)
    {
        ump[i]++;
        res=res^i;
        if(ump[i]==2){
            repeat=i;
        }
    }
    // One Mathematical solution could be To find the sum of first N then subtract it with the sum - repating val
    int sumOfN=(n*(n+1))>>1;
    miss= sumOfN - (sum - repeat);
    return {miss,repeat};
}
int main()
{
    vector<int>arr={1,2,3,4,4,6};
    pair<int,int>p=missAndRepeat(arr);
    cout<<"Missing is : "<<p.first<<" and Repeating is : "<<p.second<<endl;
    return 0;
}
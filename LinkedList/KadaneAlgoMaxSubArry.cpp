#include<iostream>
#include<algorithm>
using namespace std;
int kadaneAlgo(int arr[],int n)
{
    int res=arr[0];
    int maxEnding=arr[0];
    for(int i=1;i<n;i++)
    {
        maxEnding = max(maxEnding+arr[i],arr[i]);
        res=max(maxEnding,res);
    }
    return res;
}
int main()
{
    int arr[]={2,3,-8,7,-1};

    return 0;
}
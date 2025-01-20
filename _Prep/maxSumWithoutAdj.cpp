/*
     Given an array arr containing positive integers.
     Find the maximum sum of any possible subsequence such that no two numbers in
     the subsequence should be adjacent in array arr.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int mxSumSub(int ind, int sum, vector<int> &arr)
{
    if (ind >= arr.size())
    {
        return 0;
    }
    // Pick Condition
    int pick =arr[ind]+mxSumSub(ind + 2, sum, arr);
    // Not Pick
    int notPick=mxSumSub(ind + 1, sum, arr);
    return max(pick,notPick);
}
int main()
{
    vector<int> arr = {3,2,7,10};
    // vector<int> ans;
    cout<<mxSumSub(0, 0, arr);
    cout << '\n';
    return 0;
}
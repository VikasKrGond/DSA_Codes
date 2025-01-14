/*
     We've given the array with negative number
     we've to find the first negative number in the
     k size sub array..
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> firstNegKwindow(vector<int> &arr, int k)
{
    vector<int> res;
    int n = arr.size();
    int i = 0, j = 0, neg_ele = 0;
    bool neg_flag=false;
    while (j < n)
    {
        if (arr[j] < 0 && !neg_flag){
            neg_ele = arr[j];
            neg_flag=true;
        }
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            res.push_back(neg_ele);
            neg_ele=0;
            neg_flag=false;
            i++;
            j++;
        }
    }
    return res;
}
vector<int> brutForceApproach(vector<int> &arr, int k)
{
    // We'll rull a nested for lopp then we'll put
    //  the conditon to check
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (i + k < n)
        {
            for (int j = i; j <= i + k; j++)
            {
                if (arr[j] < 0)
                    ans.push_back(arr[j]);
            }
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> res;
    // res = brutForceApproach(arr, k);
    res=firstNegKwindow(arr,k);
    for (auto &it : res)
        cout << it << " ";
    cout << endl;
    return 0;
}
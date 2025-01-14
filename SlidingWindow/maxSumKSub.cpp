/*
   We wanted to find the subarray of size k with max
   sum
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int maxSumSubK(vector<int> &arr, int k)
{
    int i = 0, j = 0, sum = 0, mx = 0;
    while (j < arr.size())
    {
        sum = sum + arr[j];
        if (j - i + 1 < k)
            j++;                 // for Window size K
        else if (j - i + 1 == k) // when we got the window size then we perform the operations
        {
            mx = max(sum, mx);
            sum = sum - arr[i]; // removing the earlier sum
            i++;
            j++;
        }
    }
    return mx;
}
vector<int> printMaxSumSub(vector<int> &arr, int k)
{
    int i = 0, j = 0, sum = 0, mx = 0;
    while (j < arr.size())
    {
        sum = sum + arr[j];
        if (j - i + 1 < k)
            j++;                 // for Window size K
        else if (j - i + 1 == k) // when we got the window size then we perform the operations
        {
            mx = max(sum, mx);
            sum = sum - arr[i]; // removing the earlier sum
            i++;
            j++;
        }
    }
    return {i, j};
}
int main()
{
    int n, k;
    cout << "Enter n and  k: ";
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    cout << "Maxmimum subarray sum with size " << k << " is : " << maxSumSubK(arr, k);
    cout << "\n Do you want to Print the Subarray: ";
    string ch;
    cin >> ch;
    int x = 0;
    if (ch == "Yes" || ch == "YES" || ch == "yes")
        x = 1;
    if (x == 1)
    {
        vector<int> vec;
        vec = printMaxSumSub(arr, k);
        int l = vec[0];
        int r = vec[1];
        cout << "The respective subarry is : ";
        for (int i = l; i <= r; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "\n***********You Exited from the Program********";
    }
    return 0;
}
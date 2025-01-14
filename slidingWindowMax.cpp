/*
We've given array in which we need to find the maximum
element in k size window.So there are total N-K ans
*/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<int> slidingWindowMaxK(vector<int> &arr, int k)
{
    deque<int> dq; // to store the index for monotonic
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        if (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_front(i);
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 7, 1, 6};
    int k = 3;
    vector<int> ans = slidingWindowMaxK(arr, k);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}
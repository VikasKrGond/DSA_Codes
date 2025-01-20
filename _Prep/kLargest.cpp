/*
    Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order.

Examples

Input: arr[] = [12, 5, 787, 1, 23], k = 2
Output: [787, 23]
Explanation: 1st largest element in the array is 787 and second largest is 23.
Input: arr[] = [1, 23, 12, 9, 30, 2, 50], k = 3
Output: [50, 30, 23]
Explanation: Three Largest elements in the array are 50, 30 and 23.
Input: arr[] = [12, 23], k = 1
Output: [23]
Explanation: 1st Largest element in the array is 23.
Constraints:
1 ≤ k ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> kLargest(vector<int>&arr,int k)
{
    // We can use the priority Queue to store the element and maintain the size of the queue 
    // By poping out the extra element then print the k element 
    priority_queue<int,vector<int>,greater<int>>pq; // Max Heap it'll store the element i
    vector<int>ans;//to store the ans 
    for(int &it:arr)
    {
        pq.push(it);
    }
    while(pq.size()>k) pq.pop();
    while(!pq.empty())
    {
         ans.push_back(pq.top());
         pq.pop();
    }
    return ans;
}
int main()
{
    vector<int>arr={3,11,23,-1,29,101,0};
    int k=2;
    vector<int>ans=kLargest(arr,k);
    for(int it:ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}
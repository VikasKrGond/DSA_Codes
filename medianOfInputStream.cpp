/*
    You Have given Stream of integers you need to find the median of the Stream at any instant
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> minHeap;
priority_queue<int, vector<int>, greater<int>> maxHeap;
void inPutStream(int val)
{
    if (maxHeap.empty() || maxHeap.top() < val)
    {
        maxHeap.push(val);
    }
    else
    {
        minHeap.push(val);
    }
    if (maxHeap.size() > minHeap.size() + 1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if (minHeap.size() > maxHeap.size() + 1)
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}
double median()
{
    if (minHeap.size() == maxHeap.size())
    {
        if (minHeap.size() == 0)
        {
            return 0.0;
        }
        else
        {
            return (double)(minHeap.top() + maxHeap.top()) / 2;
        }
    }
    else
    {
        return minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
    }
}
int main()
{
    inPutStream(2);
    inPutStream(7);
    inPutStream(4);
    cout<<median()<<"\n";
    inPutStream(1);
    inPutStream(11);
    inPutStream(6);
    //{1,2,4,6,7,11}
    cout<<median()<<"\n";


    return 0;
}
/*
     We've given array wich has only three types
     of element 0,1 or 2 we need to sort the Array
     with constant space and Linear Complexity
*/
#include <iostream>
#include <vector>
using namespace std;
/*
    Optimal way to solve the Problem is using the
    Dutch National Flag Algorithm
    we have three pointer low,high,mid
    Intially low and mid at 0th index and High n-1 th index
    Now we have three different cases
    Case 1 when arr[mid]=0 then we need to swap
    arr[mid],arr[low] and increment mid and low
    Case 2 when arr[mid]=1 then we just have to
    increment mid
    Case 3 if arr[mid]=2 then we need to swap
    arr[mid] and arr[high] and decrement high
*/
void swap(int *ptr1, int *ptr2)
{
    *ptr1 = *ptr1 ^ *ptr2;
    *ptr2 = *ptr2 ^ *ptr1;
    *ptr1 = *ptr1 ^ *ptr2;
}
// T.C O(N), S.C O(1)
void Sort012(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int>arr={2,2,2,0,0,1,1,1,1,1};
    Sort012(arr);
    for(int &it:arr) cout<<it<<" ";
    cout<<'\n';
    return 0;
}
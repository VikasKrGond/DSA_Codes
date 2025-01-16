/*
    We've given two sorted arrays we wanted to merge
    the array  without using extra space
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
   To solve the problem idea is simple use two pointers i at arr1 0th index and
   j for arr2 at 0th index then we compare the value if value
   at arr1 is greater than arr2 then we swap the values and incremnt
   the pointer is not then we increment the arr1 pointer
   Dry Run of the Approach :
   {7,9,11,15} {3,12,16}
    i=n-1, j=0 if arr[i] > arr[j] then swap and i--,j++
    otherwise j++
*/
void swapNum(int &p1, int &p2)
{
    p1 = p1 ^ p2;
    p2 = p1 ^ p2;
    p1 = p1 ^ p2;
}
void mergeSorted(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = n1 - 1, j = 0;
    int cnt=0;
    while (i >= 0 && j < n2)
    {
        if (arr1[i] > arr2[j])
        {
            swapNum(arr1[i], arr2[j]);
            sort(arr1.begin(), arr1.end());
            sort(arr2.begin(), arr2.end());
            cnt++;
        }
        else
        {
            i--;
            j++;
        }
    }
    cout<<"Count Sorting: "<<cnt<<" \n";
    for (int i : arr1)
        cout << i << " ";
    cout << " ";
    for (int i : arr2)
        cout << i << " ";
}
//T.C is min(n1,n2)*(n1logn1+n2logn2);
int main()
{
    vector<int> arr1 = {18,20,22,24};
    vector<int> arr2 = {-2,0,21,25};
    mergeSorted(arr1, arr2);
    return 0;
}
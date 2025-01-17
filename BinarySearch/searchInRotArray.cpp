/*
    Given a rotated array we need to find the target if exist
    in O(logN) time
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int searchInRotArray(vector<int> &arr, int target)
{
    /*
       Our Algorithm is simple it is based on the observation
       that even a rotated matrix is divided into two half in which
       one half is always sorted. First we'll check whether the element
       is present at mid or not if not then we'll check whether the
       left subarray is sorted or not if not then the right half
       is definitely sorted. in the sorted half we then check
       whether the target belongs to that half or not if yes
       then we update the mid as per the half other wise we need
       to update the low or high. If we traverse the entire array
       without getting the target then we return the -1.
    */
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == target)
            return mid;
        // Check if Left half is sorted or not
        if (arr[mid] >= arr[low])
        {
            // Checking whether the target belongs to the left half or not
            if (arr[low] <= target && arr[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // If the right half is sorted then
        else
        {
            // If lies in right half
            if (arr[mid] <= target && arr[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr={5,6,7,0,1,2};
    int target=9;
    cout<<searchInRotArray(arr,target);
    return 0;
}
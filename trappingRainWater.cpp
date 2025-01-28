/*
   This Question asked me in the Amazon Interview
   Here is my Final Solution using Two Pointer Approach Handeling Edge Cases as we'll
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int trappingRain(vector<int> &heights)
{
    int n = heights.size();
    int left_max = heights[0];
    int right_max = heights[n - 1];
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j)
    {
        if (left_max <= right_max)
        {
            if (left_max >= heights[i])
            {
                ans += (left_max - heights[i]);
            }
            left_max = max(left_max, heights[i]);
            i++;
        }
        else
        {
            if (right_max >= heights[i])
            {
                ans += (right_max - heights[j]);
            }
            right_max = max(right_max, heights[j]);
            j--;
        }
    }
    return ans;
}

// My Leetcode Solution
int trappingRain(vector<int> &heights)
{
    int n = heights.size();
    int left_max = heights[0];
    int right_max = heights[n - 1];
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j)
    {
        if (left_max <= right_max)
        {
            ans += (left_max - heights[i]);
            i++;
            left_max = max(left_max, heights[i]);
        }
        else
        {
            ans += (right_max - heights[j]);
            j--;
            right_max = max(right_max, heights[j]);
        }
    }
    return ans;
}

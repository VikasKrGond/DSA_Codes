#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// When there is only one majority element or not
/*
     Brute is : With Extra space to store the frequency
     then find which has freq > n/2 that will be the majority element

     Optimal : Using Moore's Algorithm
     let say we ele=a[i]
     In Moore ALso we assume that ele is already a
     majority element so if we encounter any other
     we decrement the counter till the time it become
     zero at any instance then we choose the another
     element as the major and repeat the process till we
     exhaust the list then the remaning in the element is the
     majority element we can extend the same algo for 2 major ele also
     When count become Zero change the number
     It actually works as cancelling of the number
     the number that is remaning will be the majority
    case 1 :  if(cnt == 0)
       ele=a[i]
    case 2:  if(el == a[i]) cnt++;

    case 3: cnt--;


*/
int majority1(vector<int> &arr)
{
    //{1,2,3,2,4,2,5,2,1}
    int cnt = 0;
    int majority_element = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            majority_element = arr[i];
        }
        if (majority_element == arr[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    // Checking if the element is having the freq > n/2 or
    //  As per also if there is any major element then it has
    //  to be that we got from algo otherwise not.
    cnt = 0;
    for (int it : arr)
    {
        if (it == majority_element)
        {
            cnt++;
        }
    }

    return cnt > n >> 1 ? majority_element : -1;
}

/*
Majority Element  2 i.e there are can be at manx two majority element in array
So we can extend the Above Moore Algo for two Majority element
So After applying the algo we'll check the frequency of the both
element wheter they satify or not
*/
pair<int, int> major_2_Eelement(vector<int> arr)
{
    int n = arr.size();
    int ele_1 = 0, ele_2 = 0;
    int cnt_1 = 0, cnt_2 = 0;
    // First we check if count is zero then we update the element to 1 and 2
    for (int i = 0; i < n; i++)
    {
        if (ele_1 == arr[i])
        {
            cnt_1++;
        }
        else if (ele_2 == arr[i])
        {
            cnt_2++;
        }
        else if (cnt_1 == 0)
        {
            ele_1 = arr[i];
            cnt_1++;
        }
        else if (cnt_2 == 0)
        {
            ele_2 = arr[i];
            cnt_2++;
        }
        else
        {
            cnt_1--;
            cnt_2--;
        }
    }
    //Now We'll check whether the obtained numbers are eliblie or not
    cnt_1=0;
    cnt_2=0;
    for(int i=0;i<n;i++)
    { 
        if(arr[i]==ele_1) cnt_1++;
        if(arr[i]==ele_2) cnt_2++;
    }
    pair<int,int>ans={-1,-1};
    if(cnt_1 >n/3) ans.first=ele_1;
    if(cnt_2 > n/3) ans.second=ele_2;
    return ans;
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 2, 4, 2, 5, 2, 1};
    // cout << majority1(arr1) << endl;
    vector<int>arr2={9,4,1,3,1,5,0,2,1};
    pair<int,int>ans=major_2_Eelement(arr2);
    cout<<ans.first<<" and "<<ans.second<<" \n";
    return 0;
}
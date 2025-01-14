/*
Given a circular integer array A, return the next greater element for every element in A.
 The next greater element for an element x is the first element greater than x that
 we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.
Example 1:

Input: N = 11, A[] = {3,10,4,2,1,2,6,1,7,2,9}

Output: 10,-1,6,6,2,6,7,7,9,9,10

Explanation: For the first element in A ,i.e, 3, the greater element which comes next to it while
 traversing and is closest to it is 10. Hence,10 is present on index 0 in the resultant array.
 Now for the second element,i.e, 10, there is no greater number and hence -1 is it’s next greater element (NGE).
 Similarly, we got the NGEs for all other elements present in A.

Example 2:

Input:  N = 6, A[] = {5,7,1,7,6,0}

Output: 7,-1,7,-1,7,5

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
/*
   Our Approach is simple we are gonna use the monotonic stack to solve the problem. We need to find the element
   Which is greater than the current one so to do so we need to see from left to right but we can't do it in linear
   time so we can traverse in reverse fashion i.e from right to left then at every instane we have already traversed
   the element on the right.Initally when the stack is empty we mark the nge of the index as -1, then we push the element
   into the stack then move from the next element then we compare the top of the stack if the top of the stack is
   greater than current element then we mark the top of the stack as the nge of the particular index and push the current
   element into the stack, other case if the current element is greater than or equal to the top of the stack then
   we need to pop it out from the stack till the time we encounter the element in the stack i.e is strictly greater
   than the current element if we are unable to find i.e stack beacme empty we mark nge as -1 for the index and push the
   element in the stack and move
*/
// T.C O(2N) as inner while loop will run at max N time that too when the all elements of array are in Decreasing order i.e worst case
// S.C (N)+O(N) for stack and array
vector<int> nexGreateElement(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n);
    nge[n - 1] = -1;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (st.top() > arr[i]) // Case 1: When the top of stack is grater than current element
        {
            nge[i] = st.top();
            st.push(arr[i]); // Storing elements in stack in strictly decreasing order
        }
        else
        {
            while (i >= 0 && !st.empty() && st.top() <= arr[i]) // To maintain the strictly decreasing order
            {
                st.pop();
            }
            if (st.empty())
                nge[i] = -1;
            else
            {
                nge[i] = st.top();
                st.push(arr[i]);
            }
        }
    }
    return nge;
}

// Let's try to write a code for the circular array
//  We just double the array i.e the llast index will be 2n-1 then we start pushing into the stack as the above one like if the top of the stack
//  is greater than the current then we push it into the stack otherwise pop it out and we need to find the nge from the n-1 th index of
//  the array
//T.C O(4N)
//S.C O(2N)+O(N)
vector<int> nextGreaterElCircular(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> nge(n);
    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        int ind = i % n;
        while(!st.empty() && st.top() <= arr[ind])
        {
            st.pop();
        }
        if(i<n)
        {
            nge[i]=st.empty()? -1 : st.top();
        }
            st.push(arr[ind]);
    }
    return nge;
}
int main()
{
    vector<int> arr = {2, 10, 12, 1, 11};
    // vector<int> nge = nexGreateElement(arr);
    vector<int> nge = nextGreaterElCircular(arr);
    for (int &i : nge)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
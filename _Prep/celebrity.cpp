/*
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[0 1 0], [0 0 0], [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.
Input: mat[][] = [[0 1], [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
Input: mat[][] = [[0]]
Output: 0
*/
#include <iostream>
#include <vector>
using namespace std;
/*
    Brute we make two array iKnow and knowMe array
    then we store whome i know and i is know by whom
    then we check if we found the pair with iKonw =0 and knowMe= n-1
    then i is the clebrity
*/
// T.C O(N^2)
// S.C O(2N)
int celebrityBrute(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<int> knowMe(n), iKnow(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1) // i knows the j
            {
                iKnow[i]++;
                knowMe[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (iKnow[i] == 0 && knowMe[i] == n - 1)
            return i;
    }
    return -1;
}
/*
   For Optimal Solution we Use elimination
   We first defined two pointer top=0 and down=n-1
   then if top knows down which means top can't be celebrity then incement top = top+1,
   Similarly if down knows top then down can't be clebrity
   If both know each other then both can't be celebrity
   When top == down then we check that
   if top is known be everyone i.e mat[i][top]=1 and
   mat [top][i]=0 for all and when i=top then mat[top][top] showld be zero
   if all these satisfy then top is celebrity otherwise
   there is no celebrity
*/
int celebrityOptimal(vector<vector<int>> &mat)
{
    int n = mat.size();
    int top = 0, down = n - 1;
    while (top < down)
    {
        if (mat[top][down] == 1)
        {
            top++;
        }
        else if (mat[down][top] == 1)
            down--;
        else
        {
            top++;
            down--;
        }
    }
    if(top>down) return -1; //there is no celebrity
    else{
        for(int i=0;i<n;i++)
        {
            if(i==top) continue;
            else if(mat[top][i]==0 && mat[i][top]==1) continue;
            else
            return -1;
        }
    }
    return top;
}
int main()
{
    vector<vector<int>> mat = {{1, 0} ,{0, 1}};
    // cout << celebrityBrute(mat);
    cout<<celebrityOptimal(mat);
    return 0;
}
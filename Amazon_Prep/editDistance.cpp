/*
Edit Distance : The Problem is we've given
Two String S1 and S2 We've to converst S1 into S2
We've three operation either we can delete or replace or insert
Let's say each operation costs 1
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
/*
    Approach We'll start with matching the string from
    Back if it match we move the pointers
    otherwise we'll perform  all 3 opertations and
    take the min
*/
int edit_Distance(string s1, string s2, int ptr1, int ptr2)
{
    // Base Case
    if (ptr1 < 0)
        return 1 + ptr2; // All insert Operation
    if (ptr2 < 0)
        return 1 + ptr1; // All Delete Operation
    // If matches
    if (s1[ptr1] == s2[ptr2])
    {
        return 0 + edit_Distance(s1, s2, ptr1 - 1, ptr2 - 1);
    }
    // If it does'nt matches then we can try all three ways
    //  Insert,Delete and Update
    return 1 + min(
                   /*
                      For Insert let's say we insert the character at imaginary index that
                      matches the ptr2 then we hit the first case so we can decrement both
                      so after decrementing the imaginary one we still at the orignal
                      but in the s2 we've decremntd by one so ptr1,ptr2-1

                      For Delete We delete the element at ptr1 so that that we can match
                      the other one so which means we need to decremnt the ptr i.r ptr1-1,ptr2

                      For Replace
                      Let's say we replace the char at ptr1 to the element at ptr2 then
                      we hit the first case i.e we decrement both ptr, i.e ptr1-1,ptr2-1
                   */
                   {edit_Distance(s1, s2, ptr1, ptr2 - 1),     // Insert
                    edit_Distance(s1, s2, ptr1 - 1, ptr2),     // Delete
                    edit_Distance(s1, s2, ptr1 - 1, ptr2 - 1)} // Replace
               );
}
// Now we need to memoization of the above code
int edit_Dis_Memo(string &s1, string &s2, int ptr1, int ptr2, vector<vector<int>> &dp)
{
    if (ptr1 < 0)
        return 1 + ptr2; // Insert all characters
    if (ptr2 < 0)
        return 1 + ptr1; // Delete all characters
    if (dp[ptr1][ptr2] != -1)
        return dp[ptr1][ptr2];
    if (s1[ptr1] == s2[ptr2])
    {
        return dp[ptr1][ptr2] = 0 + edit_Dis_Memo(s1, s2, ptr1 - 1, ptr2 - 1, dp);
    }
    return dp[ptr1][ptr2] = 1 + min({edit_Dis_Memo(s1, s2, ptr1, ptr2 - 1, dp), edit_Dis_Memo(s1, s2, ptr1 - 1, ptr2, dp), edit_Dis_Memo(s1, s2, ptr1 - 1, ptr2 - 1, dp)});
}
int main()
{
    string s1 = "horse";
    string s2 = "ros";
    int ptr1 = s1.length() - 1;
    int ptr2 = s2.length() - 1;
    // DP Table
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    cout << edit_Distance(s1, s2, ptr1, ptr2);
    // cout << edit_Dis_Memo(s1, s2, ptr1, ptr2, dp);
    return 0;
}
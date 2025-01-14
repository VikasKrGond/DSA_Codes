/*
 Minimum Consecutive days for which the stocks price
 was less than or equal to the current day
 Stock 
    Max Conseutvive days    Stock Curr Val
 7    1                         7
 2    1                         2
 1    2                         2
 3    2                         3
 3    3                         3
 1    1                         1
 8    7                         8

 BruteForce: at every index count backwards with the
 condtion if(stock[i]<=stock[curr]) cnt++ where 0<=i<=n-1 
  for(int i=size-2;i>=0;i--) T.C. O(No. of Days)
  {
    if(arr[i]<=curr_val) cnt++;
    else break;
  }
  Better Approach: Using the concept of Next Greater element and Previous Greater ELement
  Optimal : 

*/
#include<stack>
#include<iostream>
using namespace std;
// T.C if we have n next call T.C O(2N),SC O(N)
class StockSpan{
    stack<pair<int,int>>st;
    int ind= -1;
    StockSpan()
    {
        ind= -1;
        st.clear();
    }

};
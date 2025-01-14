/*
The weight of N items and their corresponding values are given.
 We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

Example:

Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

Output: 240.00

Explanation: The first and second items  are taken as a whole 
 while only 20 units of the third item is taken. 
 Total value = 100 + 60 + 80 = 240.00
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
   Our Approach is Simple We'll find the ratio of Val/weight
   then we sort it in descending order then we start pusing it
   into the bag till we can make it, then we can divide it 
*/
class Knapsack{
    public: 
    int val;
    int weight;
};
bool static cmp(Knapsack k1,Knapsack k2)
{
    double d1= (double)k1.val/(double)k1.weight;  
    double d2= (double)k2.val/(double)k2.weight; 
    return d1>d2; 
}
double frac_Knapsack(Knapsack knap[],int n,int cap)
{
   sort(knap,knap+n,cmp);
   int weigh=0;
   double val=0.0;
   int curr_wt=0;
   for(int i=0;i<n;i++)
   {
      if(curr_wt+knap[i].weight<=cap)
      {    
        curr_wt+=knap[i].weight;
           val+=knap[i].val;
           cap-=knap[i].weight;
      }
      else{ // We need to split it 
         double rem= ((double)knap[i].val/(double)knap[i].weight)*cap;
         val+=rem;
         break;
      }
   }
   return val;
}
int main()
{
    int n=3;
    Knapsack kn[3];
    vector<int>val={100,60,120};
    vector<int>wt={20,10,30};
    for(int i=0;i<n;i++)
    {
        kn[i].val=val[i];
        kn[i].weight=wt[i];
    }
    int cap=50;
    cout<<"Value of Knapsack is: "<<frac_Knapsack(kn,n,cap);
    return 0;
}

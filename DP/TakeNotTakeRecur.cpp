//
//Pick Not Pick Pattern for the subsequence Print 
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    For every index we having couple of option i.e 2
    so T.C O(2^N)
       S.C O(N) Depth of recursion 
*/
void takeNotTake(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &res)
{
  if (ind == arr.size())
  {
    res.push_back(ds);
    return;
  }
  ds.push_back(arr[ind]);
  takeNotTake(ind + 1, arr, ds, res); // take condition i.e element  added to your subsequence
  ds.pop_back();
  takeNotTake(ind + 1, arr, ds, res); // Not take conditon i.e element not added to your subsequence
}

int main()
{
  vector<int> vec(3);
  vec = {3, 1, 2};
  vector<vector<int>> res;
  vector<int> ds;
  takeNotTake(0, vec, ds, res);
  sort(res.begin(),res.end());
  for (auto it : res)
  {
    for (auto i : it)
      cout << i << " ";
    cout << '\n';
  }
  return 0;
}

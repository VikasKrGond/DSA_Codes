#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
vector<int> arr;
class stockSpan
{
public:
    stockSpan()
    {
        arr.clear();
    }
    int nextEle(int val)
    {
        arr.push_back(val);
        int cnt = 1;
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (arr[i] <= val)
                cnt++;
            else
                break;
        }
        return cnt;
    }
};
// Now we can optimize the code there is an observation
// like if we can somehow able to get the index of
// Previous Greatest element then we can find the span
// by using simple formula like
// ind of curr - indx of prev-great-element
// the concept of pge is similar to the next greater or previous small
// We need to use the stack which will store the
// value in such fashion that it's top will give the
// prev-greater element
int ind;
stack<pair<int, int>> st;
class stockSpan_Optimal
{
public:
    // Stack to store the index and val of the pge
    stockSpan_Optimal()
    {
        ind = -1;
    }
    int nextVal(int val)
    {
        ind = ind + 1; // Incermenting the index
        while (!st.empty())
        {
            if (st.top().first <= val)
                st.pop();
        }
        int res = ind - (st.empty() ? -1 : st.top().second);
        st.push({val, ind});
        return res;
    }
};
int main()
{
    // stockSpan st;
    stockSpan_Optimal st;
    stockSpan_Optimal();
    int n;
    cout << "Enter Span size: ";
    cin >> n;
    while (n--)
    {
        // int val;
        // cin >> val;
        // cout << st.nextEle(val) << '\n';
        int val;
        cin >> val;
        cout << st.nextVal(val) << '\n';
    }

    return 0;
}

/*
   You have given categories in pair like - [[1,1],[2,1],[3,2],[4,1],[5,3].[6,4]] where the pair are [p,c]
   p=product it can be p1,p2,p3,p4... c=category, c1,c2,c3....
*/
/*
   You have given categories in pair like - [[1,1],[2,1],[3,2],[4,1],[5,3].[6,4]] where the pair are [p,c]
   p=product it can be p1,p2,p3,p4... c=category, c1,c2,c3....
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map> 
#include <queue>
using namespace std;

vector<pair<int, int>> arrangeCart(vector<pair<int, int>> &cart)
{
    // Store the freuqncy for each catgory with c->p1,p2....
    unordered_map<int, vector<int>> catMap;
    for (auto &it : cart)
    {
        catMap[it.second].push_back(it.first);
        /*
            1->1,2,4
            2->3
            3->5
            4->6
            Now the size of value vector of catMap gives us the total freq of that particular category
        */
    }

    // Now we need to arrange them in such a order that no two category remain adjacent to each other
    //  to achieve this we'll be storing the date in priority queue and firt arrange the category with
    //  most number of products
    priority_queue<pair<int, int>> pq;
    for (auto &it : catMap)
    {
        pq.push({it.second.size(), it.first}); // Storing them size order
        /*  Freq->Category
              3->1
              1->2
              1->3
              1->4

        */
    }
    vector<pair<int, int>> result;
    pair<int, int> prev = {-1, -1};
    while (!pq.empty())
    {
        auto [count, category] = pq.top();
        pq.pop();
        result.push_back({catMap[category].back(), category});
        count--;
        if (prev.first > 0) // Some category
        {
            pq.push(prev);
        }
        if (count > 0)
        {
            prev = {count, category};
        }
        else
        {
            prev = {-1, -1};
        }
    }
    if (result.size() != cart.size())
    {
        cout << "Not possible to arrange them";
    }
    return result;
}
int main()
{
    vector<pair<int, int>> cart = {
        {1, 1}, {2, 1}, {3, 2}, {4, 2}, {5, 3}, {6, 3}, {7, 3}};
    vector<pair<int, int>> res = arrangeCart(cart);
    for (auto it : res)
    {
        cout << "[" << it.first << " ," << it.second << " ]";
    }
    return 0;
}
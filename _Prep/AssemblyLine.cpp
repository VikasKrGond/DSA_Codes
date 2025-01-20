#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Brute Force Using Recursion 2^N T.C
int assemblyLine_Brute(vector<vector<int>> stations, vector<vector<int>> switch_time, int cl, int csi, int x1, int x2, int n)
{
    // cl =current line 0 for line 1 , 1 for line 2, cs current station index
    //  x1 exit time from 1 and exit time from 2
    if (csi == n - 1) // We reached to the last station index
    {
        if (cl == 0) // we 're at Line 1 the simpley return the time to exit from line 1
            return x1;
        else
        {
            return x2; // We're at end station and exiting via Line 2
        }
    }
    int same_line = assemblyLine_Brute(stations, switch_time, cl, csi + 1, x1, x2, n) + stations[cl][csi + 1];
    int diff_line = assemblyLine_Brute(stations, switch_time, !cl, csi + 1, x1, x2, n) + stations[!cl][csi + 1]+switch_time[cl][csi+1];
    return min(same_line, diff_line);
}

int main()
{
    int n = 4;
    vector<vector<int>> stations{{4, 5, 3, 2}, {2, 10, 1, 4}};
    vector<vector<int>> switch_time{{0, 7, 4, 5}, {0, 9, 2, 8}};
    int e1 = 10; // Time to entry via Line 1
    int e2 = 12; // Time to entry via Line 2
    int x1 = 18; // Tie Spend on exit via Line 1
    int x2 = 7;  // Tie Spend on exit via Line 2
    int line1 = assemblyLine_Brute(stations, switch_time, 0, 0, x1, x2, n) + e1 + stations[0][0];
    int line2 = assemblyLine_Brute(stations, switch_time, 1, 0, x1, x2, n) + e2 + stations[1][0];
    int ans = min(line1, line2);
    cout << ans << endl;
    return 0;
}
/*
     lets see the reccurance relation of the fibonacci is
     f(n)=f(n-1)+f(n-2) for all n >=2; f(1)=1,f(0)=1 1 1 2 3 5 8...
     now the tree will be

             f(5)
         f(4)     f(3)
      f(3)  f(2) f(2) f(1)
    f(2) f(1)

    so the
*/
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int fiboRec(int n)
{
    if (n <= 1)
        return 1;
    return fiboRec(n - 1) + fiboRec(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout<<fiboRec(n);

    return 0;
}
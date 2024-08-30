#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myPow(int x, int n)
    {
        if (n == 0)
            return 1;
        int res = myPow(x, n / 2);
        if (n & 1)
            return res * res * x;
        else
            return res * res;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, n;
        cin >> x >> n;
        Solution ob;
        cout << ob.myPow(x, n) << '\n';
    }
    return 0;
}
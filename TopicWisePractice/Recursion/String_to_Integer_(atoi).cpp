#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long func(int i, string &s, long result, int sign)
    {
        if (1LL * result * sign >= INT_MAX)
            return INT_MAX;
        if (1LL * result * sign <= INT_MIN)
            return INT_MIN;
        if (i >= s.length() || s[i] < '0' || s[i] > '9')
            return sign * result;
        long res = (result * 10) + (s[i] - '0');
        return func(i + 1, s, res, sign);
    }

    int myAtoi(string s)
    {
        int i = 0, n = s.length(), sign = 1;
        while (i < n && s[i] == ' ')
            i++;
        if (s[i] == '+')
            sign = 1, i++;
        else if (s[i] == '-')
            sign = -1, i++;
        return func(i, s, 0, sign);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.myAtoi(s) << '\n';
    }
    return 0;
}
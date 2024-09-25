#include <bits/stdc++.h>
using namespace std;

void multi(vector<int> &v, int x)
{
    int carry = 0, n = v.size();
    for (int i = 0; i < v.size(); i++)
    {
        int value = v[i] * x + carry;
        v[i] = value % 10;
        carry = value / 10;
    }
    while (carry)
    {
        v.push_back(carry % 10);
        carry /= 10;
    }
}

string func(int n)
{
    if (n <= 1)
        return "1";

    vector<int> v;
    v.push_back(1);
    for (int i = 2; i <= n; i++)
        multi(v, i);

    string s;
    for (int i = v.size() - 1; i >= 0; i--)
        s += to_string(v[i]);
    return s;
}

int32_t main()
{
    int n;
    cin >> n;
    cout << func(n) << '\n';
    return 0;
}

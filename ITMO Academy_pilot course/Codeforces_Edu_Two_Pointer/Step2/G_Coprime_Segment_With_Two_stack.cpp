#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Stack
{
    vector<int> v, g = {0};
    void push(int x)
    {
        v.push_back(x);
        g.push_back(__gcd(x, g.back()));
    }
    int pop()
    {
        int x = v.back();
        v.pop_back();
        g.pop_back();
        return x;
    }
    int top()
    {
        return g.back();
    }
    bool empty()
    {
        return v.empty();
    }
} s1, s2;

void remove()
{
    if (s2.empty())
    {
        while (!s1.empty())
            s2.push(s1.pop());
    }
    s2.pop();
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int gc = 0;
    for (int i = 0; i < n; i++)
        gc = __gcd(gc, v[i]);

    int l = 0, ans = n + 2;
    for (int r = 0; r < n; r++)
    {
        s1.push(v[r]);
        while (__gcd(s1.top(), s2.top()) == 1)
        {
            remove();
            ans = min(ans, r - l + 1);
            l++;
        }
    }
    cout << (ans > n ? -1 : ans) << '\n';

    return 0;
}
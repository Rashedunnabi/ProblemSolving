#include <bits/stdc++.h>
using namespace std;
#define int long long

struct G_Coprime_Segment
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
    if (s1.empty())
    {
        while (!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, i, gc = 0, ans = INT_MAX, l = 0;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
    {
        cin >> i;
        gc = __gcd(gc, i);
    }

    if (gc != 1)
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int r = 0; r < n; r++)
    {
        s2.push(v[r]);
        while (__gcd(s2.top(), s1.top()) == 1)
        {
            remove();
            ans = min(ans, r - l + 1);
            l++;
        }
    }
    cout << ans << '\n';

    return 0;
}
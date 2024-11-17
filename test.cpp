#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

struct debug
{
#define contPrint                     \
    {                                 \
        *this << "[";                 \
        int f = 0;                    \
        for (auto it : x)             \
        {                             \
            *this << (f ? ", " : ""); \
            *this << it;              \
            f = 1;                    \
        }                             \
        *this << "]";                 \
        return *this;                 \
    }

    ~debug() { cerr << endl; }
    template <class c>
    debug &operator<<(c x)
    {
        cerr << x;
        return *this;
    }
    template <class c, class d>
    debug &operator<<(pair<c, d> x)
    {
        *this << "(" << x.first << ", " << x.second << ")";
        return *this;
    }
    template <class c>
    debug &operator<<(vector<c> x) contPrint;
#undef contPrint
};

#define dbg(x) "[" << #x << ": " << x << "]  "
#define Wa()                                  \
    cerr << "[LINE: " << __LINE__ << "] -> "; \
    debug() <<
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int print(int l, int r)
{
    l++, r++;
    printf("? %d %d\n", l, r);
    fflush(stdout);

    int x;
    scanf("%d", &x);
    return x;
}

void print_ans(string s)
{
    printf("! %s\n", s.c_str());
    fflush(stdout);
}

void solve()
{
    int n;
    scanf("%d", &n);

    vector<int> ans(n);
    int first = -1;
    int cnt = -1;

    for (int i = 1; i < n; i++)
    {
        int x = print(0, i);

        if (first == -1)
        {
            if (x)
            {
                first = i;
                cnt = x;
                ans[i] = 1;
                for (int j = 0; j <= i - 1 - x; j++)
                    ans[j] = 1;
            }
        }
        else
        {
            if (x > cnt)
            {
                ans[i] = 1;
                cnt = x;
            }
        }
    }

    if (first == -1)
        print_ans("IMPOSSIBLE");
    else
    {
        string s = "";
        for (int i : ans)
            s += char('0' + i);
        print_ans(s);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solution()
{
    int n, m, i;
    cin >> n >> m;
    deque<int> q;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }
    string s;
    cin >> s;
    vector<int> remove;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            int x = q.front();
            q.pop_front();
            remove.push_back(x);
        }
        else
        {
            int x = q.back();
            q.pop_back();
            remove.push_back(x);
        }
    }
    reverse(all(remove));

    vector<int> ans;
    int prod = 1;
    for (i = 0; i < n; i++)
    {
        prod = (prod * 1LL * remove[i]) % m;
        ans.push_back(prod);
    }
    reverse(all(ans));
    for (int &e : ans)
        cout << e << ' ';
    cout << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
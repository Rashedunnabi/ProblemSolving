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
    int n, i, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    vector<int> ans[27];

    for (i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            ans[cnt].push_back(i);
            cnt++;
        }
        else
        {
            for (int j = 0; j < 27; j++)
            {
                if (ans[j].size() == v[i])
                {
                    ans[j].push_back(i);
                    break;
                }
            }
        }
    }

    // for (i = 0; i < 27; i++)
    // {
    //     if (ans[i].size() == 0)
    //         continue;
    //     cout << i << ": ";
    //     for (auto val : ans[i])
    //         cout << val << ' ';
    //     cout << endl;
    // }
    // cout << endl;

    string s(n, '0');

    for (i = 0; i < 27; i++)
    {
        if (ans[i].size() == 0)
            continue;
        char ch = i + 'a';
        for (auto val : ans[i])
            s[val] = ch;
    }
    cout << s << '\n';
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
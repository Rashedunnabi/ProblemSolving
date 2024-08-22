#include <bits/stdc++.h>
using namespace std;
#define int long long

void computeLPSArray(string &pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(string &pat, string &txt)
{
    vector<int> v;
    int M = pat.length();
    int N = txt.length();
    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            v.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return v;
    // its size it the number of count where the pattern appear
}

bool check(string &s, int len, int k)
{
    string pat = s.substr(0, len);
    vector<int> v = KMPSearch(pat, s);

    int cnt = 1, pre = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] >= pre + len)
        {
            cnt++;
            pre = v[i];
        }
    }
    return cnt >= k;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, l, r, i;
        string s;
        cin >> n >> l >> r >> s;

        int lo = 1, hi = n, mid, ans = 0;
        while (lo <= hi)
        {
            mid = (lo + hi) >> 1;
            if (check(s, mid, l))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
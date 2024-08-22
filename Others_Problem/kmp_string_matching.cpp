#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

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

void solution()
{
    string pi = "pie", mp = "map", pimp = "mapie";
    int n, i;
    cin >> n;
    string s;
    cin >> s;

    // pattern,text
    int ans = KMPSearch(pi, s).size();
    cout << ans << '\n';
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
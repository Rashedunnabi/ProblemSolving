#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> digit;
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            digit.push_back((int)ch);
        }

        if (is_sorted(digit.begin(), digit.end()))
            yes;
        else
            no;
    }
    return 0;
}
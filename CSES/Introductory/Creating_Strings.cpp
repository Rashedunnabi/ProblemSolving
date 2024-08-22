#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    vector<int> v;

    int c = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            c++;
        else
        {
            v.push_back(c);
            c = 1;
        }
    }
    v.push_back(c);

    int a = 1, b = 1;
    a = fact(s.length());
    for (int i = 0; i < v.size(); i++)
        b *= fact(v[i]);
    int ans = a / b;
    cout << ans << endl;

    do
    {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
// https://leetcode.com/problems/count-anagrams/description/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int mod = 1e9 + 7;
    int gcdExtended(int a, int b, int *x, int *y)
    {
        if (a == 0)
        {
            *x = 0, *y = 1;
            return b;
        }

        int x1, y1;
        int gcd = gcdExtended(b % a, a, &x1, &y1);
        *x = y1 - (b / a) * x1;
        *y = x1;
        return gcd;
    }
    int modInverse(int b, int m = 1e9 + 7)
    {
        int x, y;
        int g = gcdExtended(b, m, &x, &y);
        if (g != 1)
            return -1;
        return (x % m + m) % m;
    }
    int modDivide(int a, int b, int m = 1e9 + 7)
    {
        a = a % m;
        int inv = modInverse(b, m);
        int ans = (inv * 1LL * a) % m;

        if (ans < 0)
            ans += m;
        return ans;
    }

    int fact(int n)
    {
        long long res = 1, i;
        for (i = 2; i <= n; i++)
            res = (res * 1ll * i) % mod;
        return res;
    }
    int countAnagrams(string s)
    {
        long long ans = 1;
        int i, n = s.length();
        map<char, int> mp;
        for (i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                int total = 0;
                int niche = 1;
                for (auto val : mp)
                {
                    niche = (niche * 1LL * fact(val.second)) % mod;
                    total += val.second;
                }
                ans = (ans * 1ll * modDivide(fact(total), niche, mod)) % mod;
                mp.clear();
            }
            else
            {
                mp[s[i]]++;
            }
        }
        int total = 0;
        int niche = 1;
        for (auto val : mp)
        {
            niche = (niche * 1LL * fact(val.second)) % mod;
            total += val.second;
        }
        ans = (ans * 1ll * modDivide(fact(total), niche, mod)) % mod;
        mp.clear();

        return ans;
    }
};

int main()
{
    string s;
    getline(cin, s);

    Solution obj;
    cout << obj.countAnagrams(s) << '\n';
    return 0;
}
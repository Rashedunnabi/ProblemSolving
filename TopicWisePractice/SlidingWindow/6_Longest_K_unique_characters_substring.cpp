#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    int longestKSubstr(string s, int k)
    {
        map<char, int> mp;
        int l = 0, n = s.length(), maxi = -1, cnt = 0;
        for (int r = 0; r < n; r++)
        {
            mp[s[r]]++;
            if (mp[s[r]] == 1)
                cnt++;
            while (cnt > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    cnt--;
                l++;
            }
            maxi = max(r - l + 1, maxi);
        }
        return maxi;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int k;
        cin >> s >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << '\n';
    }
    return 0;
}
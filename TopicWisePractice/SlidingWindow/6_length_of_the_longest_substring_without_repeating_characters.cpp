#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    int longestUniqueSubsttr(string s)
    {
        int ans = 1, n = s.length(), l = 0, count = 0;
        vector<int> freq(27);
        for (int r = 0; r < n; r++)
        {
            int x = s[r] - 'a';
            freq[x]++;
            if (freq[x] == 1)
                count++;
            while (r - l + 1 > count)
            {
                int y = s[l] - 'a';
                freq[y]--;
                if (freq[y] == 0)
                    count--;
                l++;
            }
            if (r - l + 1 == count)
                ans = max(r - l + 1, ans);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestUniqueSubsttr(s) << '\n';
    }
    return 0;
}
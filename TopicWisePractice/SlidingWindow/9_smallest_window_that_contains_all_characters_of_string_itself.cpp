#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    int findSubString(string s)
    {
        set<char> st;
        for (auto &ch : s)
            st.insert(ch);

        int ans = INT_MAX, require = st.size(), cnt = 0, l = 0, n = s.length();
        vector<int> vp(70);

        for (int r = 0; r < n; r++)
        {
            int x = s[r] - 'A';
            vp[x]++;
            if (vp[x] == 1)
                cnt++;

            while (cnt == require)
            {
                ans = min(ans, r - l + 1);
                int y = s[l] - 'A';
                vp[y]--;
                if (vp[y] == 0)
                    cnt--;
                l++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
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
        cout << ob.findSubString(s) << '\n';
    }
    return 0;
}
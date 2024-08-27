#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        vector<int> p_freq(26, 0);
        vector<int> s_freq(26, 0);

        for (char c : p)
            p_freq[c - 'a']++;

        int required = 0;
        for (int i = 0; i < 26; i++)
            required += (p_freq[i] > 0);

        int left = 0, right = 0;
        int formed = 0;
        int min_len = INT_MAX, start_idx = 0;

        while (right < s.length())
        {
            char c = s[right] - 'a';
            s_freq[c]++;

            if (p_freq[c] > 0 && s_freq[c] == p_freq[c])
                formed++;

            while (left <= right && formed == required)
            {
                if (right - left + 1 < min_len)
                {
                    min_len = right - left + 1;
                    start_idx = left;
                }
                char lc = s[left] - 'a';
                s_freq[lc]--;

                if (p_freq[lc] > 0 && s_freq[lc] < p_freq[lc])
                    formed--;
                left++;
            }
            right++;
        }
        return min_len == INT_MAX ? "-1" : s.substr(start_idx, min_len);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
    }
    return 0;
}
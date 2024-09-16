#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(string &ans, vector<int> &v, int k, int fact)
    {
        if (v.size() == 0)
            return;
        fact = fact / v.size();
        int idx = k / fact;
        k %= fact;
        char ch = v[idx] + '0';
        ans.push_back(ch);
        v.erase(v.begin() + idx);
        func(ans, v, k, fact);
    }

    string getPermutation(int n, int k)
    {
        string ans;
        vector<int> v;
        int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
            v.push_back(i);
        }
        k--;

        // // using recursion
        // func(ans, v, k, fact);
        // return ans;

        while (v.size())
        {
            fact = fact / v.size();
            int idx = k / fact;
            k %= fact;
            char ch = v[idx] + '0';
            ans.push_back(ch);
            v.erase(v.begin() + idx);
        }
        return ans;
    }
};
int main()
{
    int n, k;
    cin >> n >> k;
    Solution ob;
    cout << ob.getPermutation(n, k) << '\n';
    return 0;
}
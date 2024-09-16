#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int index, long sumSoFar, long preValue, string s, string num, int target, vector<string> &ans)
    {
        if (index == num.length())
        {
            if (sumSoFar == target)
                ans.push_back(s);
            return;
        }
        string tmp;
        long val = 0;
        for (int i = index; i < num.length(); i++)
        {
            if (i > index && num[index] == '0')
                break;

            tmp += num[i];
            val = val * 10 + num[i] - '0';

            if (index == 0)
                func(i + 1, val, val, s + tmp, num, target, ans);
            else
            {
                func(i + 1, sumSoFar + val, val, s + '+' + tmp, num, target, ans);
                func(i + 1, sumSoFar - val, -val, s + '-' + tmp, num, target, ans);
                func(i + 1, sumSoFar - preValue + (preValue * val), preValue * val, s + '*' + tmp, num, target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        func(0, 0, 0, "", num, target, ans);
        return ans;
    }
};

int main()
{
    string s;
    int target;
    cin >> s >> target;
    Solution ob;
    auto v = ob.addOperators(s, target);
    for (auto val : v)
        cout << val << '\n';
    return 0;
}
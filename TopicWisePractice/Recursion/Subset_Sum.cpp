#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    void func(int i, int sum, vector<int> &ans, vector<int> &ar)
    {
        if (i < 0)
        {
            ans.push_back(sum);
            return;
        }
        // not take
        func(i - 1, sum, ans, ar);
        // take
        func(i - 1, sum + ar[i], ans, ar);
    }

    vector<int> subsetSums(vector<int> ar, int n)
    {
        vector<int> ans;
        func(n - 1, 0, ans, ar);
        return ans;
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
        auto it = ob.subsetSums(arr, n);
        for (auto val : it)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}
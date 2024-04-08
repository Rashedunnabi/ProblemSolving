#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> nums;
bool dp[N];
void func(int n)
{
    if (n > N)
        return;
    nums.push_back(n);
    func(10 * n);
    func(10 * n + 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    func(1);
    sort(nums.begin(), nums.end());
    dp[1] = 1;
    for (int i = 2; i < N; i++)
    {
        for (int x : nums)
        {
            if (i % x == 0)
                dp[i] |= dp[i / x];
        }
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}
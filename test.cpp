#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution
{
public:
    vector<int> maximumToys(int N, vector<int> &A, int Q, vector<vector<int>> &Queries)
    {
        vector<int> ans;
        vector<pair<int, int>> arr(N);
        unordered_map<int, int> mp;
        vector<int> ps(N, 0);

        for (int i = 0; i < N; i++)
            arr[i] = {A[i], i};
        sort(arr.begin(), arr.end());

        for (int i = 0; i < N; i++)
            mp[arr[i].second] = i;

        ps[0] = arr[0].first;
        for (int i = 1; i < N; i++)
            ps[i] = ps[i - 1] + arr[i].first;

        for (auto &x : Queries)
        {
            int cost = x[0];
            int pos = lower_bound(ps.begin(), ps.end(), cost) - ps.begin();

            if (pos == N)
            {
                ans.push_back(N - (x.size() - 2));
                continue;
            }

            if (ps[pos] > cost)
                pos--;

            cost -= ps[pos];

            if (x[1] == 0)
                ans.push_back(pos + 1);
            else
            {
                int cnt = pos + 1;
                unordered_set<int> st;
                for (int i = 2; i < x.size(); i++)
                {
                    if (mp[x[i] - 1] <= pos)
                        cost += arr[mp[x[i] - 1]].first, cnt--;
                    else
                        st.insert(x[i] - 1);
                }

                for (int j = pos + 1; j < N && arr[j].first <= cost; j++)
                    if (!st.count(arr[j].second))
                        cost -= arr[j].first, cnt++;
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        int c, k;
        cin >> c >> k;
        queries[i].push_back(c);
        queries[i].push_back(k);
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            queries[i].push_back(x);
        }
    }

    Solution solution;
    vector<int> result = solution.maximumToys(n, arr, q, queries);

    for (int val : result)
        cout << val << " ";
    cout << '\n';

    return 0;
}

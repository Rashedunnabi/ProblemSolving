// https://www.geeksforgeeks.org/problems/maximum-number-of-toys/1

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// st.order_of_key (k) : Number of items strictly smaller than k
// st.find_by_order(k) : K-th element in a set (counting from zero)

class Solution
{
public:
    vector<int> maximumToys(int n, vector<int> arr, int q, vector<vector<int>> queries)
    {
        pbds toys;
        vector<int> result, temp;

        for (int i = 0; i < n; i++)
        {
            temp.push_back(arr[i]);
            toys.insert({arr[i], i});
        }
        sort(temp.begin(), temp.end());
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + temp[i];

        for (auto &v : queries)
        {
            int cost = v[0], k = v[1];
            vector<pair<int, int>> vp;
            for (int i = 2; i < v.size(); i++)
            {
                int id = v[i] - 1;
                vp.push_back({arr[id], id});
            }

            auto it = lower_bound(preSum.begin(), preSum.end(), cost);
            it--;
            int upValue = *it;
            int dis = it - preSum.begin();
            int ans = 0;
            for (int i = dis; i <= min(n, dis + 10); i++)
            {
                int total = preSum[i];
                int cnt = i;
                for (auto x : vp)
                {
                    int dis = toys.order_of_key(x);
                    if (dis < i)
                    {
                        total -= x.first;
                        cnt--;
                    }
                }
                if (total <= cost)
                    ans = max(ans, cnt);
            }
            result.push_back(ans);
        }
        return result;
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

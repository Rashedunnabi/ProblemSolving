#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {

        int i, n, m, sz, sum = 0;
        cin >> n >> m;
        sz = n + m + 1;

        vector<int> pro(sz), tes(sz), ans;
        for (int &i : pro)
            cin >> i;
        for (int &i : tes)
            cin >> i;

        set<int> lastPro, lastTes;

        for (i = 1; i < sz; i++)
        {
            if (pro[i] > tes[i])
            {
                if (lastPro.size() < n)
                {
                    sum += pro[i];
                    lastPro.insert(i);
                }
                else
                {
                    sum += tes[i];
                    lastTes.insert(i);
                }
            }
            else
            {
                if (lastTes.size() < m)
                {
                    sum += tes[i];
                    lastTes.insert(i);
                }
                else
                {
                    sum += pro[i];
                    lastPro.insert(i);
                }
            }
        }
        ans.push_back(sum);

        for (i = 1; i < sz; i++)
        {

            if (lastPro.find(i) != lastPro.end())
            {
                lastPro.erase(i);
                sum -= pro[i];

                if (pro[i - 1] > tes[i - 1])
                {
                    sum += pro[i - 1];
                    lastPro.insert(i - 1);
                }
                else
                {
                    if (m > 0)
                    {
                        sum += tes[i - 1];
                        lastTes.insert(i - 1);
                    }
                    else
                    {
                        sum += pro[i - 1];
                        lastPro.insert(i - 1);
                    }
                }
            }
            else
            {
                lastTes.erase(i);
                sum -= tes[i];

                if (tes[i - 1] > pro[i - 1])
                {
                    sum += tes[i - 1];
                    lastTes.insert(i - 1);
                }
                else
                {
                    if (n > 0)
                    {
                        sum += pro[i - 1];
                        lastPro.insert(i - 1);
                    }
                    else
                    {
                        sum += tes[i - 1];
                        lastTes.insert(i - 1);
                    }
                }
            }

            if (lastPro.size() > n)
            {
                int ind = *lastPro.rbegin();
                lastPro.erase(ind);
                sum -= pro[ind];
                sum += tes[ind];
                lastTes.insert(ind);
            }
            if (lastTes.size() > m)
            {
                int ind = *lastTes.rbegin();
                lastTes.erase(ind);
                sum -= tes[ind];
                sum += pro[ind];
                lastPro.insert(ind);
            }
            ans.push_back(sum);
        }

        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}
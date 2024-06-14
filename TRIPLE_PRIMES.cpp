#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> primes;
const int N = 1e5 + 1;
void sieve(int N)
{
    vector<int> vv(N + 1);
    vv[1] = 1;
    vv[0] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!vv[i])
            vv[i] = i, primes.push_back(i);
        for (int j = 0; j < primes.size() and primes[j] <= vv[i] and i * primes[j] <= N; j++)
            vv[i * primes[j]] = primes[j];
    }
}

signed main()
{
    int t = 1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    set<int> st;
    sieve(N);
    for (int i = 0; i < primes.size(); i++)
    {
        // cout<<primes[i]<<" ";
        st.insert(primes[i] * primes[i]);
        primes[i] = primes[i] * primes[i];
    }
    while (t--)
    {
        int n;
        cin >> n;
        bool flag = false;
        if (n < 38)
        {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < primes.size(); i++)
        {
            if (primes[i] * primes[i] >= n)
                break;
            for (int j = i + 1; j < primes.size() - 1; j++)
            {
                int x = n - (primes[i] + primes[j]);
                if (x <= 0)
                    break;
                if (st.find(x) != st.end() && x != primes[i] && x != primes[j])
                {
                    cout << "YES\n";
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << "NO\n";
    }

    return 0;
}
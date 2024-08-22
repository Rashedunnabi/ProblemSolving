#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(v) v.begin(), v.end()

void solution()
{
    int n, m, x, i;
    cin >> n >> m >> x;

    set<pair<int, int>> st;
    st.insert({0, x}); // distance , node
    for (i = 0; i < m; i++)
    {
        int val;
        char ch;
        cin >> val >> ch;

        while (!st.empty())
        {
            auto it = *st.begin();

            if (it.first > i)
                break;

            st.erase(st.begin());

            int dis = it.first + 1;
            int node = it.second;
            int newNode = 0;

            if (ch == '0') // clockwise
            {
                newNode = node + val;
                if (newNode > n)
                    newNode -= n;

                st.insert({dis, newNode});
            }
            else if (ch == '1') // anticlock-wise
            {
                newNode = node - val;
                if (newNode < 1)
                    newNode += n;
                st.insert({dis, newNode});
            }
            else
            {
                newNode = node + val;
                if (newNode > n)
                    newNode -= n;

                st.insert({dis, newNode});

                newNode = node - val;
                if (newNode < 1)
                    newNode += n;
                st.insert({dis, newNode});
            }
        }
    }
    vector<int> v;
    for (auto val : st)
        v.push_back(val.second);
    sort(all(v));

    cout << v.size() << '\n';
    for (auto val : v)
        cout << val << ' ';
    cout << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 7;
int parent[N], Size[N];
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}

int Find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]); // path compression
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        // Union by size
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 0;
        cin >> n >> m;

        int sz = n * m + 10;
        for (int i = 0; i < sz; i++)
            make(i);

        char ar[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> ar[i][j];
        }

        // Create the DSU for the initial grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ar[i][j] == '#')
                {
                    if (i > 0 && ar[i - 1][j] == '#')
                        Union(i * m + j, (i - 1) * m + j);
                    if (j > 0 && ar[i][j - 1] == '#')
                        Union(i * m + j, i * m + j - 1);
                }
            }
        }
        // Calculate the maximum connected component size by setting entire rows
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            set<int> st;
            for (int j = 0; j < m; j++)
            {
                if (ar[i][j] == '#')
                {
                    st.insert(Find(i * m + j));
                }
                else
                {
                    sum++;
                    if (i > 0 && ar[i - 1][j] == '#')
                        st.insert(Find((i - 1) * m + j));
                    if (i < n - 1 && ar[i + 1][j] == '#')
                        st.insert(Find((i + 1) * m + j));
                }
            }
            for (auto it : st)
                sum += Size[it];
            ans = max(ans, sum);
        }
        // Calculate the maximum connected component size by setting entire columns
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            set<int> st;
            for (int i = 0; i < n; i++)
            {
                if (ar[i][j] == '#')
                    st.insert(Find(i * m + j));
                else
                {
                    sum++;
                    if (j > 0 && ar[i][j - 1] == '#')
                        st.insert(Find(i * m + j - 1));
                    if (j < m - 1 && ar[i][j + 1] == '#')
                        st.insert(Find(i * m + j + 1));
                }
            }
            for (auto it : st)
                sum += Size[it];
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;
int parent[N], Size[N];

// Function to initialize the DSU structure
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}

// Find function with path compression
int Find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]); // path compression
}

// Union by size
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 0;
        cin >> n >> m;

        char arr[n][m];
        int sz = n * m + 10;

        // Initialize DSU structures for each test case
        for (int i = 0; i <= sz; i++)
            make(i);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }

        // Create the DSU for initial grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '#')
                {
                    if (i > 0 && arr[i - 1][j] == '#')
                        Union(i * m + j, (i - 1) * m + j);
                    if (j > 0 && arr[i][j - 1] == '#')
                        Union(i * m + j, i * m + j - 1);
                }
            }
        }
        // Calculate max connected component size by setting entire rows
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            set<int> st;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '#')
                    st.insert(Find(i * m + j));
                else
                {
                    sum++;
                    if (i > 0 && arr[i - 1][j] == '#')
                        st.insert(Find((i - 1) * m + j));
                    if (i < n - 1 && arr[i + 1][j] == '#')
                        st.insert(Find((i + 1) * m + j));
                    if (j > 0 && arr[i][j - 1] == '#')
                        st.insert(Find(i * m + j - 1));
                    if (j < m - 1 && arr[i][j + 1] == '#')
                        st.insert(Find(i * m + j + 1));
                }
            }
            for (auto it : st)
                sum += Size[it];
            ans = max(ans, sum);
        }
        // Calculate max connected component size by setting entire columns
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            set<int> st;
            for (int i = 0; i < n; i++)
            {
                if (arr[i][j] == '#')
                    st.insert(Find(i * m + j));
                else
                {
                    sum++;
                    if (i > 0 && arr[i - 1][j] == '#')
                        st.insert(Find((i - 1) * m + j));
                    if (i < n - 1 && arr[i + 1][j] == '#')
                        st.insert(Find((i + 1) * m + j));
                    if (j > 0 && arr[i][j - 1] == '#')
                        st.insert(Find(i * m + j - 1));
                    if (j < m - 1 && arr[i][j + 1] == '#')
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

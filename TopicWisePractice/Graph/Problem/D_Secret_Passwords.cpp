#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int N = 2e5 + 100;
vector<int> graph[N];
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
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;

    // Union by size
    if (Size[a] < Size[b])
        swap(a, b);
    parent[b] = a;
    Size[a] += Size[b];
}

int main()
{
    Faster;
    int n, i, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        for (int j = 0; j < s.length(); j++)
        {
            if (j > 0 && s[j] == s[j - 1])
                continue;
            int v = n + s[j] - 'a';
            graph[i].push_back(v);
            graph[v].push_back(i);
        }
    }

    for (i = 0; i < N; i++)
        make(i);

    for (i = 0; i < N; i++)
    {
        if (graph[i].size() == 0)
            continue;
        for (int j = 0; j < graph[i].size(); j++)
        {
            Union(i, graph[i][j]);
        }
    }

    for (i = 0; i < N; i++)
    {
        if (parent[i] == i && graph[i].size() > 0)
            ans++;
    }

    cout << ans << '\n';
    return 0;
}
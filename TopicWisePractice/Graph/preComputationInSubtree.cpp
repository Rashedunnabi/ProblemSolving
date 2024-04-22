// SumOfSubtree
// Count of even-odd in subtree
// Count of prime in subtree

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
bool prime[N + 1];

void sieve()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

vector<int> graph[N];
int sumOfSubtree[N], primeCount[N], evenCount[N], oddCount[N];

void dfs(int vertex, int parent)
{
    sumOfSubtree[vertex] += vertex; // considering the vertex number is the value array
    primeCount[vertex] += (prime[vertex] == true);
    evenCount[vertex] += (vertex % 2 == 0);
    oddCount[vertex] += (vertex & 1);

    for (int &child : graph[vertex])
    {
        if (child == parent)
            continue;

        dfs(child, vertex);

        sumOfSubtree[vertex] += sumOfSubtree[child];
        primeCount[vertex] += primeCount[child];
        evenCount[vertex] += evenCount[child];
        oddCount[vertex] += oddCount[child];
    }
}

int main()
{
    sieve();
    int e, v, i;
    cin >> v >> e;

    for (i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // suppose 1 is the root
    dfs(1, 0);

    for (i = 1; i <= v; i++)
        cout << i << ' ';
    cout << '\n';
    for (i = 1; i <= v; i++)
        cout << "--";
    cout << '\n';

    for (i = 1; i <= v; i++)
        cout << sumOfSubtree[i] << ' ';
    cout << '\n';
    for (i = 1; i <= v; i++)
        cout << primeCount[i] << ' ';
    cout << '\n';
    for (i = 1; i <= v; i++)
        cout << evenCount[i] << ' ';
    cout << '\n';
    for (i = 1; i <= v; i++)
        cout << oddCount[i] << ' ';
    cout << '\n';

    return 0;
}
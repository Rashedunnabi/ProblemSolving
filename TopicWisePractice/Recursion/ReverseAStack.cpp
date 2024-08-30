#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int last)
{
    if (st.size() == 0)
    {
        st.push(last);
        return;
    }
    int tmp = st.top();
    st.pop();
    insert(st, last);
    st.push(tmp);
}

void reverser(stack<int> &st)
{
    if (st.size() == 1)
        return;
    int last = st.top();
    st.pop();
    reverser(st);
    insert(st, last);
}

int main()
{
    int n;
    cin >> n;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    reverser(st);

    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        cout << tp << ' ';
    }
    cout << '\n';
}
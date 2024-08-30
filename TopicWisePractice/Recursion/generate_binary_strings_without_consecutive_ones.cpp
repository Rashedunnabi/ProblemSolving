#include <bits/stdc++.h>
using namespace std;

void getAllPermutation(int i, string &s, int n)
{
    if (i == n)
    {
        cout << s << ' ';
        return;
    }

    if (s.size() == 0 || s.back() == '0')
    {
        s.push_back('0');
        getAllPermutation(i + 1, s, n);
        s.pop_back();

        s.push_back('1');
        getAllPermutation(i + 1, s, n);
        s.pop_back();
    }
    else
    {
        s.push_back('0');
        getAllPermutation(i + 1, s, n);
        s.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    getAllPermutation(0, s, n);
}
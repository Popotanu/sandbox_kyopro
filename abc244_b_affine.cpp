#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
// #define dbg(x) true
#endif

// https : // atcoder.jp/contests/abc244/tasks/abc244_b

int main()
{
    int i;
    string t;
    cin >> i >> t;

    int x = 0;
    int y = 0;
    int dx = 1;
    int dy = 0;

    for (char c : t)
    {
        if (c == 'S')
        {
            x = x + dx;
            y = y + dy;
        }
        else
        {
            int tmp = dx;
            dx = dy;
            dy = -tmp;
        }
    }

    cout << x << " " << y << endl;
}
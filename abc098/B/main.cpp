#include <bits/stdc++.h>

using namespace std;

#define _GLIBCXX_DEBUG  // 空の構造に対して未定義な操作を行ったときに例外を投げる
#ifdef LOCAL
#define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
// #define dbg(x) true
#endif

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()

int N;
string S;

int main() {
  cin >> N >> S;

  int ans = 0;
  rep(i, 1, N - ans) {
    string x = S.substr(0, i);
    string y = S.substr(i);

    set<char> l;
    fore(xx, x) l.insert(xx);
    int c = l.size();
    fore(yy, y) l.erase(yy);

    int d = c - l.size();
    ans = max(ans, d);
  }

  cout << ans << endl;
}

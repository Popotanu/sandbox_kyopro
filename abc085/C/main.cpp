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

int N, Y;

int main() {
  cin >> N >> Y;
  int a = -1, b = -1, c = -1;

  rep(aa, 0, N + 1) {
    rep(bb, 0, N + 1) {
      int cc = N - aa - bb;

      if (cc < 0 || cc > N) continue;
      if (aa * 10000 + bb * 5000 + cc * 1000 == Y) {
        a = aa;
        b = bb;
        c = cc;
      }
    }
  }

  cout << a << " " << b << " " << c << endl;
}

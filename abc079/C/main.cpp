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

string N;
int main() {
  cin >> N;

  rep(bit, 0, 1 << 3) {
    int ans = N[0] - '0';

    rep(i, 0, 3) {
      // +: i桁目が立ってる
      // -: たってない

      if (bit & (1 << i)) {
        ans += (N[i + 1] - '0');
      } else {
        ans -= (N[i + 1] - '0');
      }
    }

    if (ans == 7) {
      cout << N[0];

      rep(j, 0, 3) {
        if (bit & (1 << j)) {
          cout << "+";
        } else {
          cout << "-";
        }
        cout << N[j + 1];
      }

      cout << "=7" << endl;
      return 0;
    }
  }
}

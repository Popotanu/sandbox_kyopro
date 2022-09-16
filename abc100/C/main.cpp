#include <bits/stdc++.h>

using namespace std;

// clang-format off
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
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

// https://atcoder.jp/contests/abc100/tasks/abc100_c
int N;
void _main() {
  // N<=10e4, a_1<=10e9
  cin >> N;
  vector<ll> A(N);
  fore(i, A) cin >> i;

  // (今回は,2で割った結果が整数となることを`2で割れる`という)
  // a_iの素因数の2の数の回数だけ2でわれる.
  // ところで，2と3は互いに素だから
  // a_iに3を掛けたとしても,2で割れる回数は変わらない.

  int ans = 0;
  fore(i, A) {
    if (i % 2 == 0) {
      while (i % 2 == 0) {
        i /= 2;
        ans++;
      }
    }
  }

  cout << ans << endl;
}

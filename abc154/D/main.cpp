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

int K, N;
string A;
void _main() {
  // 1<=K<=N<= 200000
  cin >> N >> K;
  vector<int> dice(N);
  fore(i, dice) cin >> i;

  // vector<double> cumsum(N + 1, 0.0);
  // rep(i, 0, N + 1) {
  //   cumsum[i + 1] = cumsum[i] + ((double)(1 + dice[i]) / 2.0);
  // }
  // double ans = 0.0;
  // rep(i, K, N + 1) { chmax(ans, cumsum[i] - cumsum[i - K]); }

  vector<double> E(N);
  rep(i, 0, N) { E[i] = 1.0 * (1 + dice[i]) / 2; }

  // K個の区間を先頭から見ていって，maxが答え
  double total = 0;
  rep(i, 0, K) total += E[i];

  double ans = total;

  // 調べる区間を右に1つずらしていく
  // 右にずらしたときに,新たに含まれる要素を合計にプラスする
  // 右にずらしたときに,区間からはみ出る要素を合計からマイナスする
  rep(i, K, N) {
    total = total + E[i] - E[i - K];
    chmax(ans, total);
  }

  cout << fixed << setprecision(10);
  cout << ans << endl;
}

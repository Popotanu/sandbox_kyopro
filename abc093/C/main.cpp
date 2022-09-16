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

// https://atcoder.jp/contests/abc093/tasks/arc094_a
int A, B, C;
void _main() {
  vector<int> se(3);
  fore(i, se) cin >> i;
  sort(all(se));
  A = se[0];
  B = se[1];
  C = se[2];

  int ans = 0;
  if (C - B == 1) {
    A++;
    B++;
    ans++;
  }
  ans += (C - B) / 2;
  ans += (C - A) / 2;

  if ((A ^ B) & 1) {
    ans += 2;
  }

  cout << ans << endl;
}

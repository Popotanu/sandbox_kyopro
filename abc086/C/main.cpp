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

// https://atcoder.jp/contests/abc086/tasks/arc089_a
int N;
string A;
void _main() {
  cin >> N;
  int x, y, t;
  vector<vector<int>> move(N, vector<int>(3));

  // 前回の時刻と座標を持っておく
  int pt = 0, px = 0, py = 0;
  bool ok = true;
  rep(i, 0, N) {
    cin >> t >> x >> y;

    int dx = abs(x - px);
    int dy = abs(y - py);
    int dt = t - pt;
    int d = dx + dy;

    // 届かない場合 || 偶奇が不一致な場合
    if (dt < d || dt % 2 != d % 2) {
      ok = false;
      break;
    }

    pt = t;
    px = x;
    py = y;
  }

  cout << (ok ? "Yes" : "No") << endl;
}

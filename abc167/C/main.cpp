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

int N, M, X;
string A;
void _main() {
  //  books >> algorithms >> aim
  cin >> N >> M >> X;

  vector<vector<int>> books(N, vector<int>(M));
  vector<int> prices(N);
  rep(i, 0, N) {
    cin >> prices[i];
    fore(j, books[i]) cin >> j;
  }

  int ans = inf;
  rep(mask, 0, 1 << N) {
    int cost = 0;
    vector<int> grasp(M);
    rep(i, 0, N) {
      if (mask & (1 << i)) {
        cost += prices[i];
        rep(j, 0, M) grasp[j] += books[i][j];
      }
    }

    bool satisfied = true;
    fore(b, grasp) if (b < X) satisfied = false;
    if (satisfied) chmin(ans, cost);
  }
  cout << (ans == inf ? -1 : ans) << endl;
}

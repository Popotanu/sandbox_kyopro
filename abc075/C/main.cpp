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

int N, M;
string A;
bitset<50> G[50];
void _main() {
  // 単純連結無向グラフの橋の本数を求める
  // N <=50, M <=50
  cin >> N >> M;

  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u][v] = true;
    G[v][u] = true;
  }

  // fore(i, G) { cout << i << endl; }

  int ans = 0;

  rep(v, 0, N) {
    bitset<50> now = G[v];
    rep(h, 0, N) {
      if (v == h) continue;

      now.set(v);
      auto andd = now & G[h];
      if (andd.test(v) && andd.count() == 1) {
        ans++;
      }
    }
  }

  cout << ans / 2 << endl;
}

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

int N, M, Q;
string A;
void _main() {
  // N:頂点,M:辺
  cin >> N >> M >> Q;
  vector<vector<int>> G(N);

  // グラフは頂点番号が1始まりであることが多い.
  // グラフを表すlistは0始まりにしておいて,
  // 受け取った数値をdecrementしてlistの構造に合わせる.
  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;

    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<int> colors(N);
  fore(i, colors) cin >> i;

  // 1 a : 頂点 aの色を出力, 隣接点をaの色でぬる
  // 2 b c: 頂点bの色を出力, bの色をcで上書きする
  rep(i, 0, Q) {
    int t, x;
    cin >> t >> x;
    x--;
    cout << colors[x] << endl;
    if (t == 1) {
      fore(j, G[x]) colors[j] = colors[x];
    } else {
      int y;
      cin >> y;
      colors[x] = y;
    }
  }
}

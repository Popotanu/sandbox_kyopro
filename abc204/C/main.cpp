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

int dfs(const vector<vector<int>>& G, const int& v, vector<bool> seen) {
  if (seen[v]) return 0;
  seen[v] = true;

  int ret = 0;
  fore(vv, G[v]) { ret += dfs(G, vv, seen); }
  return ret + 1;
}

void _main() {
  // 各頂点に対してdfsを施すから,O(N(N+E))...なはず.
  // 2000*(2000+2000).
  // 条件よりグラフは単純．
  cin >> N >> M;

  vector<vector<int>> G(N);
  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    G[u].push_back(v);
  }

  int ans = 0;
  rep(v, 0, G.size()) {
    vector<bool> seen(N, false);
    ans += dfs(G, v, seen);
  }

  cout << ans << endl;
}

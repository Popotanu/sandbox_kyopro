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

struct LowLink {
  const vector<vector<int>>& G;

  // ord[u] < low[v]ならば(u,v)は橋.
  // (じつは<=も成り立つ)
  vector<int> seen, ord, low;
  vector<int> aps;  // 関節点. articulation points.
  vector<pair<long long, long long>> bridges;

  LowLink(const vector<vector<int>>& G_) : G(G_) {
    seen.assign(G.size(), 0);
    ord.assign(G.size(), 0);
    low.assign(G.size(), 0);
    int k = 0;

    for (int i = 0; i < G.size(); i++) {
      if (!seen[i]) k = dfs(i, k, -1);
    }

    // 必要ならsortする
    // sort(aps.begin(), aps.end());
    // sort(bridges.begin(), bridges.end());
  }

  int dfs(const int now, int& k, const int par) {
    seen[now] = true;
    ord[now] = k++;  // 探索順の記録
    low[now] = ord[now];

    bool is_aps = false;
    int children = 0;

    for (auto& v : G[now]) {
      // vが未探索なら,辺{now,v}を使ってvへ行く
      if (!seen[v]) {
        children++;

        k = dfs(v, k, now);

        // 辺{自分,子}がDFSで辿ったものならば,
        // 自分のLowLinkは子のLowLink以下なはず
        low[now] = min(low[now], low[v]);
        if (par != -1 && ord[now] <= low[v]) is_aps = true;
        if (ord[now] < low[v]) bridges.emplace_back(min(now, v), max(now, v));

      } else if (v != par) {
        // vが訪問済だけど,DFSで辺{now,v}を通らなかった({now,v}が後退辺)
        // 1回だけ後退辺を辿れる
        low[now] = min(low[now], ord[v]);
      }
    }

    // DFS treeの根で,子が2つ以上あるなら関節点
    if (par == -1 && children >= 2) is_aps = true;
    if (is_aps) aps.push_back(now);
    return k;
  }
};

int N, M;
void _main() {
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  LowLink lowlink(G);
  cout << lowlink.bridges.size() << endl;
}

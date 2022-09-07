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
  bool completed = true;
  for (bool i : seen) {
    if (!i) {
      completed = false;
      break;
    }
  }
  if (completed) return 1;

  int comp = 0;
  fore(vv, G[v]) {
    if (seen[vv]) continue;
    seen[vv] = true;
    comp += dfs(G, vv, seen);
    seen[vv] = false;
  }

  return comp;
}

void _main() {
  // Q.頂点1を始点としたハミルトン路は何通り？

  // 問題文では，与えられたグラフが連結であることは仮定されてない.
  // から，0通りであることも一応考慮する.

  // 方針(解説見た)
  // 頂点1を始点とするDFSで数え上げる

  // 頂点1を訪問済みとして再帰で探っていく
  // 頂点数の最大は8.そのうち1個は訪問済だから,7!=5040とおり.
  // 今回の解法はO(V!)だからいける.(V:頂点の数)

  // DFSはΘ(V+E)なのに，今回はなんでO(V!)もかかるの？:
  //  (通常の)DFSでは1通り調べればいいけど，今回はpathを全通り調べなくちゃいけない.
  //  だから訪問済の頂点vに対してDFSをほどこしたあとに，頂点vを未訪問に戻す必要がある.
  //  よってO(N!)となる.

  cin >> N >> M;

  // DFSではグラフの隣接リストの存在が仮定されてるからそれをつくる．
  vector<vector<int>> G(N);
  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  // 訪問済フラグも準備する
  // グラフが連結でない場合,頂点1から辿れない頂点は常にfalse
  // よって非連結なグラフの場合もカバーできる(0通りになる)
  vector<bool> seen(N, false);
  seen[0] = true;

  cout << dfs(G, 0, seen) << endl;
}

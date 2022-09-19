#include <bits/stdc++.h>

using namespace std;

/* -------------ACL--------------- */
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
//
// #include <atcoder/math>
// #include <atcoder/convolution>
// #include <atcoder/modint>
//
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>
//
// using namespace atcoder;
/* ------------------------------- */

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
string S;
vector<int> signpost;

void bfs(const vector<vector<int>>& G, queue<int> qu, set<int> seen) {
  if (seen.size() == N || qu.empty()) return;

  int cur = qu.front();
  qu.pop();

  fore(i, G[cur]) {
    if (seen.count(i)) continue;
    qu.push(i);
    seen.insert(i);
    signpost[i] = cur;
    bfs(G, qu, seen);
  }
}
void _main() {
  cin >> N >> M;

  vector<vector<int>> G(N);  // 連結
  rep(i, 0, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  // 向かうべき隣の部屋を出力.
  // BFSする．
  // 始点: 部屋1
  // 部屋Bが部屋Aから探索されたとき,部屋Bは部屋Aへの道標を立てればOK;

  queue<int> que;
  set<int> seen;
  signpost.resize(N);
  que.push(0);
  seen.insert(0);
  signpost.push_back(0);

  bfs(G, que, seen);

  cout << "Yes" << endl;
  rep(i, 1, N) { cout << ++signpost[i] << endl; }
}

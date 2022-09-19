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

int H, W;

// 上下左右の移動を定義しておく
// おなじループでどこか1方向のみへ動くように
// e.g) x + dx[2], y + dy[2];
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
void _main() {
  cin >> H >> W;  //<=50

  vector<string> S(H);
  fore(i, S) cin >> i;

  // 幅優先探索は最短距離も算出する.
  // 距離の記録のついでに探索済フラグも兼ねる.
  vector<vector<int>> dist(H, vector<int>(W, -1));

  // 次に訪れる地点．
  queue<pair<int, int>> que;

  dist[0][0] = 0;
  que.push({0, 0});

  // BFSする
  while (!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    rep(d, 0, 4) {
      int nx = x + dx[d], ny = y + dy[d];

      if (nx < 0 || W <= nx || ny < 0 || H <= ny) continue;

      if (S[ny][nx] == '#') continue;
      if (dist[ny][nx] != -1) continue;
      que.push({nx, ny});
      dist[ny][nx] = dist[y][x] + 1;
    }
  }

  int siro = 0;
  fore(i, S) { fore(j, i) if (j == '.') siro++; }
  if (dist[H - 1][W - 1] == -1) {
    cout << -1;
  } else {
    // 始点を白のままにしておくのを忘れないーの+1.
    cout << siro - (dist[H - 1][W - 1] + 1);
  }
  cout << endl;
}

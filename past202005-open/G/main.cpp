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

int N, X, Y;
vector<int> dx = {1, 0, -1, 1, -1, 0};
vector<int> dy = {1, 1, 1, 0, 0, -1};
void _main() {
  cin >> N >> X >> Y;
  X += 200;
  Y += 200;

  vector<pair<int, int>> D(N);
  fore(i, D) {
    int a, b;
    cin >> a >> b;
    a += 200;
    b += 200;
    i.first = a;
    i.second = b;
  }

  queue<pair<int, int>> que;
  vector<vector<int>> dist(401, vector<int>(401, -1));

  que.push({200, 200});
  dist[200][200] = 0;

  while (!que.empty() || dist[X][Y] == -1) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    rep(i, 0, 6) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || 400 < nx || ny < 0 || 400 < ny) continue;
      if (dist[nx][ny] != -1) continue;

      bool keep_on = true;
      fore(dis, D) {
        if (nx == dis.first && ny == dis.second) keep_on = false;
      }

      if (!keep_on) continue;

      dist[nx][ny] = dist[x][y] + 1;
      que.push({nx, ny});
    }
  }

  std::cout << dist[X][Y] << endl;
}

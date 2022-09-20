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

// https://atcoder.jp/contests/past202010-open/tasks/past202010_g
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int N, M;
void _main() {
  cin >> N >> M;  // <=10

  vector<string> S(N);
  fore(i, S) cin >> i;

  assert(S.size() == N && S[0].size() == M && S[N - 1].size() == M);

  // #を.にしたときに連結となればいい
  // 壁を1つ取り払って，そのときにある．からBFSする
  // 全部の.にたどり着ければ+1通り
  // 100 * (100+4*100)

  int blocks = 0;
  pair<int, int> begin({-1, -1});
  rep(i, 0, N) {
    rep(j, 0, M) {
      if (begin.first == -1 && S[i][j] == '.') begin = {i, j};
      if (S[i][j] == '#') blocks++;
    }
  }

  int ans = 0;
  vector<vector<int>> seen(N, vector<int>(M, -1));

  fore(row, S) {
    fore(tile, row) {
      if (tile != '#') continue;
      tile = '.';

      seen.assign(N, vector<int>(M, -1));
      seen[begin.first][begin.second] = 1;

      queue<pair<int, int>> que;
      que.push({begin.first, begin.second});

      while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        rep(i, 0, 4) {
          int nx = x + dx[i], ny = y + dy[i];
          if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;
          if (S[nx][ny] == '#') continue;
          if (seen[nx][ny] != -1) continue;

          seen[nx][ny] = 1;
          que.push({nx, ny});
        }
      }

      int reached = accumulate(seen.begin(), seen.end(), 0,
                               [](int acc, const auto& current) {
                                 fore(i, current) if (i != -1) acc++;
                                 return acc;
                               });

      if (N * M - (blocks - 1) == reached) ans++;

      tile = '#';
    }
  }

  cout << ans << endl;
}

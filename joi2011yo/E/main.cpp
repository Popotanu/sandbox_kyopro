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

// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e
int H, W, N_fac;
void _main() {
  cin >> H >> W;  // <=1000
  cin >> N_fac;   // 1..9

  // S: nest
  // X: barricade
  // .: empty
  // 1..9: factory,チーズの硬さ,食べたら一律HP+1
  // おなじ硬さのチーズの工場はただ1つ.

  // 最短経路だからBFS.
  // 1についたらBFSを打ち切る. 1を始点として別のBFSで探索
  // 2についたら...

  // 時間計算量: たかだか(1000+ 4*1000)*9 = 45000....だよね？
  // とすると枝刈ったりする必要なさそう

  vector<string> S(H);
  rep(i, 0, H) { cin >> S[i]; }

  assert(S.size() == H);
  assert(S[H - 1].size() == W);

  pair<int, int> st;
  rep(i, 0, H) { rep(j, 0, W) if (S[i][j] == 'S') st = {i, j}; }

  vector<vector<int>> dist(H, vector<int>(W, -1));

  vector<int> ans;

  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};

  rep(i, 0, N_fac) {
    queue<pair<int, int>> que;
    que.push(st);

    dist.assign(H, vector<int>(W, -1));
    dist[st.first][st.second] = 0;

    bool reached = false;
    while (!(que.empty() || reached)) {
      int x = que.front().first;
      int y = que.front().second;

      que.pop();

      rep(j, 0, 4) {
        int nx = x + dx[j], ny = y + dy[j];

        if (nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
        if (dist[nx][ny] != -1) continue;
        if (S[nx][ny] == 'X') continue;

        if (S[nx][ny] == '0' + (i + 1)) {
          ans.push_back(dist[x][y] + 1);
          st = {nx, ny};
          reached = true;
        }

        que.push({nx, ny});
        dist[nx][ny] = dist[x][y] + 1;
      }
    }
  }

  assert(ans.size() == N_fac);

  cout << accumulate(ans.begin(), ans.end(), 0,
                     [](int acc, const auto& current) { return acc + current; })
       << endl;
}

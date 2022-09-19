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

void _main() {
  cin >> N >> X >> Y;  // <=2*10^3
  vector<vector<int>> G(N);
  rep(i, 0, N - 1) {
    G[i].push_back(i + 1);
    G[i + 1].push_back(i);
  }
  G[X - 1].push_back(Y - 1);
  G[Y - 1].push_back(X - 1);

  if (X != N && X != 1) {
    assert(G[X - 1].size() == 3);
  } else {
    assert(G[X - 1].size() == 2);
  }

  vector<int> ans(N), dist(N);

  rep(i, 0, N) {
    queue<int> que;
    que.push(i);
    dist.assign(N, -1);
    dist[i] = 0;

    while (!que.empty()) {
      int cur = que.front();
      que.pop();

      fore(nex, G[cur]) {
        if (dist[nex] != -1) continue;

        dist[nex] = dist[cur] + 1;
        que.push(nex);
      }
    }

    fore(d, dist) ans[d]++;
  }

  assert(ans.size() == N);
  for_each(ans.begin() + 1, ans.end(), [](auto& x) { cout << x / 2 << endl; });
}

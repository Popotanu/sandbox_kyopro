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
#define LOCAL

#ifdef LOCAL
  #define _GLIBCXX_DEBUG  // 配列外参照をしたときにエラーをあげる(未定義な動作の代わりに)
  #define dbg(x) cout << __LINE__ << " : " << #x << " = " << (x) << endl
#else
  #define dbg(x) true
#endif

void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

int N, M;
string S;
void _main() {
  ll H;
  cin >> N >> H;

  // {mb,ma}
  pair<ll, ll> maxA = {0, 0};

  priority_queue<pair<ll, ll>> que;
  rep(i, 0, N) {
    ll a, b;
    cin >> a >> b;
    if (maxA.second < a) {
      // 最大のAだって思ってたものがそうじゃなくなったからqueにいれる.
      if (maxA.first != 0) que.push(maxA);
      maxA = {b, a};
    } else {
      que.push({b, a});
    }
  }

  pair<ll, ll> cur;
  ll ans = 0;

  while (H > 0 && !que.empty()) {
    cur = que.top();
    que.pop();
    // cur = {B,A}
    if (cur.first < maxA.second) break;
    H -= cur.first;
    ans++;
  }

  if (H > 0) {
    H -= maxA.first;
    ans++;
    if (H > 0) {
      ans += H / maxA.second;
      if (H % maxA.second) ans++;
    }
  }
  cout << ans << endl;
}

// clang-format off
/*

- 条件より, 投げると切りつける以上のダメージが出る.
- maxA: A(きりつける)が最大のかたなとする

-  1. B_i >= A_maxAかつ A_i <= A_maxAのかたなiはすべて投げてしまう.
  - そうしても結果は悪くならない
    - 当てはまる刀を残しておいて，切りつけてもmaxAで切るのより効果が出ない
    - かつ，投げればmaxAで切るより効果がある
    - ↑に当てはまらないかたなは
      - B_i < A_maxA または A_i > A_maxA
        - なげてもmaxAで切るより効果が出ない
        - A_i > A_maxAのものは存在しない
          - なぜなら，maxAはAが最大のかたなだから.
        - よってこれはなまくら.ほおっておく.
          
-  2.maxAでてきをやっつける
  -  HP<=Bまで斬りつける，A_maxAを引いていく
  -  最後に1回投げる

- ↑のように貪欲にたたかっていく

*/
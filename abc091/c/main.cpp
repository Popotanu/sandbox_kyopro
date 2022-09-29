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
  cin >> N;
  vector<pair<int, int>> R(N), B(N);
  rep(i, 0, N) cin >> R[i].first >> R[i].second;
  rep(i, 0, N) cin >> B[i].first >> B[i].second;
  sort(all(B));

  set<int> seen;

  fore(b, B) {
    int bx = b.first, by = b.second;
    int r_idx = -1;
    int may = -1;
    rep(r, 0, N) {
      if (seen.count(r)) continue;
      if (bx <= R[r].first || by <= R[r].second) continue;
      if (may < R[r].second) {
        r_idx = r;
        may = R[r].second;
      }
    }

    if (r_idx != -1) seen.insert(r_idx);
  }

  std::cout << seen.size() << endl;
}

// clang-format off

/*

- スケジューリング問題の二次元verのようにみえる

- 良い赤点をあとに残す,(0,0)が最良

- 最小の部分問題を考えたい
- blue_xが最小のものをとってくる
  - red_x < blue_xのものをすべてとってくる
  - いま, 取ってきた赤点のx座標の大小はきにしなくていい
    - ∵ 今考えてる青点のx座標は,すべての青店のx座標より真に小さい
      - 制約より, すべての青店のxは異なる
  - なので，とってきた赤点のうち，最大のyを持つ赤点とペアを組む.
    - 任意の赤点を取ると最適でなくなる
      - 例: 青点=(3,3), 赤点={(0,0), (2,2)}のとき, 赤点(0,0)を取った場合
        - もし青点(100,1)があって,赤点(0,0)しか取れないなら最適でない

- xを固定することで，あとはyだけ考えれば良くなる

*/
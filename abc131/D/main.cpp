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

  // tasks[B] = {A_n,A_m...}
  map<ll, vector<ll>> tasks;

  rep(i, 0, N) {
    ll a, b;
    cin >> a >> b;
    tasks[b].push_back(a);
  }

  ll elapsed = 0;
  bool satisfied = true;
  for (auto it = tasks.begin(); it != tasks.end(); it++) {
    for (const auto i : it->second) elapsed += i;
    if (elapsed > it->first) satisfied = false;
  }

  std::cout << (satisfied ? "Yes" : "No") << endl;
}

// clang-format off

/* めも

- あるしごとaについて，仕事を終えるのにかかる時間を$A_a$,〆切時刻を$B_a$とする.

- しごとを1つ取りiとする.
  - すべての仕事の集合をSとし，その部分集合Xを↓のように作る
    - X:〆切時刻$ \leq B_i$のもの，すなわち$ X = \{ x\in S | B_y \leq B_i\}$

- いま，任意のXのしごとは時刻$B_i$より以前に終わらせなくてはならない
  - つまり，仕事iを終える前に，Xの,i以外の仕事をすべて終えていなくてはならない.
    - (ここで，あるしごと $ j \in X $の〆切 $B_j$が $B_j = B_i$のとき, 仕事iとjを交換しても構わない.
      - そのようにしても，このおはなしは成り立つ
  - よって,仕事iを〆切$B_i$に間に合わせるためには,
    - $ \sum_{k \in X} A_k \leq B_i$を満たしていなければならない.

- したがって, 〆切時刻の最も早い仕事を1つとって
  - 集合Xにそれを加えて(最初はX={})
  - その仕事が〆切に間に合うかを確認する
    - ってのを，すべての仕事について再帰的にみてけばいい

- ...はず

*/


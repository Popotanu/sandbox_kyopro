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
  map<int, int> bo;
  priority_queue<int> que;
  rep(i, 0, N) {
    int a;
    cin >> a;
    bo[a]++;
    que.push(a);
  }

  int ans = 0;
  int dob = 0;

  rep(i, 1, N + 1) {
    bool ok = true;

    dbg(i);
    dbg(dob);
    dbg(que.size());

    if (bo[i] > 0) {
      dob += bo[i] - 1;

      // iがない
    } else {
      // だぶりが2個以上
      if (dob >= 2) {
        dob -= 2;

        // だぶりが1こでqueが存在する
      } else if (dob == 1 && !que.empty()) {
        dob -= 1;

        int b = que.top();
        // i以下は使い果たしてるはず
        if (b <= i) ok = false;
        que.pop();
      } else if (dob == 1 && que.empty()) {
        ok = false;

        // だぶりが1で,queがemptyは下にはいってしまっている
      } else {  //だぶりがない

        rep(j, 0, 2) {
          if (que.empty()) ok = false;
          // queから1つとる
          int b = que.top();
          if (b <= i) ok = false;
          que.pop();
        }
      }
    }

    if (ok) {
      ans++;
    } else {
      cout << ans << endl;
      return;
    }
  }
  cout << ans << endl;
}

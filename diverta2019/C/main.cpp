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

// https://atcoder.jp/contests/diverta2019/tasks/diverta2019_c
int N;
string S;
void _main() {
  cin >> N;  // <=10e4

  // i.BxA: 1,2,3とくっつく
  // ii.xxA: 1,3とくっつく
  // iii.Bxx: 1,2とくっつく
  // iv.xxx

  // 上界は？
  // s_iの端っこの文字だけを考える(中身は一旦無視する)と,
  // a, 1,3のペアで+1
  // b, 2,1のペアで+1
  // c, 1,1のペアで+1
  //    BxA BxA BxA: 1の数-1だけペア
  // ひとつの1を2と3で共有できる
  // xxA BxA Bxx で+2できる

  // よって上界は
  // 2,3が存在する場合
  // min(i,iii) + min(i,ii) = i + min(ii , iii)

  // しない場合
  // max(i-1,0)

  int a = 0, b = 0, c = 0;
  int ans = 0;
  rep(i, 0, N) {
    cin >> S;
    rep(j, 0, S.size() - 1) {
      if (S[j] == 'A' && S[j + 1] == 'B') ans++;
    }
    if (S.front() == 'B' && S.back() == 'A') {
      a++;
    } else if (S.front() == 'B') {
      c++;
    } else if (S.back() == 'A') {
      b++;
    }
  }

  if (b == 0 && c == 0) {
    ans += max(a - 1, 0);
  } else {
    ans += a + min(b, c);
  }

  cout << ans << endl;
}

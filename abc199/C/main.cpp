#include <bits/stdc++.h>

using namespace std;

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

int N, Q;
string S;
void _main() {
  // N<= 2*10^5
  // Q<= 3*10^5
  cin >> N >> S >> Q;

  // abcd efgh
  // 2
  // 1 2 5
  // N=4
  // efgh abcd
  // eagh fbcd
  // fbcd eagh
  // abcd efgh

  // T=1: 互換(A_i B_i)
  // T=2: 前半分とうしろ半分を交換
  // 反転して真ん中で分けてそれぞれもっかい反転すれば良さそう

  // T2が奇数回のときにT1が呼ばれたときは
  // Z/2NZを考えて
  // swapするindexを,index+NしてあげればOK

  bool is_t2 = false;
  rep(i, 0, Q) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      a--;
      b--;
      if (is_t2) {
        a = (a + N) % (2 * N);
        b = (b + N) % (2 * N);
      }
      swap(S[a], S[b]);
    } else {
      // reverse 1回で2N/2=Nかいのswap
      // T2呼ばれるたびに毎回置換すると,O(NQ)だからTLE
      is_t2 = !is_t2;
    }
  }
  if (is_t2) {
    reverse(all(S));
    reverse(S.begin(), S.begin() + N);
    reverse(S.end() - N, S.end());
  }
  cout << S << endl;
}

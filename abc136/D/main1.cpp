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

int N;
// doublingは2^kで考える
// 多くとも10^5の移動ですべてRLに吸い込まれる
// ゆえに2^32.+αでちょっと余裕持たせとけば安心.
int doubling[33][101010];
string A;

void _main() {
  cin >> A;
  N = A.size();  // <= 10^5だから,O(NlogN)くらいまででやりたい.

  // doublingの前処理をする
  // doubling[p][i] : = i番目のマスから2p回移動した先のマス

  // 1回目の移動
  rep(i, 0, N) {
    // 移動先の座標を格納していく
    //        R R R R R L
    // A[0]:  1 2 3 4 5 4
    if (A[i] == 'R') {
      doubling[0][i] = i + 1;
    } else {
      doubling[0][i] = i - 1;
    }
  }

  // A[0]: 1 2 3 4 5 4
  // p=0:
  // A[1]: 2 3 4 5 4 5
  // p=1:
  // A[2]: 4 5 4 5 4 5
  // ...

  rep(p, 0, 32) {
    // 2^p 回目の移動
    rep(i, 0, N) doubling[p + 1][i] = doubling[p][doubling[p][i]];
  }

  int ans[101010];
  rep(i, 0, N) ans[doubling[32][i]]++;
  rep(i, 0, N) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
}

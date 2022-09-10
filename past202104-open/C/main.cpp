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

int N, M;
void _main() {
  cin >> N >> M;
  int K;
  bitset<50> A[50];
  rep(i, 0, N) {
    cin >> K;
    rep(j, 0, K) {
      int a;
      cin >> a;
      A[i][a] = true;
    }
  }

  int P, Q;
  cin >> P >> Q;
  bitset<50> B;
  rep(i, 0, P) {
    int b;
    cin >> b;
    B[b] = true;
  }
  int ans = 0;
  rep(i, 0, 50) {
    if ((A[i] & B).count() >= Q) {
      ans++;
    }
  }
  cout << ans << endl;
}

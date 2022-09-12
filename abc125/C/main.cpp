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

#define dbgl(x) for(auto& i:x) cout << i << " "; cout << endl;

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
string A;
void _main() {
  cin >> N;
  vector<ll> A(N);
  fore(i, A) cin >> i;

  vector<int> cumgcd_l(A.size(), 0);
  cumgcd_l[0] = A.front();
  for (int i = 1; i < A.size(); i++) {
    cumgcd_l[i] = gcd(cumgcd_l[i - 1], A[i]);
  }

  vector<int> cumgcd_r(A.size(), 0);
  cumgcd_r[0] = A.back();
  rrep(i, A.size(), 0) { cumgcd_r[i] = gcd(cumgcd_r[i + 1], A[i]); }

  int ans = 0;
  rep(i, 0, N) {
    int g = 0;
    if (0 < i) g = gcd(g, cumgcd_l[i - 1]);
    dbg(g);
    g = gcd(g, cumgcd_r[i + 1]);
    chmax(ans, g);
  }

  cout << ans << endl;
}

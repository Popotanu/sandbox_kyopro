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
string A;
void _main() {
  // cin >> 町 >> 日数;
  // N,M <= 10e5
  cin >> N >> M;

  vector<int> d(N, 0);
  rep(i, 1, N) {
    int a;
    cin >> a;
    d[i] = d[i - 1] + a;
  }

  vector<int> mov(M);
  fore(i, mov) cin >> i;

  long long ans = 0;
  int now = 0;
  fore(i, mov) {
    ans += (d[now + i] - d[now]) * (i / abs(i));
    now += i;
  }

  ans %= 1LL * (int)pow(10, 5);
  cout << ans << endl;
}

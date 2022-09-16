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

// https://atcoder.jp/contests/abc125/tasks/abc125_d
int N;
void _main() {
  // N<=10e5, -10e9<= A_i <=10e9
  cin >> N;
  vector<ll> A(N);
  int minuses = 0;
  fore(i, A) {
    ll n;
    cin >> n;
    if (n < 0) minuses++;
    i = n;
  }

  ll mm = infl;
  ll ans =
      accumulate(A.begin(), A.end(), 0LL, [&mm](ll acc, const auto& current) {
        mm = min(mm, abs(current));
        return acc + abs(current);
      });

  if (minuses % 2 == 1) ans -= mm * 2;

  cout << ans << endl;
}

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
string A;
void _main() {
  cin >> N;
  vector<ll> A(N);
  fore(i, A) cin >> i;

  // cumsumの同じ値の要素を2つ取ってきたときに1ペア成立？
  // 0 1 4 0 2 4 2
  // 1 3 -4 2 2 -2
  // |     |
  //     |     |
  //         |     |

  // 1,3.-4
  // -4,2,2
  // 2,-2

  // 1 -1 1 -1 1 -1 1

  vector<ll> cumsum(A.size() + 1, 0);
  for (int i = 0; i < A.size(); i++) {
    cumsum[i + 1] = cumsum[i] + A[i];
  }

  map<ll, int> zero;
  rep(i, 0, cumsum.size()) { zero[cumsum[i]]++; }

  long long ans = 0;
  fore(i, zero) { ans += 1LL * i.second * (i.second - 1) / 2; }
  cout << ans << endl;
}

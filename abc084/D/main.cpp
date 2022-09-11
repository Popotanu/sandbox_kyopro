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

vector<bool> is_prime(10e5 + 1, true);
// set<int> primes;
vector<int> cumsum_like2017(10e5 + 1, 0);

void sieve_2017(int n) {
  is_prime[0] = is_prime[1] = false;
  rep(i, 2, 10e5 + 1) {
    cumsum_like2017[i] = cumsum_like2017[i - 1];
    if (is_prime[i]) {
      // primes.insert(i);
      for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
      if (i == 2) continue;
      // if (primes.count((i + 1) / 2)) cumsum_like2017[i]++;
      if (is_prime[(i + 1) / 2]) cumsum_like2017[i]++;
    }
  }
}

int Q;
string A;
void _main() {
  // - N,(N+1)/2がどちらも素数
  // - ただし2以外
  // [l,r]で↑の条件を満たす数の個数

  cin >> Q;
  sieve_2017(10e5);

  rep(j, 0, Q) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    ans = cumsum_like2017[b] - cumsum_like2017[a - 1];
    cout << ans << endl;
  }
}

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
// string A;
void _main() {
  // N <= 10^5
  // 1<=A_i<= 10^9
  cin >> N;
  vector<int> A(N);
  fore(i, A) cin >> i;
  vector<int> AA;

  int ans = 1;

  rep(i, 0, N) {
    if (!AA.size()) {
      AA.push_back(A.at(i));
    } else if (AA[0] <= AA.back() && AA.back() <= A[i]) {
      AA.push_back(A.at(i));
    } else if (AA[0] >= AA.back() && AA.back() >= A[i]) {
      AA.push_back(A.at(i));
    } else {
      ans++;
      AA.clear();
      AA.push_back(A[i]);
    }
  }

  cout << ans << endl;
}

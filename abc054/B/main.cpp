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
  std::cin >> N >> M;
  vector<string> A(N);
  fore(i, A) cin >> i;

  vector<string> B(M);
  fore(i, B) cin >> i;

  bool ok = true, satisfied = false;
  rep(ay, 0, N - M + 1) {
    rep(ax, 0, N - M + 1) {
      ok = true;

      rep(by, 0, M) {
        rep(bx, 0, M) {
          if (A[ay + by][ax + bx] != B[by][bx]) ok = false;
        }
      }

      if (ok) satisfied = true;
    }
  }

  std::cout << (satisfied ? "Yes" : "No") << endl;
}
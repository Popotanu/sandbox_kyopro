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

int H, W;
string M[50];
void _main() {
  cin >> H >> W;
  rep(h, 0, H) { cin >> M[h]; }

  rep(h, 0, H) {
    rep(w, 0, W) {
      if (M[h][w] == '#') continue;
      int a = 0;
      rep(i, -1, 2) {
        rep(j, -1, 2) {
          if (h + i < 0 || w + j < 0) continue;
          if (h + i >= H || w + j >= W) continue;
          if (M[h + i][w + j] == '#') a++;
        }
      }

      M[h][w] = a + '0';
    }
  }

  rep(h, 0, H) { cout << M[h] << endl; }
}

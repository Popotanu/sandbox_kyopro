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

int N, Q;
string A;

// フォロー関係を隣接行列として持つ
// 条件よりフォローしてるorしてないのどっちかだから,各成分TorFの2値で間に合う.
// ∴ bitsetで実現できる.

// following[a][b]: aがbをふぉろーしてる？？
// following[a][b] = true; のように書ける.うれし.
bitset<100> following[100];
void _main() {
  cin >> N >> Q;

  rep(i, 0, Q) {
    int t, a;
    cin >> t >> a;
    a--;

    if (t == 1) {
      int b;
      cin >> b;
      b--;
      following[a][b] = true;
    } else if (t == 2) {
      rep(j, 0, N) {
        if (following[j][a]) following[a][j] = true;
      }
    } else {
      set<int> to_follow;
      rep(k, 0, N) {
        if (following[a][k]) to_follow.insert(k);
      }
      fore(x, to_follow) following[a] |= following[x];
    }
  }

  rep(i, 0, N) following[i][i] = false;

  rep(i, 0, N) {
    rep(j, 0, N) { cout << (following[i][j] ? "Y" : "N"); }
    cout << endl;
  }
}

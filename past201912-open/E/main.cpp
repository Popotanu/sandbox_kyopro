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
void _main() {
  cin >> N >> Q;
  vector<vector<int>> G(N);

  rep(i, 0, Q) {
    int t, x;
    cin >> t >> x;
    x--;

    if (t == 1) {
      int b;
      cin >> b;
      b--;
      G[x].push_back(b);
    } else if (t == 2) {
      rep(j, 0, G.size()) {
        auto found = find(all(G[j]), x);
        if (found != G[j].end()) G[x].push_back(j);
      }
    } else {
      set<int> following;
      rep(k, 0, G[x].size()) {
        rep(l, 0, G[G.at(x).at(k)].size()) {
          int n = G[G[x][k]][l];
          if (n != x) {
            following.insert(n);
          }
        }
      }

      fore(i, following) G.at(x).push_back(i);
    }
  }

  // YYNYNN
  // NNYNNN
  // ...

  fore(i, G) {
    string ans(N, 'N');
    rep(j, 0, N) {
      auto found = find(all(i), j);
      if (found != i.end()) ans[j] = 'Y';
    }
    cout << ans << endl;
  }
}

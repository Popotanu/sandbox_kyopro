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

struct UnionFind {
  vector<int> par, siz;

  UnionFind(int n) : par(n, -1), siz(n, 1) {}

  int root(int x) {
    if (par[x] == -1) return x;
    return root(par[x]);
  }

  bool is_same(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (x < y) swap(x, y);

    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  int size(int x) { return siz[root(x)]; }
};

int N, M;
void _main() {
  // 単純連結無向グラフの橋の本数を求める
  // N <=50, M <=50
  cin >> N >> M;

  vector<int> A(M), B(M);

  rep(i, 0, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  int ans = 0;
  rep(i, 0, M) {
    UnionFind uf(N);
    rep(j, 0, M) {
      if (i != j) uf.unite(A[j], B[j]);
    }
    rep(k, 0, N - 1) {
      if (!uf.is_same(N - 1, k)) {
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;
}

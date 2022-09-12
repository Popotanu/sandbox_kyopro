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

#define dbgl(x) for(auto& i:x) cout << i << " "; cout << endl;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
// clang-format on

template <typename T>
struct Segtree {
  // segtreeを用いた累積GCD
  // 乗っけるデータはモノイドであることが要請される.
  // 今回はベクトル空間とgcd
  T op(T& a, T& b) { return gcd(a, b); }
  const T ID = 0;

  int n;           // leafの数
  vector<T> tree;  // 完全二分木

  Segtree(int n_) : n(), tree(n_ * 4, ID) {
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x;
  }

  // 更新したい点から親へたどりながら演算をくりかえしてく
  // 下からばばばーって演算してくイメージ

  // i: 更新したい位置
  // x: 更新する値
  void update(int i, T x) {
    i += n - 1;
    tree[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;  // parent

      // 12345678
      // 1234 5678
      // 12 34 56 78
      // 1 2 3 4 5 6 7 8

      // 引数のようにすると左右の子にそれぞれアクセスできる
      tree[i] = op(tree[i * 2 + 1], tree[i * 2 + 2]);
    }
  }

  // 区間[a,b)のgcd
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

  T query_sub(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return ID;
    } else if (a <= l && r <= b) {
      return tree[k];
    } else {
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return op(vl, vr);
    }
  }

  void debug() { dbgl(tree); }
};

int N;
void _main() {
  cin >> N;

  vector<int> A(N);
  fore(i, A) cin >> i;

  Segtree<int> st(N);
  rep(i, 0, N) st.update(i, A[i]);

  // st.debug();

  int ans = 0;
  rep(i, 0, N) {
    int g = 0;
    // iを除外したときのgcdをもとめる
    // 累積和で求めるときと同じように,前から後ろから挟んで除外する値を求める.
    chmax(ans, gcd(g, gcd(st.query(0, i), st.query(i + 1, N))));
  }

  cout << ans << endl;
}

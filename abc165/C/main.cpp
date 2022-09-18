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

int N, M, Q;
string A;
vector<ll> a, b, c, d;

ll calc_score(vector<int>& A) {
  ll score = 0;
  rep(i, 0, Q) {
    if (A[b[i]] - A[a[i]] == c[i]) {
      score += d[i];
    }
  }
  return score;
}

ll rec(vector<int>& A) {
  if (A.size() == N) return calc_score(A);

  ll result = 0;
  int prev = (A.empty() ? 1 : A.back());

  // ここで数列Aを構成していく
  // 試しては捨て，試しては捨て....
  rep(i, prev, M + 1) {
    A.push_back(i);
    chmax(result, rec(A));
    A.pop_back();
  }

  return result;
}
void _main() {
  cin >> N >> M >> Q;
  a.resize(Q);
  b.resize(Q);
  c.resize(Q);
  d.resize(Q);
  rep(q, 0, Q) {
    cin >> a[q] >> b[q] >> c[q] >> d[q];
    a[q]--, b[q]--;
  }

  /*
  1<= A1<= A2 <= A_3 <= M=4
  得点が最大になるようにAを定める.

  3 4 3
  a b c d
  1 3 3 100 A3-A1 = 3 A={1,x,4}
  1 2 2 10            A={1,3,x}
  2 3 2 10            A={x,2,4}とか
*/

  vector<int> A;
  cout << rec(A) << endl;
}

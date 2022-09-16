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

// https://atcoder.jp/contests/abc101/tasks/arc099_a
int N, K;
string A;
void _main() {
  // K <= N <= 10e6
  cin >> N >> K;

  if (N == K) {
    cout << 1 << endl;
    return;
  }

  vector<int> A(N);
  int min_idx = 0;
  rep(i, 0, N) {
    int j;
    cin >> j;
    if (j == 1) min_idx = i;
    A.at(i) = j;
  }

  // となりあったKこを選ぶ，最小値で更新する
  // 区間は好きに選んでいい.front()とback()はつながってない
  // なるべく少ない操作ですべての値を等しくしたい

  // すべての値を1にする必要がある
  // 区間の中に1があれば，それをK-1こ先まで伝搬させることができる.

  int ans = ceil((float)min_idx / (float)(K - 1));
  ans += ceil((float)(N - min_idx) / (float)(K - 1));

  cout << ans << endl;
}

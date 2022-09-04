#include <bits/stdc++.h>

using namespace std;

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

int N;
string A;
int ans = 0;

void f(vector<int> &h, int left, int right) {
  if (left >= right) return;
  // 0 ∉ [left,right) なはずだから, 区間の全部のお花にいっせいに水やりする.
  // 回数: 区間の中で水やりの必要数が最小なものに合わせる

  int mi = 1000;
  rep(i, left, right) { mi = min(mi, h.at(i)); }

  ans += mi;

  // 0であるhの要素のindexを入れてく
  vector<int> zero;
  zero.push_back(-1);
  rep(i, left, right) {
    h.at(i) -= mi;
    if (h.at(i) == 0) zero.push_back(i);
  }
  zero.push_back(right);

  rep(i, 0, zero.size() - 1) {
    // 0を含まない区間に対して水やりする
    f(h, zero.at(i) + 1, zero.at(i + 1));
  }
}

int main() {
  cin >> N;
  vector<int> h(N);
  fore(i, h) cin >> i;

  f(h, 0, N);
  cout << ans << endl;
}

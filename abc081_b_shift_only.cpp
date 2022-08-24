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

int divv(int n) {
  int c = 0;
  if (n == 0) return 0;
  while (!(n & (1 << c))) {
    c++;
  }
  return c;
}

int main() {
  cin >> N;
  vector<int> A(N);
  vector<int> count(N);
  fore(i, A) { cin >> i; }

  rep(i, 0, A.size()) { count.at(i) = divv(A.at(i)); }
  cout << *min_element(all(count)) << endl;
}

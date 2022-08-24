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

double law_of_cosin(int a, int b, double theta) {
  return pow(a, 2) + pow(b, 2) - (2 * a * b * cos(theta));
}

int main() {
  string S, T;
  cin >> S >> T;
  vector<int> diff(S.size() - T.size() + 1);
  fore(i, diff) i = 0;

  rep(i, 0, diff.size()) {
    string ss = S.substr(i, T.size());
    rep(j, 0, T.size()) {
      if (ss[j] == T[j]) diff.at(i)++;
    }
  }

  int d = *max_element(all(diff));

  cout << T.size() - d << endl;
}

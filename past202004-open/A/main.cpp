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

int N;
string A, B;
void _main() {
  map<string, int> f;
  f.insert({"B9", -8});
  f.insert({"B8", -7});
  f.insert({"B7", -6});
  f.insert({"B6", -5});
  f.insert({"B5", -4});
  f.insert({"B4", -3});
  f.insert({"B3", -2});
  f.insert({"B2", -1});
  f.insert({"B1", 0});
  f.insert({"1F", 1});
  f.insert({"2F", 2});
  f.insert({"3F", 3});
  f.insert({"4F", 4});
  f.insert({"5F", 5});
  f.insert({"6F", 6});
  f.insert({"7F", 7});
  f.insert({"8F", 8});
  f.insert({"9F", 9});

  cin >> A >> B;
  cout << abs(f[A] - f[B]) << endl;
}

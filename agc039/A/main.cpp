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

int K;
string A;
void _main() {
  cin >> A >> K;
  vector<pair<char, int>> lens;

  // vector<int> per;
  int count = 0;

  lens.push_back({A[0], 1});

  rep(i, 1, A.size()) {
    if (lens.back().first == A[i]) {
      lens.back().second++;
    } else {
      lens.push_back({A[i], 1});
    }
  }

  long long ans = 0;
  rep(i, 0, lens.size()) { ans += floor(lens[i].second / 2) * K; }

  if (lens.size() > 1) {
    if (lens.front().first == lens.back().first) {
      if ((lens.front().second + lens.back().second) % 2 == 0) {
        ans += K - 1;
      }
    }
  }

  cout << ans << endl;
}

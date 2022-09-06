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
string A;
void _main() {
  cin >> A;

  // RLと並んでいたら(R L)の互換になる.
  // ゆえに ...RRRRRLとか,RLLLLL...とかになっても全部RLに吸い込まれる.

  // 移動回数が10^100に対してA.size() <=10^5
  // だから，すべてがRLに吸い込まれるって考えてOK
  // 互換だから偶奇から周期がみえるはず

  // RRR...RL
  // ......^いまここ
  // R: +=Rが続いた数 / 2
  // L: += Rが続いた数/ 2 (+連続数が奇数なら+1)

  // RLL...L
  // ^いまここ
  // R:  +=Lが続いた数 /2  (+奇数なら+1)
  // L: += Lが続いた数/2

  // 連長圧縮して，境目がRLとなる.
  // 圧縮ご:
  // listの先頭or末尾でないとき,左右にRLのペアがある
  // だから,自分のマスが0になるのは連続数-2: RRRR=> (L)R RR R(L) :2

  vector<pair<char, int>> lens;
  lens.push_back({A[0], 1});
  rep(i, 1, A.size()) {
    if (lens.back().first == A[i]) {
      lens.back().second++;
    } else {
      lens.push_back({A[i], 1});
    }
  }

  vector<int> ans(A.size(), 0);

  int j = 0;
  rep(i, 0, lens.size()) {
    if (lens[i].second == 1) {
      ans[j] += 1;
      j++;
      continue;
    }
    if (lens[i].first == 'R') {
      ans[j + lens[i].second] += lens[i].second / 2;
      ans[j + lens[i].second - 1] += ceil((float)lens[i].second / 2.0);
      j += lens[i].second;
    } else {
      ans[j - 1] += lens[i].second / 2;
      ans[j] += ceil((float)lens[i].second / 2.0);
      j += lens[i].second;
    }
  }

  fore(i, ans) { cout << i << " "; }
  cout << endl;
}

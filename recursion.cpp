// 参照: https://atcoder.jp/contests/apg4b/tasks/APG4b_v

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// =================================================================
// aからb(bからa)までの総和
// =================================================================
int sum_range(int a, int b) {
  int sup = max(a, b);
  int inf = min(a, b);
  if (sup == inf) return sup;

  return sum_range(inf, sup - 1) + sup;
}

// =================================================================
// vector(数列)の総和
// =================================================================
// ↓の補助関数
int vector_sum_from_i(const vector<int> &v, int i) {
  if (i == v.size()) return 0;

  int s = vector_sum_from_i(v, i + 1);
  return v.at(i) + s;
}
int vector_sum(const vector<int> &v) { return vector_sum_from_i(v, 0); }

// =================================================================
// 素数判定
// =================================================================
// ↓の補助関数
bool has_divisor(int n, int i) {
  // iがsqrt(n)より真に大きければ素数じゃない
  if (i * i > n) return false;

  return (n % i == 0 || has_divisor(n, i + 1));
}

// n ∈ ℕ, n >= 2. (素数の定義より)
bool is_prime(int n) {
  if (n < 2) return false;

  return has_divisor(n, 2);
}

// =================================================================
// 配列の要素を逆順にする
// =================================================================
vector<int> reverse_array_from(const vector<int> &v, int pos) {
  if (v.size() == pos) {
    vector<int> empty(0);
    return empty;
  }

  vector<int> tmp = reverse_array_from(v, pos + 1);
  tmp.push_back(v.at(pos));
  return tmp;
}

vector<int> reverse_array(const vector<int> &v) {
  return reverse_array_from(v, 0);
}

int main() {
  cout << "sum_range: " << sum_range(5, 8) << endl;

  int s = 10;
  vector<int> v(s);
  rep(i, s) v.at(i) = i + 1;

  cout << "vector_sum: " << vector_sum(v) << endl;
  cout << "vector_sum(expected): " << accumulate(v.begin(), v.end(), 0) << endl;

  cout << "is_prime (expect 0):" << is_prime(0) << endl;
  cout << "is_prime (expect 0):" << is_prime(3457) << endl;
  cout << "is_prime (expect 1):" << is_prime(117) << endl;
  cout << "is_prime (expect 1):" << is_prime(2397) << endl;

  for (const int &n : reverse_array(v)) cout << n << endl;
}
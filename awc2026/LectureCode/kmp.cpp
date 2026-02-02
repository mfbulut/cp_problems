#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int MOD = 1e9 + 7;
const int INF = 1e18;

vector<int> kmp(string s) {
  int n = (int)s.size();
  vector<int> v(n);
  v[0] = 0;

  for (int i = 1; i < n; i++) {
    int j = v[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = v[j - 1];
    }
    if (s[i] == s[j]) j++;
    v[i] = j;
  }
  return v;
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string a, b; cin >> a >> b;
  int n = b.size();
  b = b + ' ' + a;
  
  auto v = kmp(b);

  int ans = 0;
  for (auto& i : v) if (i == n) ans++;
  cout << ans;


  return 0;
}
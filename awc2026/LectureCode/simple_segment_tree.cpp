#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

struct SimpleSegmentTree {
  vector<int> tree;
  int n;
  SimpleSegmentTree(int _n) {
    n = _n;
    tree = vector<int>(4 * n);
  }
  // nl = node_left, nr = node_right
  // i = segment tree'deki node'un indexi
  // idx = gercek array'deki degisecek index
  // val = o index'in hangi deger ile degisecegi
  void update(int idx, int val, int i, int nl, int nr) {
    if (idx < nl || idx > nr) return;
    if (nl == nr) {
      tree[i] = val;
      return;
    }
    int mid = (nl + nr) / 2;
    update(idx, val, 2 * i, nl, mid);
    update(idx, val, 2 * i + 1, mid + 1, nr);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
  // ql = query_left, qr = query_right
  int query(int ql, int qr, int i, int nl, int nr) {
    if (qr < nl || ql > nr) {
      return 0;
    }
    if (ql <= nl && qr >= nr) {
      return tree[i];
    }
    int mid = (nl + nr) / 2;
    int left = query(ql, qr, 2 * i, nl, mid);
    int right = query(ql, qr, 2 * i + 1, mid + 1, nr);
    return left + right;
  }

  void build(vector<int>& arr, int i, int nl, int nr) {
    if (nl == nr) {
      tree[i] = arr[nl];
      return;
    }
    int mid = (nl + nr) / 2;
    build(arr, 2 * i, nl, mid);
    build(arr, 2 * i + 1, mid + 1, nr);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
};

// https://cses.fi/problemset/task/1648
void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  SimpleSegmentTree st(N);
  st.build(a, 1, 0, N - 1);
  while (Q--) {
    int qt;
    cin >> qt;
    if (qt == 1) {
      int idx, k;
      cin >> idx >> k;
      --idx;
      st.update(idx, k, 1, 0, N - 1);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << st.query(l, r, 1, 0, N - 1) << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
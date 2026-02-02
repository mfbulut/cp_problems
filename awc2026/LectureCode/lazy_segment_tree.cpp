#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

struct LazySegmentTree {
  vector<int> tree;
  vector<int> lazy;
  int n;
  LazySegmentTree(int _n) {
    n = _n;
    tree = vector<int>(4 * n);
    lazy = vector<int>(4 * n);
  }

  void push(int i, int nl, int nr) {
    if (lazy[i] != 0) {
      tree[i] += (nr - nl + 1) * lazy[i];
      if (nl != nr) {
        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];
      }
      lazy[i] = 0;
    }
  }

  void update(int ql, int qr, int val, int i, int nl, int nr) {
    push(i, nl, nr);
    if (qr < nl || ql > nr) return;
    if (ql <= nl && qr >= nr) {
      lazy[i] += val;
      push(i, nl, nr);
      return;
    }
    int mid = (nl + nr) / 2;
    update(ql, qr, val, 2 * i, nl, mid);
    update(ql, qr, val, 2 * i + 1, mid + 1, nr);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  int query(int ql, int qr, int i, int nl, int nr) {
    push(i, nl, nr);
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

// https://cses.fi/problemset/task/1651/
void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  LazySegmentTree st(N);
  st.build(a, 1, 0, N - 1);
  while (Q--) {
    int qt;
    cin >> qt;
    if (qt == 2) {
      int idx;
      cin >> idx;
      --idx;
      cout << st.query(idx, idx, 1, 0, N - 1) << '\n';
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      --l, --r;
      st.update(l, r, x, 1, 0, N - 1);
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
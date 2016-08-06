#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 1e9;

int n, sz, q, A[100010], B[100010];

int query(int lo, int hi) {
  int ret = INF;
  while (lo <= hi && lo % sz != 0) {
    ret = min(ret, A[lo++]);
  }
  while (lo <= hi && (hi + 1) % sz != 0) {
    ret = min(ret, A[hi--]);
  }
  while (lo < hi) {
    ret = min(ret, B[lo / sz]);
    lo += sz;
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &q);
  
  sz = sqrt(n);
  for (int i = 0 ; i <= sz ; ++i) {
    B[i] = INF;
  }
  
  for (int i = 0 ; i < n ; ++i) {
    scanf("%d", &A[i]);
    B[i / sz] = min(B[i / sz], A[i]);
  }
  
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) {
      swap(x, y);
    }
    printf("%d\n", query(x - 1, y - 1));
  }
}

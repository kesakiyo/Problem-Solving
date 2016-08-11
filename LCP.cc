#include <stdio.h>
#include <algorithm>

const int MAX = 500010;
char T[MAX];
int n, t = 1, group[MAX], newGroup[MAX], SA[MAX], rank[MAX], LCP[MAX];

bool comp(int x, int y) {
  if (group[x] == group[y]) {
    return group[x + t] < group[y + t];
  }
  return group[x] < group[y];
}

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%s", T);
  n = (int)strlen(T);
  
  for (int i = 0 ; i < n ; ++i) {
    SA[i] = i;
    group[i] = T[i] - 'a';
  }
  
  while (t < n) {
    group[n] = -1;
    std::sort(SA, SA + n, comp);
    
    newGroup[SA[0]] = 0;
    for (int i = 1 ; i < n ; ++i) {
      int prevGroup = newGroup[SA[i - 1]];
      if (comp(SA[i - 1], SA[i])) {
        newGroup[SA[i]] = prevGroup + 1;
      } else {
        newGroup[SA[i]] = prevGroup;
      }
    }
    
    for (int i = 0 ; i < n ; ++i) {
      group[i] = newGroup[i];
    }
    t <<= 1;
  }
  
  for (int i = 0 ; i < n ; ++i) {
    printf("%d ", SA[i] + 1);
  }
  printf("\nx ");
  
  for (int i = 0 ; i < n ; ++i) {
    rank[SA[i]] = i;
  }
  
  int len = 0;
  for (int i = 0 ; i < n ; ++i) {
    int k = rank[i];
    if (k) {
      int j = SA[k - 1];
      while (T[j + len] == T[i + len]) {
        ++len;
      }
      LCP[k] = len;
      if (len) {
        --len;
      }
    }
  }
  for (int i = 0 ; i < n ; ++i) {
    printf("%d ", LCP[i]);
  }
}

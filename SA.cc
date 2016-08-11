#include <stdio.h>
#include <algorithm>
#include <string.h>

char str[1010];
int n, t = 1, group[1010], newGroup[1010], SA[1010];

bool comp(int x, int y) {
  if (group[x] == group[y]) {
    return group[x + t] < group[y + t];
  }
  return group[x] < group[y];
}

int main() {
  scanf("%s", str);
  n = (int)strlen(str);
  
  for (int i = 0 ; i < n ; ++i) {
    SA[i] = i;
    group[i] = str[i] - 'a';
  }
  
  while (t <= n) {
    group[n] = -1;
    std::sort(SA, SA + n, comp);
    newGroup[SA[0]] = 0;
    for (int i = 1 ; i < n ; ++i) {
      if (comp(SA[i - 1], SA[i])) {
        newGroup[SA[i]] = newGroup[SA[i - 1]] + 1;
      } else {
        newGroup[SA[i]] = newGroup[SA[i - 1]];
      }
    }
    for (int i = 0 ; i < n ; ++i) {
      group[i] = newGroup[i];
    }
    t <<= 1;
  }
  
  for (int i = 0 ; i < n ; ++i) {
    printf("%s\n", str + SA[i]);
  }
}

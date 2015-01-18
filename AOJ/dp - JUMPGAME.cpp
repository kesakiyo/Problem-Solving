#include <stdio.h>
#include <string.h>

int t, n, data[110][110], DP[110][110];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		memset(DP, 0, sizeof(DP));
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++)
			for(int j=0 ; j<n ; j++)
				scanf("%d", &data[i][j]);

		// DP[x][y] => (x, y) 까지 도달할 수 있는 경우의 수
		// DP[x][y] = sigma(1, a) DP[pi][y] + sigma(1, b) DP[x][pi]
		// 현재 위치의 경우의 수는 현재 위치에 도달할 수 있는 전 칸들의 경우의 수를 합친것이 된다
		// 하지만 이러한 식의 문제점이 있다면 현재 위치에 도달할 수 있는 칸이 어디있는지 모른다는 것이다
		// 시점을 잠깐 바꾼다면 현재 위치에서 갈 수 있는 위치에다가 경우의 수를 더해줘도 된다는 것을 알 수 있다
		// 다음 위치에 있는 곳에서 그 다음 위치로 갈 수 있는 곳을 계산할 때 다음 위치의 경우의 수는 변하지 않는다
		// 왜냐하면 갈 수 있는 위치가 오른쪽 또는 아래로 제한이 되어있기 때문이다
		// 기저사례는 (0, 0) 일때 1이라고 설정을 해 주면 된다
		DP[0][0]=1;
		for(int x=0 ; x<n ; x++) {
			for(int y=0 ; y<n ; y++) {
				int nextX=x+data[x][y], nextY=y+data[x][y];
				if(nextX<n) DP[nextX][y]+=DP[x][y];
				if(nextY<n) DP[x][nextY]+=DP[x][y];
			}
		}

		if(DP[n-1][n-1]) puts("YES");
		else puts("NO");
	}
}
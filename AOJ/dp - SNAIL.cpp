#include <stdio.h>
#include <string.h>

int t, n, m;
double DP[1010][1010];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		memset(DP, 0, sizeof(DP));
		scanf("%d%d", &n, &m);

		// DP[day][dist] => day일이 지난 후에 달팽이가 dist 위치에 있을 확률
		// DP[day][dist] = DP[day-1][dist-2]*0.75 + DP[day-1][dist-1]*0.25
		// 위와같은 점화식을 가지게 된다
		// 위 식대로 이중포문을 구현하게 되면 day와 dist의 크기에 따라 예외처리를 해 줘야 하므로
		// 식을 약간 변형시켜 day-1에서 가져오는 형식이 아닌 day+1로 확률을 보내주는 방법을 취한다면
		// 예외처리를 해 줄 필요가 없다.
		DP[0][0]=1.0;
		for(int day=0 ; day<m ; day++) {
			for(int dist=0 ; dist<n ; dist++) {
				DP[day+1][dist+2]+=DP[day][dist]*0.75;
				DP[day+1][dist+1]+=DP[day][dist]*0.25;
			}
		}

		// 답을 구할때는 한번 더 생각을 해 줘야 한다.
		// 달팽이가 탈출을 하게 되는 것은 정확히 dist가 n이 되는 경우도 있지만
		// dist가 n+1 이 되어서 탈출을 하는경우도 있다는 것을 생각해 줘야 한다
		// 이 두가지를 모든 day에 대해서 누적을 해 준다면 탈출 할 확률을 구할 수 있다
		double sol=0;
		for(int i=0 ; i<=m ; i++) sol+=DP[i][n]+DP[i][n+1];
		printf("%.10lf\n", sol);
	}
}
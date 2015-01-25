#include <stdio.h>
#include <algorithm>

using namespace std;

const double INF=1500*15;
int t, n;
double DP[1<<16][16], data[16][16];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++)
			for(int j=0 ; j<n ; j++)
				scanf("%lf", &data[i][j]);

		// DP[state][last] => 현재 state만큼의 도시를 방문했고 그 중 마지막 도시는 last였을 때 최솟값
		// state는 bitmask 연산을 이용해 집합으로 표시할 수 있다.
		// DP[state][last] = min(1, n) DP[state&(~(1<<last))][prev]+data[prev][last]
		// 대략적으로 위와같은 점화식으로 표현할 수 있다. 물론 prev에서 올 때의 state에는 prev가 포함이 되어있어야 한다
		for(int i=0 ; i<(1<<16) ; i++) for(int j=0 ;j<n ; j++) DP[i][j]=INF;

		// 기저사례. 첫 시작도시는 비용이 안드므로 0으로 초기화
		for(int i=0 ; i<n ; i++) DP[1<<i][i]=0;

		// 위 점화식을 구현한 것, bitmask를 이용해 구현할 수 있다
		for(int state=1 ; state<(1<<n) ; state++) {
			for(int last=0 ; last<n ; last++) {
				if(state&(1<<last)) continue;

				for(int prev=0 ; prev<n ; prev++)
					if(state&(1<<prev))
						DP[state|(1<<last)][last]=min(DP[state|(1<<last)][last], DP[state][prev]+data[prev][last]);
			}
		}

		// 마지막 도시가 어딘지에 따라 최소비용이 달라지므로 전부 탐색하며 최적해를 찾는다
		double sol=INF;
		for(int i=0 ; i<n ; i++) sol=min(sol, DP[(1<<n)-1][i]);
		printf("%.10lf\n", sol);
	}
}
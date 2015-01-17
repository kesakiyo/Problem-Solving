#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF=987654321;

int n, DP[1010][3], cost[1010][3];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++) for(int j=0 ; j<3 ; j++) scanf("%d", &cost[i][j]);

	// 최소값을 찾는것이기 때문에 DP테이플을 INF로 초기화 시켜준다
	for(int i=1 ; i<=n ; i++) for(int j=0 ; j<3 ; j++) DP[i][j]=INF;

	// DP[pos][cur] => 1번부터 pos번까지의 집을 색칠했고 pos번째 집을 cur로 칠했을 때 사용한 돈의 최소값
	// DP[pos][cur] = min(DP[pos][cur], DP[pos-1][prev] + cost[pos][cur]) : prev는 cur과는 다륵 색
	// 기저사례는 아무것도 칠하지 않았을 때, 즉 pos가 0일때 DP[0][0]~DP[0][2]를 0으로 만들어 준다
	// 구현의 편의를 위해 처음집을 1번, 마지막 집을 n번이라고 생각함
	for(int pos=1 ; pos<=n ; pos++)
		for(int cur=0 ; cur<3 ; cur++)
			for(int prev=0 ; prev<3 ; prev++)
				if(cur!=prev) DP[pos][cur]=min(DP[pos][cur], DP[pos-1][prev]+cost[pos][cur]);

	// 마지막 집을 색칠할 수 있는 경우가 세가지 이므로 그 중 최솟값을 가져온다
	int sol=INF;
	for(int i=0 ; i<3 ; i++) sol=min(sol, DP[n][i]);

	printf("%d\n", sol);
}
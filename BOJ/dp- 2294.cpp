#include <cstdio>
#define min(a, b) (a)<(b) ? (a):(b)

const int INF=987654321;
int n, k, coin[110], DP[10010];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	for(int i=0 ; i<=k ; i++) DP[i]=INF;
	for(int i=0 ; i<n ; i++) scanf("%d", &coin[i]);

	// DP 문제중 가장 기본적인 coin change(CC) 종류 중 한 문제이다
	// DP[cur] = min(DP[cur], allCase(0, n-1) DP[cur-coin[i]]+1)
	// 현재 금액을 만들 수 있는 경우의 수는 현재 선택한 동전의 금액만큼
	// 뺀 DP 테이블에서 값을 가져와 1을 더한 값이 가능 한 값이다
	// 그렇다면 현재 금액의 DP 테이블 값과 새롭게 계산한 값을 비교해 최소값을 유지해 준다

	DP[0]=0;
	for(int i=0 ; i<n ; i++)
		for(int j=coin[i] ; j<=k ; j++)
			DP[j]=min(DP[j], DP[j-coin[i]]+1);

	printf("%d\n", DP[k]);
}
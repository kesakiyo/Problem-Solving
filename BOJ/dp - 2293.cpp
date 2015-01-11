#include <cstdio>

int n, k, coin[110], DP[10010];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	for(int i=0 ; i<n ; i++) scanf("%d", &coin[i]);

	// 가장 대표적인 DP문제중 하나인 coin change(CC) 중 한 문제
	// 점화식을 세워본다면 아래와 같다
	// DP[cur] = sigma(0, n-1) DP[cur-coin[i]]
	// 위 수식을 딱히 말로 설명하기는 힘들거 같다
	// 여기서 이중 반복문이 필요한 데 밖에 동전을 먼저 둠으로
	// 순서 강제를 해 줘 중복되게 카운딩 하는 일을 없앤다

	DP[0]=1;
	for(int i=0 ; i<n ; i++)
		for(int j=coin[i] ; j<=k ; j++)
			DP[j]+=DP[j-coin[i]];

	printf("%d\n", DP[k]);
}
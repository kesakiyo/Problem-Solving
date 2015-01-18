#include <stdio.h>

const int MOD=1000000007;
int t, n, DP[110];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	// DP[len] => 2*1 크기의 사각형으로 2*len 사각형을 채우는 방법의 수
	// DP[len] = DP[len-1] + DP[len-2]
	// 위 수식이 나오는 이유
	// 1. len-1에 2*1사각형을 세워서 채우는 방법
	// 2. len-2에 2*1사각형을 눕혀서 2개 채우는 방법
	// 이렇게 len을 만드눈 두가지 방법이 존재하기 때문이다
	DP[0]=DP[1]=1;
	for(int i=2 ; i<=100 ; i++) {
		DP[i]=DP[i-1]+DP[i-2];
		DP[i]%=MOD;
	}

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", DP[n]);
	}
}
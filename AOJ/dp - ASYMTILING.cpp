#include <stdio.h>

typedef long long ll;
const ll MOD=1000000007;
int t, n;
ll DP[110], SOL[110];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	// 일반적인 타일링의 방법
	DP[0]=DP[1]=1;
	for(int i=2 ; i<=100 ; i++) {
		DP[i]=DP[i-1]+DP[i-2];
		DP[i]%=MOD;
	}

	// sol[len] => 길이가 len일 때 비대칭 타일링의 방법
	// 정 가운데를 기점으로 타일링이 대칭이 되는 경우의 수를 생각해보자
	// 첫 번째로 정가운데에 아무것도 없는 경우다. 이 때 왼쪽 len/2 만큼 결정이 된다면 오른쪽은 자동적으로 결정이 된다
	// 두 번째로 정가운데에 [ | ] 이렇게 세로막대기가 하나 있다고 생각을 해보자. 역시 왼쪽 len/2 만큼이 결정이 되면 오른족도 결정이 된다
	// 마지막 세 번째로 정가운데에 [ = ] 가로박대기 두개가 있다고 생각을 해보자. 이것도 마찬가지다.
	// 이제 len이 홀수, 짝수일때를 생각해 보자.
	// 홀수일때는 두 번째 경우밖에 존재하지 않는다.
	// 짝수일때는 첫 번째, 두 번째의 경우의 수가 존재한다.
	// len일 때 가능한 타일링 개수에서 대칭을 만들 수 있는 왼쪽의 경우의 수를 뺀다면 비대칭 타일링의 값이 나온다.
	for(int i=3 ; i<=100 ; i++) {
		if(i&1) SOL[i]=DP[i]-DP[i/2];
		else SOL[i]=DP[i]-DP[i/2]-DP[i/2-1];
		SOL[i]=(SOL[i]+2*MOD)%MOD;
	}

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%lld\n", SOL[n]);
	}
}
#include <cstdio>

typedef long long ll;

int n;
ll DP[100][2];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	DP[1][1]=1;
	scanf("%d", &n);

	// DP[pos][last] = (last is 0) DP[pos-1][0] + DP[pos-1][1]
	//                 (last is 1) DP[pos-1][0]
	// 수학적으로 계산해 풀 수 있지만 2차원 DP 테이블을 잡아 간단하게 해결할 수 있다
	// DP[pos][last]의 뜻은 pos번째 자리수에서 last로 끝날 수 있는 경우의 수 이다
	// 만약 last가 0 이라면 pos-1번째의 0으로 끝난 경우의 수와 1로 끝난 경우의 수를 가져오고
	// 만약 last가 1 이라면 pos-1번째의 0으로 끝난 경우의 수만 가져온다
	// 마지막으로 답을 출력할 때 n번째 위치에서 0으로 끝난 경우의 수와 1로 끝난 경우의 수를 더해줘 출력한다

	for(int pos=2 ; pos<=n ; pos++)
	{
		for(int last=0 ; last<=1 ; last++)
		{
			if(last==0) DP[pos][last]+=DP[pos-1][0]+DP[pos-1][1];
			else DP[pos][last]+=DP[pos-1][0];
		}
	}

	printf("%lld\n", DP[n][0]+DP[n][1]);
}
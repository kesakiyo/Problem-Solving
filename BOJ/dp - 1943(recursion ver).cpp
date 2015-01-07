#include <cstdio>
#include <cstring>

int n, c, r, sum, cost[110], num[110], cache[110][50010];

// DP[pos][money] 는 pos번째 동전에서 money원을 만들었을 때 
// sum/2 원을 만들 수 있는 경우의 수를 의미한다
int solution(int pos, int money)
{
	// sum/2 원을 만들어다면 더이상 볼 필요가 없으므로 return 1
	// pos가 n번째가 되었다면, 즉 더 선택할 동전이 없다면 return 0
	if(money==sum/2) return 1;
	else if(pos==n) return 0;

	// 이미 이 문제의 해를 구했다면 return ret
	int& ret=cache[pos][money];
	if(ret!=-1) return ret;

	ret=0;
	// 현재 위치의 동전을 0개부터 num[pos]개까지 모두 선택해 본다
	// 만약 가능한게 한가지라도 나온다면 더이상 볼 필요가 없다
	// 답은 총 가능한 개수가 아닌 가능하냐 불가능하냐 이기 때문
	for(int i=0 ; i<=num[pos] ; i++)
		if(!ret) ret+=solution(pos+1, money+cost[pos]*i);

	return ret;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while(scanf("%d", &n)!=EOF)
	{
		sum=0;
		for(int i=0 ; i<n ; i++)
		{
			scanf("%d%d", &cost[i], &num[i]);
			sum+=cost[i]*num[i];
		}

		// 모든 동전의 합이 홀수라면 반으로 나눌 수 없으므로
		// 0 을 출력하고 다음 테스트 케이스로 넘어간다
		if(sum&1) 
		{
			puts("0");
			continue;
		}

		memset(cache, -1, sizeof(cache));
		int sol=solution(0, 0);

		if(sol) puts("1");
		else puts("0");
	}
}
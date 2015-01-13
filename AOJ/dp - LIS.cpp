#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int t, n, data[510], DP[510];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++) scanf("%d", &data[i]);
		memset(DP, 0, sizeof(DP));

		int sol=0;

		// DP[pos] => pos번째 수를 마지막으로 선택했을 때 가장 긴 증가수열의 길이
		// 그렇다면 DP[pos]의 값은 pos번째 수보다 작은 위치에 있는 수들의 DP 테이블의 값 + 1 이 된다
		// DP[pos] = max (DP[i] + 1) : ( 0<= i < pos, data[i] < data[pos] )
		// 여기서 DP[pos]의 기저사례를 정해주는데 기본값을 1이 된다. 
		// 왜냐하면 아무리 짧아도 자기 자신이 처음이자 마지막이 될 수 있기 때문
		for(int i=0 ; i<n ; i++)
		{
			// 기저사례를 정해 준다
			DP[i]=1;

			// 가능성이 있는 모든 수에 대해 최대값을 비교한다
			for(int j=0 ; j<i ; j++)
				if(data[j]<data[i]) DP[i]=max(DP[i], DP[j]+1);

			// 여기서 sol이라는 변수에 대해서도 최대값을 유지해 줘야 하는데
			// 마지막 수를 어떤것을 선택할 지 모르기 때문이다
			sol=max(sol, DP[i]);
		}

		printf("%d\n", sol);
	}
}
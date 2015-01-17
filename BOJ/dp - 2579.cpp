#include <stdio.h>
#include <algorithm>

using namespace std;

int n, cost[310], DP[310][3];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++) scanf("%d", &cost[i]);

	// DP[pos][cnt] => pos번째 계단을 cnt번 연속해서 밟았을 때 얻을 수 있는 점수의 최대 값
	// 이 수식에서는 cnt 0 은 사용이 안되지만 각각의 인덱스가 가지는 뜻을 명확히 하기 위해 크기를 3으로 잡음
	// DP[pos][cnt] = if(cnt==1) max(DP[pos-2][1], DP[pos-2][2]) + cost[pos]
	//                if(cnt==2) DP[pos-1][1] + cost[pos]
	// 만약 현재 위치를 두번 연속해서 밟는것이라면 무조건 바로 전 위치에서 와야되는 것임을 알 수 있다
	// 하지만 현재 위치를 첫 번째로 밟는것이라면 그것은 두 번째 전 계단에서 오는것이다.
	// 두 번째 전 계단에서 가지고 올 수 있는 값은 두 번째 전 계단을 한 번 연속해서 밟았냐, 두 번 연속해서 밟았냐 총 두가지이다
	// 이 두가지중 최댓값을 가지고 와서 현재 위치의 최적값을 계산하면 된다
	DP[1][1]=cost[1];
	for(int pos=2 ; pos<=n ; pos++)
	{
		DP[pos][1]=max(DP[pos-2][1], DP[pos-2][2])+cost[pos];
		DP[pos][2]=DP[pos-1][1]+cost[pos];
	}

	// 마지막 계단을 밟는 방법또한 한 번 연속해서 밟았냐 두 번 연속해서 밟았냐 이므로 둘 중 최대값을 출력한다
	int sol=max(DP[n][1], DP[n][2]);
	printf("%d\n", sol);
}
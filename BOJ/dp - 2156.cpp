#include <stdio.h>
#include <algorithm>

using namespace std;

int n, cost[10010], DP[10010][3];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++) scanf("%d", &cost[i]);

	// DP[pos][cnt] => pos번째 포도주를 cnt번째로 선택했을 때 최대 값
	// DP[pos][cnt] = 만약 현재 위치의 포도주를 선택했다면 DP[pos-1][cnt-1] + cost[pos]
	//                현재 위치의 포도주를 선택하지 않았다면 max(DP[pos-1][0~2])                 
	// pos번째의 최적해를 결정할 때 약간의 분기가 필요하다
	// 만약 pos번째의 포도주를 cnt번째로 선택할 때 의 최적해를 구한다고 생각을 하자
	// 그렇다면 pos-1번째 포도주를 cnt-1 번째 선택한 최적해와 현재 위치의 포도주의 양을 더하는 것이 
	// 최적이라는 것은 자명한 사실이다. 하지만 cnt가 0이라면, 즉 현재의 포도주를 선택하지 않는다면 어떻게 될까
	// 그렇다면 pos-1번째에서 선택할 수 있는 cnt값은 [0, 1, 2] 이 셋중에 하나가 될 것이다.
	// 이 부분을 잘 생각해서 코드를 짜면 된다
	// 역시 구현의 편의를 위해 pos를 1번부터 n번까지 라고 생각한다
	for(int pos=1 ; pos<=n ; pos++)
	{
		for(int cnt=0 ; cnt<3 ; cnt++)
		{
			if(cnt) DP[pos][cnt]=DP[pos-1][cnt-1]+cost[pos];
			else for(int prev=0 ; prev<3 ; prev++) DP[pos][cnt]=max(DP[pos][cnt], DP[pos-1][prev]);
		}
	}

	int sol=0;
	for(int i=0 ; i<3 ; i++) sol=max(sol, DP[n][i]);

	printf("%d\n", sol);
}
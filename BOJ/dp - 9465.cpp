#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int t, n, cost[2][100010], DP[2][100010];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		memset(DP, 0, sizeof(DP));
		
		// 예외처리의 번거로움을 줄이기 위해 n을 1 증가
		scanf("%d", &n); n++;
		for(int i=0 ; i<2 ; i++)
			for(int j=2 ; j<=n ; j++)
				scanf("%d", &cost[i][j]);

		// DP[x][y] => (x, y)의 스티커를 선택했을 때 얻을 수 있는 최대 점수
		// DP[x][y] = max(DP[prevX][y-1], DP[prevX][y-2]) + cost[x][y]
		// (x, y)의 스티커를 선택한다고 생각했을 때 우선적으로 전에 선택할 수 없는 스티커는 (x, y-1) 이다
		// 즉 같은 행이 있던 바로 전 스티커는 선택할 수 없다. 이는 자명한 사실이다
		// 그렇다면 먼저 생각할 수 있는 바로 전에 선택한 스티커는 (x XOR 1, y-1) 이다.
		// x가 0이라면 prevX는 1이 될 것이고 x가 1이라면 prevX는 0이 될 것이다. 이를 비트연산자 XOR을 이용해
		// 깔끔하게 구현을 할 수 있다. (1을 XOR시킨다면 bit가 토글이 된다)
		// 일단 바로 전에 선택한 스티커들 중 한개의 후보를 선택했다. 그렇다면 나머지는 무엇일까
		// (x XOR 1, y-2) 또한 바로 전에 선택한 스티커의 후보 중 하나가 될 수 있다.
		// 만약 (x XOR 1, y-2)의 스티커를 선택했다면 (x XOR 1, y-1)의 스티커를 선택할 수 있기 때문이다.
		// 그렇다면 (x, y-2)의 스티커는 후보군에 들이 못하는 것일까?
		// 결론부터 말하자면 굳이 고려할 필요가 없다. 왜냐하면 (x XOR 1, y-1)을 선택했을 때의 최적값에
		// (x, y-2)를 선택한 경우의 수가 포함이 되어있기 때문이다. 이해가 안된다면 그림을 그려서 좌표를 쓰고
		// 생각해 본다면 이해가 갈 것이다.
		// 최종적으로 (x, y)를 선택하기 전에 선택한 스티커 (x XOR 1, y-1) 과 (x XOR 1, y-2) 둘 중 더 큰 최적값을 가지고 와
		// 현재 (x, y)를 계산해 주면 된다
		for(int j=2 ; j<=n ; j++)
			for(int i=0 ; i<2 ; i++)
				DP[i][j]=max(DP[i^1][j-1], DP[i^1][j-2])+cost[i][j];

		int sol=max(DP[0][n], DP[1][n]);
		printf("%d\n", sol);
	}
}
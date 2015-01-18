#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int t, n, data[510][510], DP[510][510], PATH[510][510];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		memset(DP, 0, sizeof(DP));
		memset(PATH, 0, sizeof(PATH));
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++)
			for(int j=0 ; j<=i ; j++)
				scanf("%d", &data[i][j]);

		// DP[i][j] = max(DP[i+1][j], DP[i+1][j+1]) + data[i][j]
		// 위 점화식 대로 코드를 짜면 (i, j)에서 최대값을 가지는 DP테이블을 모두 채울 수 있다
		// 하지만 이 문제에서 원하는 것은 단순 최대값이 아니라 경로를 찾는 문제이다
		for(int i=n-1 ; i>=0 ; i--)
			for(int j=0 ; j<=i ; j++)
				DP[i][j]=max(DP[i+1][j], DP[i+1][j+1])+data[i][j];

		// 이미 완성된 DP테이블을 가지고 최적해가 도출된 방향을 찾아 나가는 것은 꽤나 자주 볼 수 있는 문제다
		// 우선 DP[i][j] 가 어떻게 도출이 된 것인가에 대해서 이해가 있어야 한다
		// 앞서 말했듯이 DP[i][j] 는 DP[i+1][j], DP[i+1][j+1] 두 가지 방향에서 올 수 있는 가능성이 존재한다
		// 그렇다면 DP[i][j] 에서 data[i][j]를 뺀 값을 DP[i+1][j]과 DP[i+1][j+1]이랑 비교를 해 보자
		// 만약 똑같은게 존재 한다면 최적해는 값이 똑같은 방향에서 오게 된 것이다.
		// 이를 이용해 PATH[i][j]를 정의하자. PATH[i][j]는 (i, j)에서 최적값을 가지는 경로의 수이다.
		// 최적해가 도출될 수 있는 곳의 경로의 수를 더해서 올라가면 결국 (0, 0)에서 최적해를 가지는 경로의 수를 찾을 수 있다
		// 기저사례로 가장 밑의 행을 모두 1로 초기화 시켜 준다.
		for(int i=0 ; i<n ; i++) PATH[n-1][i]=1;
		for(int i=n-2 ; i>=0 ; i--) {
			for(int j=0 ; j<=i ; j++) {
				if(DP[i+1][j]+data[i][j]==DP[i][j]) PATH[i][j]+=PATH[i+1][j];
				if(DP[i+1][j+1]+data[i][j]==DP[i][j]) PATH[i][j]+=PATH[i+1][j+1];
			}
		}

		printf("%d\n", PATH[0][0]);
	}
}
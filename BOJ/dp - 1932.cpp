#include <cstdio>
#include <algorithm>

using namespace std;

int n, data[510][510], DP[510][510];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<=i ; j++)
			scanf("%d", &data[i][j]);

	// DP[i][j] = max(DP[i+1][j], DP[i+1][j+1]) + data[i][j]
	// 위 점화식 대로 코드를 짠다면 답이 나온다
	for(int i=n-1 ; i>=0 ; i--)
		for(int j=0 ; j<=i ; j++)
			DP[i][j]=max(DP[i+1][j], DP[i+1][j+1])+data[i][j];

	printf("%d\n", DP[0][0]);
}
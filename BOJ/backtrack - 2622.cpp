#include <cstdio>

int n, sol;

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);

	// 이 문제 같은 경우 n^3으로 모든 경우를 다 탐색해 볼 경우 TL이 난다
	// 이 때 i와 j를 결정하면 k는 자동으로 결정이 된다는 점을 이용하면 n^2으로 시간복잡도를 줄일 수 있다
	// 또한 [ i<=j<=k ] 의 순서강제를 통해 중복되는 경우의 수를 제거할 수 있다
	for(int i=1 ; i<n ; i++)
	{
		for(int j=i ; j<n ; j++)
		{
			// i와 j가 만족이 된다면 k는 자동으로 결정
			int k=n-i-j;

			// 순서강제에 위배가 된다면 더이상 볼 필요가 없으므로 break을 통해 빠져나간다
			if(k<j) break;

			// 삼각형의 기본 법칙, 가장 큰 변은 다른 두 변의 합보다 작아야 된다
			if(i+j>k) sol++;
		}
	}
	printf("%d\n", sol);
}
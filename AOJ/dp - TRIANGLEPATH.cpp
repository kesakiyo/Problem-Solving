#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int t, n, data[510][510], DP[510][510];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		memset(DP, 0, sizeof(DP));
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++)
			for(int j=0 ; j<=i ; j++)
				scanf("%d", &data[i][j]);

		// DP[i][j] = max(DP[i+1][j], DP[i+1][j+1]) + data[i][j]
		// �� ��ȭ�� ��� �ڵ带 §�ٸ� ���� ���´�
		for(int i=n-1 ; i>=0 ; i--)
			for(int j=0 ; j<=i ; j++)
				DP[i][j]=max(DP[i+1][j], DP[i+1][j+1])+data[i][j];

		printf("%d\n", DP[0][0]);
	}
}
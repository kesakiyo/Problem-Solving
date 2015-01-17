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

	// DP[pos][cnt] => pos��° �����ָ� cnt��°�� �������� �� �ִ� ��
	// DP[pos][cnt] = ���� ���� ��ġ�� �����ָ� �����ߴٸ� DP[pos-1][cnt-1] + cost[pos]
	//                ���� ��ġ�� �����ָ� �������� �ʾҴٸ� max(DP[pos-1][0~2])                 
	// pos��°�� �����ظ� ������ �� �ణ�� �бⰡ �ʿ��ϴ�
	// ���� pos��°�� �����ָ� cnt��°�� ������ �� �� �����ظ� ���Ѵٰ� ������ ����
	// �׷��ٸ� pos-1��° �����ָ� cnt-1 ��° ������ �����ؿ� ���� ��ġ�� �������� ���� ���ϴ� ���� 
	// �����̶�� ���� �ڸ��� ����̴�. ������ cnt�� 0�̶��, �� ������ �����ָ� �������� �ʴ´ٸ� ��� �ɱ�
	// �׷��ٸ� pos-1��°���� ������ �� �ִ� cnt���� [0, 1, 2] �� ���߿� �ϳ��� �� ���̴�.
	// �� �κ��� �� �����ؼ� �ڵ带 ¥�� �ȴ�
	// ���� ������ ���Ǹ� ���� pos�� 1������ n������ ��� �����Ѵ�
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
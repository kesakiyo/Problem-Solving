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

	// DP[pos][cnt] => pos��° ����� cnt�� �����ؼ� ����� �� ���� �� �ִ� ������ �ִ� ��
	// �� ���Ŀ����� cnt 0 �� ����� �ȵ����� ������ �ε����� ������ ���� ��Ȯ�� �ϱ� ���� ũ�⸦ 3���� ����
	// DP[pos][cnt] = if(cnt==1) max(DP[pos-2][1], DP[pos-2][2]) + cost[pos]
	//                if(cnt==2) DP[pos-1][1] + cost[pos]
	// ���� ���� ��ġ�� �ι� �����ؼ� ��°��̶�� ������ �ٷ� �� ��ġ���� �;ߵǴ� ������ �� �� �ִ�
	// ������ ���� ��ġ�� ù ��°�� ��°��̶�� �װ��� �� ��° �� ��ܿ��� ���°��̴�.
	// �� ��° �� ��ܿ��� ������ �� �� �ִ� ���� �� ��° �� ����� �� �� �����ؼ� ��ҳ�, �� �� �����ؼ� ��ҳ� �� �ΰ����̴�
	// �� �ΰ����� �ִ��� ������ �ͼ� ���� ��ġ�� �������� ����ϸ� �ȴ�
	DP[1][1]=cost[1];
	for(int pos=2 ; pos<=n ; pos++)
	{
		DP[pos][1]=max(DP[pos-2][1], DP[pos-2][2])+cost[pos];
		DP[pos][2]=DP[pos-1][1]+cost[pos];
	}

	// ������ ����� ��� ������� �� �� �����ؼ� ��ҳ� �� �� �����ؼ� ��ҳ� �̹Ƿ� �� �� �ִ밪�� ����Ѵ�
	int sol=max(DP[n][1], DP[n][2]);
	printf("%d\n", sol);
}
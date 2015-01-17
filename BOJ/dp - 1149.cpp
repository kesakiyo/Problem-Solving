#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF=987654321;

int n, DP[1010][3], cost[1010][3];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i=1 ; i<=n ; i++) for(int j=0 ; j<3 ; j++) scanf("%d", &cost[i][j]);

	// �ּҰ��� ã�°��̱� ������ DP�������� INF�� �ʱ�ȭ �����ش�
	for(int i=1 ; i<=n ; i++) for(int j=0 ; j<3 ; j++) DP[i][j]=INF;

	// DP[pos][cur] => 1������ pos�������� ���� ��ĥ�߰� pos��° ���� cur�� ĥ���� �� ����� ���� �ּҰ�
	// DP[pos][cur] = min(DP[pos][cur], DP[pos-1][prev] + cost[pos][cur]) : prev�� cur���� �ٸ� ��
	// ������ʴ� �ƹ��͵� ĥ���� �ʾ��� ��, �� pos�� 0�϶� DP[0][0]~DP[0][2]�� 0���� ����� �ش�
	// ������ ���Ǹ� ���� ó������ 1��, ������ ���� n���̶�� ������
	for(int pos=1 ; pos<=n ; pos++)
		for(int cur=0 ; cur<3 ; cur++)
			for(int prev=0 ; prev<3 ; prev++)
				if(cur!=prev) DP[pos][cur]=min(DP[pos][cur], DP[pos-1][prev]+cost[pos][cur]);

	// ������ ���� ��ĥ�� �� �ִ� ��찡 ������ �̹Ƿ� �� �� �ּڰ��� �����´�
	int sol=INF;
	for(int i=0 ; i<3 ; i++) sol=min(sol, DP[n][i]);

	printf("%d\n", sol);
}
#include <stdio.h>

const int MOD=1000000007;
int t, n, DP[110];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	// DP[len] => 2*1 ũ���� �簢������ 2*len �簢���� ä��� ����� ��
	// DP[len] = DP[len-1] + DP[len-2]
	// �� ������ ������ ����
	// 1. len-1�� 2*1�簢���� ������ ä��� ���
	// 2. len-2�� 2*1�簢���� ������ 2�� ä��� ���
	// �̷��� len�� ���崫 �ΰ��� ����� �����ϱ� �����̴�
	DP[0]=DP[1]=1;
	for(int i=2 ; i<=100 ; i++) {
		DP[i]=DP[i-1]+DP[i-2];
		DP[i]%=MOD;
	}

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", DP[n]);
	}
}
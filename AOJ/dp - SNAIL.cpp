#include <stdio.h>
#include <string.h>

int t, n, m;
double DP[1010][1010];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		memset(DP, 0, sizeof(DP));
		scanf("%d%d", &n, &m);

		// DP[day][dist] => day���� ���� �Ŀ� �����̰� dist ��ġ�� ���� Ȯ��
		// DP[day][dist] = DP[day-1][dist-2]*0.75 + DP[day-1][dist-1]*0.25
		// ���Ͱ��� ��ȭ���� ������ �ȴ�
		// �� �Ĵ�� ���������� �����ϰ� �Ǹ� day�� dist�� ũ�⿡ ���� ����ó���� �� ��� �ϹǷ�
		// ���� �ణ �������� day-1���� �������� ������ �ƴ� day+1�� Ȯ���� �����ִ� ����� ���Ѵٸ�
		// ����ó���� �� �� �ʿ䰡 ����.
		DP[0][0]=1.0;
		for(int day=0 ; day<m ; day++) {
			for(int dist=0 ; dist<n ; dist++) {
				DP[day+1][dist+2]+=DP[day][dist]*0.75;
				DP[day+1][dist+1]+=DP[day][dist]*0.25;
			}
		}

		// ���� ���Ҷ��� �ѹ� �� ������ �� ��� �Ѵ�.
		// �����̰� Ż���� �ϰ� �Ǵ� ���� ��Ȯ�� dist�� n�� �Ǵ� ��쵵 ������
		// dist�� n+1 �� �Ǿ Ż���� �ϴ°�쵵 �ִٴ� ���� ������ ��� �Ѵ�
		// �� �ΰ����� ��� day�� ���ؼ� ������ �� �شٸ� Ż�� �� Ȯ���� ���� �� �ִ�
		double sol=0;
		for(int i=0 ; i<=m ; i++) sol+=DP[i][n]+DP[i][n+1];
		printf("%.10lf\n", sol);
	}
}
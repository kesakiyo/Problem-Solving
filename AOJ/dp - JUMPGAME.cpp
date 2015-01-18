#include <stdio.h>
#include <string.h>

int t, n, data[110][110], DP[110][110];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		memset(DP, 0, sizeof(DP));
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++)
			for(int j=0 ; j<n ; j++)
				scanf("%d", &data[i][j]);

		// DP[x][y] => (x, y) ���� ������ �� �ִ� ����� ��
		// DP[x][y] = sigma(1, a) DP[pi][y] + sigma(1, b) DP[x][pi]
		// ���� ��ġ�� ����� ���� ���� ��ġ�� ������ �� �ִ� �� ĭ���� ����� ���� ��ģ���� �ȴ�
		// ������ �̷��� ���� �������� �ִٸ� ���� ��ġ�� ������ �� �ִ� ĭ�� ����ִ��� �𸥴ٴ� ���̴�
		// ������ ��� �ٲ۴ٸ� ���� ��ġ���� �� �� �ִ� ��ġ���ٰ� ����� ���� �����൵ �ȴٴ� ���� �� �� �ִ�
		// ���� ��ġ�� �ִ� ������ �� ���� ��ġ�� �� �� �ִ� ���� ����� �� ���� ��ġ�� ����� ���� ������ �ʴ´�
		// �ֳ��ϸ� �� �� �ִ� ��ġ�� ������ �Ǵ� �Ʒ��� ������ �Ǿ��ֱ� �����̴�
		// ������ʴ� (0, 0) �϶� 1�̶�� ������ �� �ָ� �ȴ�
		DP[0][0]=1;
		for(int x=0 ; x<n ; x++) {
			for(int y=0 ; y<n ; y++) {
				int nextX=x+data[x][y], nextY=y+data[x][y];
				if(nextX<n) DP[nextX][y]+=DP[x][y];
				if(nextY<n) DP[x][nextY]+=DP[x][y];
			}
		}

		if(DP[n-1][n-1]) puts("YES");
		else puts("NO");
	}
}
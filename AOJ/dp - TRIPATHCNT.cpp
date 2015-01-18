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
		// �� ��ȭ�� ��� �ڵ带 ¥�� (i, j)���� �ִ밪�� ������ DP���̺��� ��� ä�� �� �ִ�
		// ������ �� �������� ���ϴ� ���� �ܼ� �ִ밪�� �ƴ϶� ��θ� ã�� �����̴�
		for(int i=n-1 ; i>=0 ; i--)
			for(int j=0 ; j<=i ; j++)
				DP[i][j]=max(DP[i+1][j], DP[i+1][j+1])+data[i][j];

		// �̹� �ϼ��� DP���̺��� ������ �����ذ� ����� ������ ã�� ������ ���� �ϳ� ���� �� �� �ִ� ������
		// �켱 DP[i][j] �� ��� ������ �� ���ΰ��� ���ؼ� ���ذ� �־�� �Ѵ�
		// �ռ� ���ߵ��� DP[i][j] �� DP[i+1][j], DP[i+1][j+1] �� ���� ���⿡�� �� �� �ִ� ���ɼ��� �����Ѵ�
		// �׷��ٸ� DP[i][j] ���� data[i][j]�� �� ���� DP[i+1][j]�� DP[i+1][j+1]�̶� �񱳸� �� ����
		// ���� �Ȱ����� ���� �Ѵٸ� �����ش� ���� �Ȱ��� ���⿡�� ���� �� ���̴�.
		// �̸� �̿��� PATH[i][j]�� ��������. PATH[i][j]�� (i, j)���� �������� ������ ����� ���̴�.
		// �����ذ� ����� �� �ִ� ���� ����� ���� ���ؼ� �ö󰡸� �ᱹ (0, 0)���� �����ظ� ������ ����� ���� ã�� �� �ִ�
		// ������ʷ� ���� ���� ���� ��� 1�� �ʱ�ȭ ���� �ش�.
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
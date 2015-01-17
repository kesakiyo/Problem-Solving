#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF=987654321;
int n, d, MIN[2][3], MAX[2][3];

int main(void){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);

	// DP[x][y] => (x, y)���� �������� �� �������̶�� ����. �������� ������ ���� �ּҰ� �ɼ��� �ִ밡 �ɼ��� �ִ�
	// DP[x][y] = comp(DP[x][y], DP[x-1][prevY] + data[x][y])
	// ���⼭ prevY�� ���� (x, y)�� �� �� �ִ� (x-1, prevY) �϶��� ���̶� ����
	// ���� ���� y�� 1�̶�� prevY�� (0, 1, 2)�� �Ǵ� ���̰� y�� 0�̶�� (0, 1)�� �Ǵ� ���̴�.
	// �� ��ȭ�Ĵ�� Ǯ�� ���� ������ ���� �翩�Ѵ�. ������ �޸������� 4MB��� ���� �ָ��ؾ� �Ѵ�
	// ���� Sliding Window ����� �̿��� DP���̺��� ũ�⸦ �ٿ���� �Ѵ�
	// (x, y)�� ���ϱ� ���ؼ��� x-1�� �ุ �̿��ϴ°Ϳ� ������ �� DP���̺��� ũ�⸦ 2 * 3���� ���� �� �ִ�
	// ����� ���� ����ؼ� ���ϱ� ������ (x, y)�� ����� ����ؼ� �ʱ�ȭ ���ִ� �͵� �Ѱ��� ����̴�
	for(int x=1 ; x<=n ; x++){
		for(int y=0 ; y<3 ; y++){
			scanf("%d", &d);

			// ����� ���� �ʱ�ȭ ���ش�
			MIN[x%2][y]=INF;
			MAX[x%2][y]=0;

			// ���� �� �� �ִ� ��ġ�� ������ �ִ� �ݺ���
			for(int dy=-1 ; dy<=1 ; dy++){
				int prevX=x-1, prevY=y+dy;

				// ���� �� �� ���� ��ġ��� continue
				if(prevY==-1 || prevY==3) continue;
				MAX[x%2][y]=max(MAX[x%2][y], MAX[prevX%2][prevY]+d);
				MIN[x%2][y]=min(MIN[x%2][y], MIN[prevX%2][prevY]+d);
			}
		}
	}

	// �������� ��������� �����Դ����� ���� �������� �ٸ��� ������ ��� Ž��
	int mmin=INF, mmax=0;
	for(int i=0 ; i<3 ; i++){
		mmin=min(mmin, MIN[n%2][i]);
		mmax=max(mmax, MAX[n%2][i]);
	}
	
	printf("%d %d\n", mmax, mmin);
}
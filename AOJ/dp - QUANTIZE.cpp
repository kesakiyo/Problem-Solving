#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF=987654321;
int t, n, s, data[110], psum[110], DP[11][110], qunt[110][110];

// left���� right���� �ش� ������ ����ȭ �ϴ� �κ�
// ��հ� ���+1, �ΰ��� ���� ������ ���� ����� �� �� �ּҰ��� ��ȯ
int quntize(int left, int right) {
	int avg=(psum[right]-psum[left-1])/(right-left+1);

	int ret1=0, ret2=0;
	for(int i=left ; i<=right ; i++) {
		int diff1=data[i]-avg;
		ret1+=diff1*diff1;

		int diff2=data[i]-(avg+1);
		ret2+=diff2*diff2;
	}

	return min(ret1, ret2);
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		// DP���̺��� �ʱ�ȭ, �ּҰ��� ���ϴ� �����̹Ƿ� INF�� �ʱ�ȭ�� �����ش�
		for(int i=0 ; i<11 ; i++) for(int j=0 ; j<110 ; j++) DP[i][j]=INF;

		scanf("%d%d", &n, &s);
		for(int i=1 ; i<=n ; i++) scanf("%d", &data[i]);

		// ���� �ذ��� ù ��° ���̵��.
		// ����ȭ�� ������ �� ������ �� �ִ� ���� ���Ƿ� ���� �� �ִ�.
		// �׷��ٸ� ����� ���� �ʹ� ������ �����ϱ� �� ��ٷο�� �ƴϴ�
		// ������ ������ ���� �� ���ٸ� ����ȭ�� ������ �� �ּ��� ������ ������ �ִٴ� ���� �� �� �ִ�
		// ����ȭ�� ������ �� �ּ��� ������ �κм����� �ּڰ��� �ִ��� ���̰� �ּҰ� �ǰ� ������ �ϴ°��̴�.
		// �׷��ٸ� ������ ������ ������ �Ѵٸ� ����� ���� ���� �� �ִ�
		sort(data+1, data+1+n);

		// ��� ��쿡 ���� ����ȭ�� �����ϴ� �κ�
		// ����ȭ�� �� �� ������ �� �ִ� ����� ���� n combination 2 �̹Ƿ� O(n^2) ������ �ȴ�.
		// �� �� �κ��� �迭�� �̿��� ���ӵ� ������ ���� ������ ����� �� �ִ�
		// psum �� partial sum�� ����
		for(int i=1 ; i<=n ; i++) psum[i]=psum[i-1]+data[i];
		for(int i=1 ; i<=n ; i++) for(int j=i ; j<=n ; j++) qunt[i][j]=quntize(i, j);

		// DP[cnt][pos] => ����ȭ�� cnt�� �ؼ� pos��° ��ġ���� ���� �� �ִ밪
		// DP[cnt][pos] = min(DP[cnt-1][prev-1] + Quntize(prev, pos)) : ( 1 <= prev <= pos)
		// ���Ͱ��� ��ȭ���� ������ �� �� �ִ�
		DP[0][0]=0;
		for(int cnt=1 ; cnt<=s ; cnt++)
			for(int pos=1 ; pos<=n ; pos++)
				for(int prev=1 ; prev<=pos ; prev++)
					DP[cnt][pos] = min(DP[cnt][pos], DP[cnt-1][prev-1]+qunt[prev][pos]);

		// ���� ����� �� ������ ���� ����ȭ�� �� s�� �ؾߵȴٴ� ���� �ƴ϶�� ���̴�
		// ����ȭ�� �ּ� 1������ �ִ� s������ �����ϹǷ� ��� ���� ���� �ּڰ��� ������ش�
		int sol=INF;
		for(int i=1 ; i<=s ; i++) sol=min(sol, DP[i][n]);

		printf("%d\n", sol);
	}
}
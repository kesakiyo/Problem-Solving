#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;
int t;
const ll INF=987654321234;
ll n, m, k, DP[210][210];
char str[210];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	// ���װ���� �̸� ����� �д�
	// �����÷ΰ� �߻��� �� �����Ƿ� INF���� ������ ���� �� �������� ����Ѵ�
	for(int i=0 ; i<210 ; i++) DP[i][0]=DP[i][i]=1;
	for(int i=1 ; i<210 ; i++)
		for(int j=1 ; j<=i-1 ; j++)
			DP[i][j]=min(INF, DP[i-1][j]+DP[i-1][j-1]);

	scanf("%d", &t);
	while(t--) {
		scanf("%lld%lld%lld", &n, &m, &k);
		int pos=0;

		// k�� ° ���� ����ϴ� ����
		// �� �װ����� ����� ���� ������
		while(k && (n||m)) {

			// ù ��°, n�� ���̻� ����� �� ���� ��. �翬�� m�� ����ؾ� �Ѵ�
			if(n==0) str[pos]='o', m--;

			// �� ��°, m�� ���̻� ����� �� ���� ��. �翬�� n�� ����ؾ� �Ѵ�
			else if(m==0) str[pos]='-', n--;
			else {
				// �� ��°. n�� ����ߴµ� k��° ���ڿ��� �װͺ��� �۰ų� ���� �����϶�, n�� ����Ѵ�
				if(k<=DP[n-1+m][n-1]) {
					str[pos]='-';
					n--;
				}
				// ������ �� ��°. n�� ����ߴµ� k�� ° ���ڿ��� �װͺ��� ũ�ٸ� k��° ���ڿ��� n�� ����ϸ�
				// �ȵȴٴ� ���� ����������. ���� m�� ����� �ְ�, n�� ������� �� ������ �������� k���� ���ش�.
				else {
					k-=DP[n-1+m][n-1];
					str[pos]='o';
					m--;
				}
			}
			pos++;
		}
		str[pos]='\0';
		printf("%s\n", str);
	}
}
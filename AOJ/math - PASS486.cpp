#include <stdio.h>

const int MAX=10000001;
int t, lo, hi, n, divisor[MAX];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	// i�� ����� ������ ��� ��(j)�� ����� ������ �Ѱ��� ����
	// �̷��� ü(sieve) ����� �ǿܷ� ������ �۵��Ѵ�
	for(int i=1 ; i<MAX ; i++)
		for(int j=i ; j<MAX ; j+=i)
			divisor[j]++;

	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &lo, &hi);

		// lo���� hi���� ���� ���� ����� n�� ���� ���� � �ֳ� Ȯ��
		int sol=0;
		for(int i=lo ; i<=hi ; i++)
			if(divisor[i]==n) sol++;

		printf("%d\n", sol);
	}
}
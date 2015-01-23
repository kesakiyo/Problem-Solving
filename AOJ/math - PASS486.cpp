#include <stdio.h>

const int MAX=10000001;
int t, lo, hi, n, divisor[MAX];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	// i를 약수로 가지는 모든 수(j)에 약수의 개수를 한개씩 증가
	// 이러한 체(sieve) 방식은 의외로 빠르게 작동한다
	for(int i=1 ; i<MAX ; i++)
		for(int j=i ; j<MAX ; j+=i)
			divisor[j]++;

	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &lo, &hi);

		// lo부터 hi까지 직접 보며 약수가 n개 가진 수가 몇개 있나 확인
		int sol=0;
		for(int i=lo ; i<=hi ; i++)
			if(divisor[i]==n) sol++;

		printf("%d\n", sol);
	}
}
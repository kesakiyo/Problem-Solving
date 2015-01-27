#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD=201;
int t, n, m, cost[21], weight[21], DP[201];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		memset(DP, 0, sizeof(DP));
		scanf("%d%d", &n, &m);
		m/=100;

		for(int i=0 ; i<n ; i++) {
			scanf("%d%d", &cost[i], &weight[i]);
			cost[i]/=100;
		}

		// DP[money] => money원을 사용했을 때 가능한 최대 만족도
		// DP[money] = max(1, n) DP[money-cost[i]] + weight[i]
		// 위와같은 점화식을 세울 수 있다.
		// 하지만 money가 21억이나 되는 큰 수여서 DP테이블을 잡을수가 없다.
		// 문제를 눈여겨 본다면 초밥의 가격이 비싸봤자 20000원 이라는 것을 볼 수 있다
		// 그렇다는 말은 money-20000 미만으로는 디피테이블을 사용하지 않는다는 의미다
		// 모듈러 연산을 통해 슬라이딩 윈도우 기법을 구현할 수 있다
		// 한가지 더 새각을 해야 할 점은 초밥의 가격이 모두 100의 배수라는 것이다.
		// 즉 DP[20001] 에서 DP[201] 로 메모리를 줄일 수 있다.(이렇게 해야 TL이 안난다)
		for(int i=0 ; i<=m ; i++) {
			for(int j=0 ; j<n ; j++) {
				if(i-cost[j]<0) continue;
				DP[i%MOD]=max(DP[i%MOD], DP[(i-cost[j])%MOD]+weight[j]);
			}
		}
		printf("%d\n", DP[m%MOD]);
	}
}
#include <stdio.h>
#include <algorithm>
#include <string.h>

typedef long long ll;
const ll MOD=20091101;
int t, n, k;
ll data[100010], psum[100010], cnt[100010], HASH[100010], DP[100010];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		memset(HASH, 0, sizeof(HASH));
		memset(cnt, 0, sizeof(cnt));
		memset(DP, 0, sizeof(DP));
		scanf("%d%d", &n, &k);

		cnt[0]=1;
		for(int i=1 ; i<=n ; i++) {
			scanf("%lld", &data[i]);
			psum[i]=data[i]+psum[i-1];
			cnt[psum[i]%k]++;
		}

		// 첫 번째 문제를 해결할 수 알고리즘
		// H부터 T인 구간(H<=T)을 선택할 수 있는 경우의 수는를 생각해보자
		// 이 때 선택할 수 있는 경우는 (psum[H] - psum[T-1]) mod k = 0 이 되는 구간이다
		// 결국 psum[H] mod k = psum[T-1] mod k 가 되므로
		// psum[H] 와 psum[T-1] 이 합동이 되는 구간들을 찾아주면 된다
		// mod k 값이 나온 횟수를 cnt배열에 기록한 뒤 0부터 k까지 두번이상 나온 mod k 값에 대하여
		// combination 2 값을 취해주면 된다
		ll sol=0;
		for(int i=0 ; i<=k ; i++) {
			if(cnt[i]<2) continue;
			sol+=cnt[i]*(cnt[i]-1)/2;
			sol%=MOD;
		}

		// 두 번쨰 문제는 DP를 통해 해결할 수 있다
		// DP[pos] => pos번째까지 봤을 때 최대 구매 횟수
		// DP[pos] = max(DP[pos-1], DP[prev]+1)
		// prev 는 pos와 mod k로 합동인 psum의 인덱스 중 가장 마지막에 나온 수
		// 우선 pos에서 선택할 수 있는 경우의 수는 두가지이다
		// 첫 번째는 pos번째를 마지막으로 선택하지 않는 경우. 이때 당연히 DP[pos] = DP[pos-1] 이 된다.
		// 두 번째는 pos번째를 선택할 경우이다. pos번째를 선택할 수 있는 경우는 psum[pos] mod k 값이 두번이상 나왔을 경우이다.
		// 이는 두번이상 같은 mod k 값이 나와야지 선택할 수 있는 경우의 수가 존재하므로...
		// psum 배열에는 psum[pos] 와 mod k 로 합동인 값이 많이 존재할텐데 이 중 선택할 인덱스는 가장 큰 값이다.
		// 이 prev가 가지는 값을 HASH 배열에 따로 저장 및 갱신을 해 줘 손쉽게 접근을 할 수 있게 한다
		memset(cnt, 0, sizeof(cnt));
		cnt[0]=1;
		for(int i=1 ; i<=n ; i++) {
			DP[i]=DP[i-1];
			ll val=psum[i]%k;
			if(++cnt[val]>=2) DP[i]=std::max(DP[i], HASH[val]+1);
			HASH[val]=DP[i];
		}

		printf("%lld %lld\n", sol, DP[n]);
	}
}
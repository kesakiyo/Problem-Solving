#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD1=1000000007, MOD2=1000000009;
ll t, a, b;

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%lld", &t);
	while(t--) {
		set< pair<ll, ll> > HASH;
		scanf("%lld%lld", &a, &b);

		// 한번의 Hashing으로는 충돌이 생길확률이 매우 높으므로
		// Double Hashing을 통해 충돌을 방지한다, 이때 Hashing은
		// Mod 연산을 통해 진행이 되는데 두개의 Mod 값은 10억 7, 10억 9로
		// 잡는다. 이 두 수는 소수이다.
		// 가능한 모든경우를 구하면서 해쉬값을 구해 set안에 저장을 한다
		for(ll i=1 ; i<=a ; i++) {
			ll mul1=1, mul2=1;
			for(ll j=1 ; j<=b ; j++) {
				mul1*=i; mul2*=i;
				mul1%=MOD1; mul2%=MOD2;
				HASH.insert(make_pair(mul1, mul2));
			}
		}

		printf("%d\n", HASH.size());
	}
}
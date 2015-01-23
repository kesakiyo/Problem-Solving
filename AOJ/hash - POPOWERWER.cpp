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

		// �ѹ��� Hashing���δ� �浹�� ����Ȯ���� �ſ� �����Ƿ�
		// Double Hashing�� ���� �浹�� �����Ѵ�, �̶� Hashing��
		// Mod ������ ���� ������ �Ǵµ� �ΰ��� Mod ���� 10�� 7, 10�� 9��
		// ��´�. �� �� ���� �Ҽ��̴�.
		// ������ ����츦 ���ϸ鼭 �ؽ����� ���� set�ȿ� ������ �Ѵ�
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
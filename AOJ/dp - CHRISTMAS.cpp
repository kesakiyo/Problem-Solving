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

		// ù ��° ������ �ذ��� �� �˰���
		// H���� T�� ����(H<=T)�� ������ �� �ִ� ����� ���¸� �����غ���
		// �� �� ������ �� �ִ� ���� (psum[H] - psum[T-1]) mod k = 0 �� �Ǵ� �����̴�
		// �ᱹ psum[H] mod k = psum[T-1] mod k �� �ǹǷ�
		// psum[H] �� psum[T-1] �� �յ��� �Ǵ� �������� ã���ָ� �ȴ�
		// mod k ���� ���� Ƚ���� cnt�迭�� ����� �� 0���� k���� �ι��̻� ���� mod k ���� ���Ͽ�
		// combination 2 ���� �����ָ� �ȴ�
		ll sol=0;
		for(int i=0 ; i<=k ; i++) {
			if(cnt[i]<2) continue;
			sol+=cnt[i]*(cnt[i]-1)/2;
			sol%=MOD;
		}

		// �� ���� ������ DP�� ���� �ذ��� �� �ִ�
		// DP[pos] => pos��°���� ���� �� �ִ� ���� Ƚ��
		// DP[pos] = max(DP[pos-1], DP[prev]+1)
		// prev �� pos�� mod k�� �յ��� psum�� �ε��� �� ���� �������� ���� ��
		// �켱 pos���� ������ �� �ִ� ����� ���� �ΰ����̴�
		// ù ��°�� pos��°�� ���������� �������� �ʴ� ���. �̶� �翬�� DP[pos] = DP[pos-1] �� �ȴ�.
		// �� ��°�� pos��°�� ������ ����̴�. pos��°�� ������ �� �ִ� ���� psum[pos] mod k ���� �ι��̻� ������ ����̴�.
		// �̴� �ι��̻� ���� mod k ���� ���;��� ������ �� �ִ� ����� ���� �����ϹǷ�...
		// psum �迭���� psum[pos] �� mod k �� �յ��� ���� ���� �������ٵ� �� �� ������ �ε����� ���� ū ���̴�.
		// �� prev�� ������ ���� HASH �迭�� ���� ���� �� ������ �� �� �ս��� ������ �� �� �ְ� �Ѵ�
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
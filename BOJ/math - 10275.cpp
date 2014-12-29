#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;

int t;
ll n, a, b;

ll power(ll base, ll n)
{
	if(n==0) return 1;
	return base*power(base, n-1);
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld%lld", &n, &a, &b);

		int sol=0;
		priority_queue<ll> pq;
		pq.push(power(2, n));

		// 문제의 속성을 파악하면 a와 b는 1보다 크고 a+b=2^n 이므로
		// 무조건 한번은 나누고 시작해야 되는것을 알 수 있다
		while(a+b)
		{
			// 여기서 또 한번 생각을 하면 나누는 것의 가장 최선은 가장 큰것부터 반토막 내는 것이다
			// 그리디하게 생각을 하면 큰게 안들어가는데 더 작은것을 나눠서 가방에 넣는다고 이득이 될까?
			ll top=pq.top(); pq.pop();
			pq.push(top/2); pq.push(top/2);

			// a는 항상 큰 수가 올 수 있도록 한다
			if(a<b) swap(a, b);

			// 가장 큰 것을 a에 넣고 그 다음 큰 것을 b에 넣도록 한다
			if(pq.top()<=a) a-=pq.top(), pq.pop();
			if(pq.top()<=b) b-=pq.top(), pq.pop();

			// 자르는 회수를 카운트 해준다
			sol++;
		}

		printf("%d\n", sol);
	}
}
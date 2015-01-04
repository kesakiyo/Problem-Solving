#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector< pair<ll, ll> > data;

int solution()
{
	// 겹치는 선분들의 끝 점을 카운팅 해주기 위한 우선순위 큐
	priority_queue<ll> endPoint;

	int ret=0;

	// 만약 현재 선분이 앞의 선분들과 겹친다면 
	// 그 집합들 중 가장 작은 끝 점보다 현재 선분의 끝 점이 작을 것이다
	// 이 점을 이용해 우선순위 큐로 겹치는 선분들의 끝 점을 관리 해 준다면 쉽게 해결할 수 있다
	for(int i=0 ; i<n ; i++)
	{
		// endPoint가 비어있지 않고, 현재 선분이 endPoint집합중 가장 작은것보다 크거나 같을 때
		// endPoint를 pop해준다, 그렇다면 겹치는 선분들의 집합의 수를 구할 수 있다
		while(!endPoint.empty() && data[i].first>=-endPoint.top()) endPoint.pop();

		// 현재 선분의 끝 점을 pq에 push한다, max pq이기 때문에 음수로 넣어준다
		endPoint.push(-data[i].second);

		// 현재 겹쳐져 있는 선분의 집합과 return value와 비교해 큰 값을 넣어준다
		ret=max(ret, (int)endPoint.size());
	}
	return ret;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	data.resize(n);
	for(int i=0 ; i<n ; i++) 
	{
		scanf("%lld%lld", &data[i].first, &data[i].second);
		if(data[i].first>data[i].second) swap(data[i].first, data[i].second);
	}

	// 선분을 앞에서부터 차례대로 카운트 하기 위해서 정렬을 해 준다
	sort(data.begin(), data.end());

	int sol=solution();
	printf("%d\n", sol);
}
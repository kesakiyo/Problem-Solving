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
	// ��ġ�� ���е��� �� ���� ī���� ���ֱ� ���� �켱���� ť
	priority_queue<ll> endPoint;

	int ret=0;

	// ���� ���� ������ ���� ���е�� ��ģ�ٸ� 
	// �� ���յ� �� ���� ���� �� ������ ���� ������ �� ���� ���� ���̴�
	// �� ���� �̿��� �켱���� ť�� ��ġ�� ���е��� �� ���� ���� �� �شٸ� ���� �ذ��� �� �ִ�
	for(int i=0 ; i<n ; i++)
	{
		// endPoint�� ������� �ʰ�, ���� ������ endPoint������ ���� �����ͺ��� ũ�ų� ���� ��
		// endPoint�� pop���ش�, �׷��ٸ� ��ġ�� ���е��� ������ ���� ���� �� �ִ�
		while(!endPoint.empty() && data[i].first>=-endPoint.top()) endPoint.pop();

		// ���� ������ �� ���� pq�� push�Ѵ�, max pq�̱� ������ ������ �־��ش�
		endPoint.push(-data[i].second);

		// ���� ������ �ִ� ������ ���հ� return value�� ���� ū ���� �־��ش�
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

	// ������ �տ������� ���ʴ�� ī��Ʈ �ϱ� ���ؼ� ������ �� �ش�
	sort(data.begin(), data.end());

	int sol=solution();
	printf("%d\n", sol);
}
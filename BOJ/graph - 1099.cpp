#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int INF=987654321;
int n;
string str, data[51];
vector< vector< pair<int, int> > > node;

// 다익스트라
int solution(int s, int e)
{
	vector<int> cache(str.size()+1, INF);
	priority_queue< pair<int, int> > pq;
	cache[s]=0;
	pq.push(make_pair(0, s));

	while(pq.size())
	{
		int here=pq.top().second, cost=-pq.top().first;
		pq.pop();

		if(cache[here]<cost) continue;

		for(int i=0 ; i<node[here].size() ; i++)
		{
			int there=node[here][i].first, nextCost=cost+node[here][i].second;

			if(cache[there]>nextCost)
			{
				cache[there]=nextCost;
				pq.push(make_pair(-nextCost, there));
			}
		}
	}

	return cache[e];
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin>>str>>n;
	for(int i=0 ; i<n ; i++) cin>>data[i];
	node.resize(str.size()+1, vector< pair<int, int> >());

	// 일단 문제를 해결 할 수 있는 방법이 여러가지가 있지만 가장 먼저 떠오른 방법은
	// 가중치 그래프를 만들어 최단거리를 구하는 방법이다.
	// 일단 원본 문자열의 각 인덱스를 vertex라고 생각을 한뒤 n개의 단어들과 비교를 해
	// 해당 위치에서 다른 단어의 순서를 바꿔 만들 수 있다면 edge를 연결 해 준다
	for(int i=0 ; i<str.size() ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(i+data[j].size()>str.size()) continue;

			int len=data[j].size(), diff=0;
			string origin=str.substr(i, len);
			string comp=data[j];

			// 위치의 차이를 미리 계산해 둔다
			for(int k=0 ; k<len ; k++)
				if(origin[k]!=comp[k]) diff++;

			// 순서를 바꾸는 것으로 orgin문자열을 만들 수 있는지 쉽게 알기위해 정렬을 한다
			sort(origin.begin(), origin.end());
			sort(comp.begin(), comp.end());

			// 만약 두 문자열이 같다면? 만들 수 있다는 뜻이므로 해당 위치에서 comp문자열 길이만큼
			// 더한 곳으로 갈 수 있고, 가중치는 미리 계산해 둔 diff로 설정을 해 준다
			if(origin==comp) node[i].push_back(make_pair(i+len, diff));
		}
	}

	// 다익스트라를 이용해 최단거리를 계산한다
	int sol=solution(0, str.size());
	if(sol==INF) cout<<-1<<endl;
	else cout<<sol<<endl;
}
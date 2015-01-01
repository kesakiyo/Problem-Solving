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

// ���ͽ�Ʈ��
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

	// �ϴ� ������ �ذ� �� �� �ִ� ����� ���������� ������ ���� ���� ������ �����
	// ����ġ �׷����� ����� �ִܰŸ��� ���ϴ� ����̴�.
	// �ϴ� ���� ���ڿ��� �� �ε����� vertex��� ������ �ѵ� n���� �ܾ��� �񱳸� ��
	// �ش� ��ġ���� �ٸ� �ܾ��� ������ �ٲ� ���� �� �ִٸ� edge�� ���� �� �ش�
	for(int i=0 ; i<str.size() ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(i+data[j].size()>str.size()) continue;

			int len=data[j].size(), diff=0;
			string origin=str.substr(i, len);
			string comp=data[j];

			// ��ġ�� ���̸� �̸� ����� �д�
			for(int k=0 ; k<len ; k++)
				if(origin[k]!=comp[k]) diff++;

			// ������ �ٲٴ� ������ orgin���ڿ��� ���� �� �ִ��� ���� �˱����� ������ �Ѵ�
			sort(origin.begin(), origin.end());
			sort(comp.begin(), comp.end());

			// ���� �� ���ڿ��� ���ٸ�? ���� �� �ִٴ� ���̹Ƿ� �ش� ��ġ���� comp���ڿ� ���̸�ŭ
			// ���� ������ �� �� �ְ�, ����ġ�� �̸� ����� �� diff�� ������ �� �ش�
			if(origin==comp) node[i].push_back(make_pair(i+len, diff));
		}
	}

	// ���ͽ�Ʈ�� �̿��� �ִܰŸ��� ����Ѵ�
	int sol=solution(0, str.size());
	if(sol==INF) cout<<-1<<endl;
	else cout<<sol<<endl;
}
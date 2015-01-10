#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ������ ǥ���ϰ� �� �� VECTOR ����ü
struct VECTOR
{
	double x, y;
	explicit VECTOR(double _x=0, double _y=0) : x(_x), y(_y) {}
	bool operator == (const VECTOR& rhs) const {
		return x==rhs.x && y==rhs.y;
	}
	bool operator < (const VECTOR& rhs) const {
		return x!=rhs.x ? x<rhs.x : y<rhs.y;
	}
	VECTOR operator - (const VECTOR& rhs) const {
		return VECTOR(x-rhs.x, y-rhs.y);
	}
	double cross(const VECTOR rhs) const {
		return x*rhs.y - y*rhs.x;
	}
};

// ���� ����ü, �������� �� ���� ������ �ְ� ������ ���� ���ͷ� �̷����
struct SEGMENT
{
	VECTOR start, end;
	SEGMENT(VECTOR s, VECTOR e) : start(s), end(e) {}
};

// ������ �̿��� �� ������ ���⼺�� �ݴ��ϰ� ���ش�
double ccw(VECTOR a, VECTOR b)
{
	return a.cross(b);
}

// ������ �̿��� �� ������ ���⼺�� �ݴ��ϰ� ���ش�
double ccw(VECTOR p, VECTOR a, VECTOR b)
{
	return ccw(a-p, b-p);
}

// �ΰ��� ������ ��ġ���� �Ȱ�ġ���� ��ȯ�ϴ� �Լ�
// ccw�Լ��� �̿��� ���� ���� �� �ִ�
bool segmentIntersects(SEGMENT x, SEGMENT y)
{
	VECTOR a=x.start, b=x.end, c=y.start, d=y.end;

	double ab=ccw(a, b, c)*ccw(a, b, d);
	double cd=ccw(c, d, a)*ccw(c, d, b);

	if(ab==0 && cd==0) 
	{
		if(b<a) swap(a, b);
		if(d<c) swap(c, d);
		return !(b<c || d<a);
	}
	return ab<=0 && cd<=0;
}

// ��ġ�� ���е��� ������ ������ �ִ� �Լ�, O(n^2)������ n�� �۱⶧���� ����
void makeGraph(const vector<SEGMENT>& data, vector< vector<int> >& node)
{
	int n=data.size();

	for(int i=0 ; i<n ; i++)
		for(int j=i+1 ; j<n ; j++)
			if(segmentIntersects(data[i], data[j])) 
				node[i].push_back(j), node[j].push_back(i);
}

// dfs�� ���� ����Ǿ� �ִ� ������ ���� ��ȯ�Ѵ�
int dfs(int here, vector<bool>& discovery, const vector< vector<int> >& node)
{
	discovery[here]=true;

	int ret=1;
	for(int i=0 ; i<node[here].size() ; i++)
	{
		int there=node[here][i];
		if(discovery[there]) continue;

		ret+=dfs(there, discovery, node);
	}

	return ret;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);

	vector<SEGMENT> seg;
	vector< vector<int> > node(n, vector<int>());
	vector<bool> discovery(n, false);

	// �����͸� �Է¹޾� ���м��� �����Ѵ�
	for(int i=0 ; i<n ; i++)
	{
		double a, b, c, d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		seg.push_back(SEGMENT(VECTOR(a, b), VECTOR(c, d)));
	}

	// �׷��� ����
	makeGraph(seg, node);

	int group=0, maxElement=0;
	for(int i=0 ; i<n ; i++)
	{
		if(discovery[i]) continue;

		// ���� i��° ������ discovery���� �ʾҴٸ� ���б׷��� �����Ѵ� ���̹Ƿ�
		// group�� 1 �����Ѵ�
		group++;

		// dfs������� maxElement �ΰ��� ���� �ִ밪�� ������ �� �ֵ��� �Ѵ�
		int elem=dfs(i, discovery, node);
		maxElement=max(maxElement, elem);
	}

	printf("%d\n%d\n", group, maxElement);
}
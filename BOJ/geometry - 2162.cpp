#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 선분을 표현하게 해 줄 VECTOR 구조체
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

// 선분 구조체, 시작점과 끝 점을 가지고 있고 각각의 점은 벡터로 이루어짐
struct SEGMENT
{
	VECTOR start, end;
	SEGMENT(VECTOR s, VECTOR e) : start(s), end(e) {}
};

// 외적을 이용해 두 벡터의 방향성을 반단하게 해준다
double ccw(VECTOR a, VECTOR b)
{
	return a.cross(b);
}

// 외적을 이용해 두 벡터의 방향성을 반단하게 해준다
double ccw(VECTOR p, VECTOR a, VECTOR b)
{
	return ccw(a-p, b-p);
}

// 두개의 선분이 겹치는지 안겹치는지 반환하는 함수
// ccw함수를 이용해 쉽게 구할 수 있다
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

// 겹치는 선분들을 엣지로 연결해 주는 함수, O(n^2)이지만 n이 작기때문에 가능
void makeGraph(const vector<SEGMENT>& data, vector< vector<int> >& node)
{
	int n=data.size();

	for(int i=0 ; i<n ; i++)
		for(int j=i+1 ; j<n ; j++)
			if(segmentIntersects(data[i], data[j])) 
				node[i].push_back(j), node[j].push_back(i);
}

// dfs를 돌며 연결되어 있는 노드들의 수를 반환한다
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

	// 데이터를 입력받아 선분셋을 유지한다
	for(int i=0 ; i<n ; i++)
	{
		double a, b, c, d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		seg.push_back(SEGMENT(VECTOR(a, b), VECTOR(c, d)));
	}

	// 그래프 생성
	makeGraph(seg, node);

	int group=0, maxElement=0;
	for(int i=0 ; i<n ; i++)
	{
		if(discovery[i]) continue;

		// 만약 i번째 선분이 discovery되지 않았다면 선분그룹이 존재한단 뜻이므로
		// group을 1 증가한다
		group++;

		// dfs결과괎과 maxElement 두개를 비교해 최대값을 유지할 수 있도록 한다
		int elem=dfs(i, discovery, node);
		maxElement=max(maxElement, elem);
	}

	printf("%d\n%d\n", group, maxElement);
}
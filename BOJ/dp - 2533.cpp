#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
 
using namespace std;
 
int n, u, v, cache[2][1000010];
bool visited[1000010];
vector< vector<int> > data, node;
 
// ����� �׷����� �ܹ��� �׷����� �ٲٱ� ���� dfs�Լ�
void dfs(int here)
{
    visited[here]=true;
    for(int i=0 ; i<data[here].size() ; i++)
    {
        int there=data[here][i];
        if(visited[there]) continue;
 
        node[here].push_back(there);
        dfs(there);
    }
}
 
// ������ �Ӽ��� ���� �󸮾���Ͱ� �ƴ� ����� �ҽ��� �������� ģ������ ��� �󸮾���Ϳ��� �Ѵ�
// ���� ��Ʈ��(�󸮾���Ͷ��) �ڽ��� ��Ʈ�� ���ɼ��� �ְ�, �ƴ� ���ɼ��� �ִ�
// ������ ���� ��Ʈ�� �ƴ϶��(�󸮾���Ͷ��) �ڽ��� �и� ��Ʈ���� �Ѵ�
// �� ����� ������� ž�ٿ� ����� ��� DP�� �����ϸ� �ȴ�
int solution(int here, bool isRoot)
{
    int& ret=cache[isRoot][here];
    if(ret!=-1) return ret;
    else if(node[here].empty()) return cache[isRoot][here] = isRoot ? 1 : 0;
 
    ret=0;

	// ���� �󸮾���͸� �ڽĵ��� �󸮾���� �ϼ���, �󸮾���Ͱ� �ƴҼ��� �ִ�
    if(isRoot)
    {
        for(int i=0 ; i<node[here].size() ; i++)
        {
            int there=node[here][i];
            ret+=min(solution(there, true), solution(there, false));
        }
        return ret+=1;
    }
	// ���� �󸮾���Ͱ� �ƴ϶�� �ڽ��� ������ �󸮾���Ϳ��� �Ѵ�.
    else
    {
        for(int i=0 ; i<node[here].size() ; i++)
        {
            int there=node[here][i];
            ret+=solution(there, true);
        }
        return ret;
    }
}
 
int main(void)
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    data.resize(n+1, vector<int>());
    node.resize(n+1, vector<int>());
    memset(cache, -1, sizeof(cache));
 
    for(int i=0 ; i<n-1 ; i++)
    {
        scanf("%d%d", &u, &v);
        data[u].push_back(v);
        data[v].push_back(u);
    }
    dfs(1);
 
    int sol=min(solution(1, true), solution(1, false));
    printf("%d\n", sol);
}
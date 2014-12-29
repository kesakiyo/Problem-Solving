#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
 
using namespace std;
 
int n, u, v, cache[2][1000010];
bool visited[1000010];
vector< vector<int> > data, node;
 
// 양방향 그래프를 단방향 그래프로 바꾸기 위한 dfs함수
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
 
// 문제의 속성을 보면 얼리어답터가 아닌 사람이 소식을 받으려면 친구들이 모두 얼리어답터여야 한다
// 내가 루트면(얼리어답터라면) 자식은 루트일 가능성도 있고, 아닐 가능성도 있다
// 하지만 내가 루트가 아니라면(얼리어답터라면) 자식은 분명 루트여야 한다
// 위 사실을 기반으로 탑다운 방식의 재귀 DP를 설계하면 된다
int solution(int here, bool isRoot)
{
    int& ret=cache[isRoot][here];
    if(ret!=-1) return ret;
    else if(node[here].empty()) return cache[isRoot][here] = isRoot ? 1 : 0;
 
    ret=0;

	// 내가 얼리어답터면 자식들은 얼리어답터 일수도, 얼리어답터가 아닐수도 있다
    if(isRoot)
    {
        for(int i=0 ; i<node[here].size() ; i++)
        {
            int there=node[here][i];
            ret+=min(solution(there, true), solution(there, false));
        }
        return ret+=1;
    }
	// 내가 얼리어답터가 아니라면 자식은 무조건 얼리어답터여야 한다.
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
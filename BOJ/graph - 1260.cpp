#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int n, m, v, a, b;
bool adj[1010][1010], discovery[1010];

// dfs를 실행하는 함수
void dfs(int here) {
	// 현재 방문한 정점을 출력하고 방문했다는 표시를 해 준다
	printf("%d ", here);
	discovery[here]=true;

	// 현재 정점과 연결된 정점을 찾는다
	// 만약 연결이 되어있고 방문을 하지 않았다면 재귀로 dfs를 호출한다
	for(int there=1 ; there<=n ; there++)
		if(adj[here][there] && !discovery[there])
			dfs(there);
}

// bfs를 실행하는 함수
void bfs(int s) {
	// dfs함수를 실행하면서 discovery배열이 채워졌으므로 false로 초기화 시켜준다
	memset(discovery, false, sizeof(discovery));
	queue<int> q;

	// 시작점을 큐에 넣어주고 방문했다는 표시를 해 준다
	q.push(s);
	discovery[s]=true;

	// 큐가 빌때까지 계속해서 bfs를 돌린다
	while(q.size()) {
		// 현재 정점을 출력하면서 큐를 pop한다
		int here=q.front();
		printf("%d ", here);
		q.pop();

		// 현재 정점과 연결된 정점을 찾는다
		// 만약 연결이 되어 있고 방문을 하지 않았다면 큐에 넣어준다
		// 큐에 넣는 순간 방문이 되는것이므로 discovery배열에 방문했다고 체크를 해 준다
		for(int there=1 ; there<=n ; there++) {
			if(adj[here][there] && !discovery[there]) {
				q.push(there);
				discovery[there]=true;
			}
		}
	}
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d%d", &n, &m, &v);
	while(m--) {
		scanf("%d%d", &a, &b);
		
		// 그래프가 양방향이므로 둘 다 연결이 되어 있다고 체크를 해 준다.
		adj[a][b]=adj[b][a]=true;
	}

	dfs(v); puts("");
	bfs(v); puts("");
}
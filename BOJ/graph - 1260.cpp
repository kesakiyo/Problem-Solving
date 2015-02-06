#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int n, m, v, a, b;
bool adj[1010][1010], discovery[1010];

// dfs�� �����ϴ� �Լ�
void dfs(int here) {
	// ���� �湮�� ������ ����ϰ� �湮�ߴٴ� ǥ�ø� �� �ش�
	printf("%d ", here);
	discovery[here]=true;

	// ���� ������ ����� ������ ã�´�
	// ���� ������ �Ǿ��ְ� �湮�� ���� �ʾҴٸ� ��ͷ� dfs�� ȣ���Ѵ�
	for(int there=1 ; there<=n ; there++)
		if(adj[here][there] && !discovery[there])
			dfs(there);
}

// bfs�� �����ϴ� �Լ�
void bfs(int s) {
	// dfs�Լ��� �����ϸ鼭 discovery�迭�� ä�������Ƿ� false�� �ʱ�ȭ �����ش�
	memset(discovery, false, sizeof(discovery));
	queue<int> q;

	// �������� ť�� �־��ְ� �湮�ߴٴ� ǥ�ø� �� �ش�
	q.push(s);
	discovery[s]=true;

	// ť�� �������� ����ؼ� bfs�� ������
	while(q.size()) {
		// ���� ������ ����ϸ鼭 ť�� pop�Ѵ�
		int here=q.front();
		printf("%d ", here);
		q.pop();

		// ���� ������ ����� ������ ã�´�
		// ���� ������ �Ǿ� �ְ� �湮�� ���� �ʾҴٸ� ť�� �־��ش�
		// ť�� �ִ� ���� �湮�� �Ǵ°��̹Ƿ� discovery�迭�� �湮�ߴٰ� üũ�� �� �ش�
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
		
		// �׷����� ������̹Ƿ� �� �� ������ �Ǿ� �ִٰ� üũ�� �� �ش�.
		adj[a][b]=adj[b][a]=true;
	}

	dfs(v); puts("");
	bfs(v); puts("");
}
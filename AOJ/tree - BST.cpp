#include <stdio.h>
#include <string.h>
#define L	0
#define R	1
#define K	2

int t, n, node[110][3], arr[110];
bool isRoot[110];

void inorder(int pos, int& cnt) {
	if(!pos) return;
	inorder(node[pos][L], cnt);
	arr[cnt++]=node[pos][K];
	inorder(node[pos][R], cnt);
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		// 모든 노드들은 root의 가능성이 있다
		memset(isRoot, true, sizeof(isRoot));
		scanf("%d", &n);
		for(int i=1 ; i<=n ; i++) {
			// 왼쪽, 오른쪽 자식의 인덱스, 그리고 현재 위치의 key 값을 입력
			scanf("%d%d%d", &node[i][L], &node[i][R], &node[i][K]);
			
			// 왼쪽, 오른쪽 자식들은 root가 될 수 없으므로 false라고 체크
			isRoot[node[i][L]]=isRoot[node[i][R]]=false;
		}

		// root를 찾는다
		int root=-1;
		for(int i=1 ; i<=n ; i++)
			if(isRoot[i]) root=i;

		// inorder 순회를 실행, BST에서 inorder를 하면
		// key값이 오름차순 정렬이 되어야 한다
		int cnt=0;
		inorder(root, cnt);

		// inorder결과가 올바른지 확인을 한다
		bool flag=true;
		for(int i=0 ; i<n-1 ; i++)
			if(arr[i]>=arr[i+1]) flag=false;

		// 올바른 BST라면 YES를, 아니라면 NO를 출력한다
		if(!flag) puts("NO");
		else puts("YES");
	}
}
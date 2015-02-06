#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[]={-1, 1,  0, 0};
const int dy[]={ 0, 0, -1, 1};
int row, col, data[1010][1010];

// 좌표의 유효성을 검사하는 부분
// 추가적으로 익을 수 있는 토마토인가도 검사를 해 준다
bool isPossible(int x, int y) {
	if(x==-1 || x==row || y==-1 || y==col || data[x][y]!=0) return false;
	return true;
}

// 모든 토마토가 익었는지 확인을 해 주는 부분
// 만약 0이 있다면 익지 않았다는 얘기므로 false를 반환한다
bool isAllRipe() {
	for(int i=0 ; i<row ; i++)
		for(int j=0 ; j<col ; j++)
			if(data[i][j]==0) return false;
	return true;
}

int bfs() {
	int ret=0;
	queue< pair<int, int> > q;

	// 초기 큐에 들어갈 값을 설정해 준다
	// 익은 토마토로 부터 bfs를 돌려야 하므로 익은 토마토(값이 1)을 큐에 넣는다
	for(int i=0 ; i<row ; i++)
		for(int j=0 ; j<col ; j++)
			if(data[i][j]==1) q.push(make_pair(i, j));

	// 큐 사이즈가 빌때까지 bfs를 실행한다
	while(q.size()) {
		// 큐의 레벨을 나눠줘야 하므로 초기 큐 값을 받아 와 그 값만큼 반복한다
		// 반복한 횟수가 한 레벨의 큐의 크기라고 할 수 있다
		int repeat=q.size();

		// 레벨의 수(최단 거리)를 체크해 줘야 하므로 ret값을 1 증가시켜 준다
		ret++;

		// 큐 레벨의 크기만큼 반복
		while(repeat--) {
			int x=q.front().first, y=q.front().second;
			q.pop();

			// 현재 위치에서 갈 수 있는 위치를 계산하고 갈 수 있다면
			// 큐에 넣어준다. 그 뒤 익었다는 표시를 해 준다
			// 이런식으로 한다면 discovery 배열이 필요없게 된다
			for(int i=0 ; i<4 ; i++) {
				int nextX=x+dx[i], nextY=y+dy[i];
				if(!isPossible(nextX, nextY)) continue;
				q.push(make_pair(nextX, nextY));
				data[nextX][nextY]=1;
			}
		}
	}

	return ret;
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &col, &row);

	// 데이터를 입력받는 부분
	// 행과 열을 주의해서 입력 받는다
	for(int i=0 ; i<row ; i++)
		for(int j=0 ; j<col ; j++)
			scanf("%d", &data[i][j]);

	int sol=bfs();
	if(isAllRipe()) printf("%d\n", sol-1);
	else puts("-1");
}
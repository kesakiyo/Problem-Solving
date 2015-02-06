#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[]={-1, 1,  0, 0};
const int dy[]={ 0, 0, -1, 1};
int row, col, data[1010][1010];

// ��ǥ�� ��ȿ���� �˻��ϴ� �κ�
// �߰������� ���� �� �ִ� �丶���ΰ��� �˻縦 �� �ش�
bool isPossible(int x, int y) {
	if(x==-1 || x==row || y==-1 || y==col || data[x][y]!=0) return false;
	return true;
}

// ��� �丶�䰡 �;����� Ȯ���� �� �ִ� �κ�
// ���� 0�� �ִٸ� ���� �ʾҴٴ� ���Ƿ� false�� ��ȯ�Ѵ�
bool isAllRipe() {
	for(int i=0 ; i<row ; i++)
		for(int j=0 ; j<col ; j++)
			if(data[i][j]==0) return false;
	return true;
}

int bfs() {
	int ret=0;
	queue< pair<int, int> > q;

	// �ʱ� ť�� �� ���� ������ �ش�
	// ���� �丶��� ���� bfs�� ������ �ϹǷ� ���� �丶��(���� 1)�� ť�� �ִ´�
	for(int i=0 ; i<row ; i++)
		for(int j=0 ; j<col ; j++)
			if(data[i][j]==1) q.push(make_pair(i, j));

	// ť ����� �������� bfs�� �����Ѵ�
	while(q.size()) {
		// ť�� ������ ������� �ϹǷ� �ʱ� ť ���� �޾� �� �� ����ŭ �ݺ��Ѵ�
		// �ݺ��� Ƚ���� �� ������ ť�� ũ���� �� �� �ִ�
		int repeat=q.size();

		// ������ ��(�ִ� �Ÿ�)�� üũ�� ��� �ϹǷ� ret���� 1 �������� �ش�
		ret++;

		// ť ������ ũ�⸸ŭ �ݺ�
		while(repeat--) {
			int x=q.front().first, y=q.front().second;
			q.pop();

			// ���� ��ġ���� �� �� �ִ� ��ġ�� ����ϰ� �� �� �ִٸ�
			// ť�� �־��ش�. �� �� �;��ٴ� ǥ�ø� �� �ش�
			// �̷������� �Ѵٸ� discovery �迭�� �ʿ���� �ȴ�
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

	// �����͸� �Է¹޴� �κ�
	// ��� ���� �����ؼ� �Է� �޴´�
	for(int i=0 ; i<row ; i++)
		for(int j=0 ; j<col ; j++)
			scanf("%d", &data[i][j]);

	int sol=bfs();
	if(isAllRipe()) printf("%d\n", sol-1);
	else puts("-1");
}
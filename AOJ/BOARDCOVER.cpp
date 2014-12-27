#include <cstdio>

// 보드의 네가지 형태를 나타내는 방향배열
const int dx[4][2]={{0, 1}, {0, 1}, {1, 1}, {1,  1}};
const int dy[4][2]={{1, 0}, {1, 1}, {0, 1}, {0, -1}};
int t, row, col;
char data[21][21];

// 좌표의 유효성을 체크해주는 함수
bool isPossible(int x, int y)
{
	if(x==-1 || y==-1 || x==row || y==col || data[x][y]=='#') return false;
	return true;
}

int solution()
{
	// 현재 보드에서 첫번째로 빈칸이 어디서 등장하는지 찾는다
	int nextX=-1, nextY=-1;
	for(int i=0 ; i<row ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			if(data[i][j]=='.')
			{
				nextX=i; nextY=j;
				break;
			}
		}
		if(nextX!=-1) break;
	}

	// 만약 빈칸이 없다면 다 채워졌다는 뜻이므로 1을 반환한다
	if(nextX==-1 && nextY==-1) return 1;

	// 현재 빈칸을 기준으로 네가지 블록을 맞춰본다
	// 순서 강제를 위해 같은 행 왼쪽과 작은 행은 보지 않는다
	int ret=0;
	for(int i=0 ; i<4 ; i++)
	{
		// 현재 블록을 끼울 수 없다면 다음 블록으로 넘어간다
		bool flag=false;
		for(int j=0 ; j<2 ; j++)
			if(!isPossible(nextX+dx[i][j], nextY+dy[i][j])) flag=true;
		if(flag) continue;
		
		// 전형적인 백트래킹의 형태
		data[nextX][nextY]='#';
		for(int j=0 ; j<2 ; j++) data[nextX+dx[i][j]][nextY+dy[i][j]]='#';

		ret+=solution();

		data[nextX][nextY]='.';
		for(int j=0 ; j<2 ; j++) data[nextX+dx[i][j]][nextY+dy[i][j]]='.';
	}

	return ret;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &row, &col);
		for(int i=0 ; i<row ; i++) scanf("%s", data[i]);

		int sol=solution();
		printf("%d\n", sol);
	}
}
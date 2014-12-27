#include <cstdio>

// ������ �װ��� ���¸� ��Ÿ���� ����迭
const int dx[4][2]={{0, 1}, {0, 1}, {1, 1}, {1,  1}};
const int dy[4][2]={{1, 0}, {1, 1}, {0, 1}, {0, -1}};
int t, row, col;
char data[21][21];

// ��ǥ�� ��ȿ���� üũ���ִ� �Լ�
bool isPossible(int x, int y)
{
	if(x==-1 || y==-1 || x==row || y==col || data[x][y]=='#') return false;
	return true;
}

int solution()
{
	// ���� ���忡�� ù��°�� ��ĭ�� ��� �����ϴ��� ã�´�
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

	// ���� ��ĭ�� ���ٸ� �� ä�����ٴ� ���̹Ƿ� 1�� ��ȯ�Ѵ�
	if(nextX==-1 && nextY==-1) return 1;

	// ���� ��ĭ�� �������� �װ��� ����� ���纻��
	// ���� ������ ���� ���� �� ���ʰ� ���� ���� ���� �ʴ´�
	int ret=0;
	for(int i=0 ; i<4 ; i++)
	{
		// ���� ����� ���� �� ���ٸ� ���� ������� �Ѿ��
		bool flag=false;
		for(int j=0 ; j<2 ; j++)
			if(!isPossible(nextX+dx[i][j], nextY+dy[i][j])) flag=true;
		if(flag) continue;
		
		// �������� ��Ʈ��ŷ�� ����
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
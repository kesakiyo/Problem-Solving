#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[]={-1, 1, 0, 0};
const int dy[]={0, 0, -1, 1};
int target, num;
bool flag, isUse[4][4];
char data[4][4];

// ��ǥ�� ��ȿ�� �˻�
bool isPossible(int x, int y)
{
	if(x==-1 || y==-1 || x==3 || y==3 || isUse[x][y]) return false;
	return true;
}

// ���� ����� ��ǥ���� ����Ʈ�� ���� ���ϴ� �Լ�
int getSum(const vector< pair<int, int> >& pii)
{
	// ������ ������ ���ϱ�Ƿ� plus�� true�� ������ش�
	bool plus=true;
	int ret=0;

	for(int i=0 ; i<pii.size() ; i++)
	{
		int x=pii[i].first, y=pii[i].second;

		// ¦����° ��ǥ�� ���� ������ �̷������
		if(i%2==0)
		{
			if(plus) ret+=data[x][y]-'0';
			else ret-=data[x][y]-'0';
		}
		// Ȧ����° ��ǥ�� �����ڰ� ��������
		else
		{
			if(data[x][y]=='+') plus=true;
			else plus=false;
		}
	}

	return ret;
}

void solution(int x, int y, int cnt, vector< pair<int, int> > coor)
{
	// ���� �Լ��� ȣ��� ��ǥ�� ����ߴٰ� üũ���ܰ� ���ÿ� ��ǥ ����Ʈ�� �߰��Ѵ�
	isUse[x][y]=true;
	coor.push_back(make_pair(x, y));

	// ���� �� ����ߴٸ� ���� �´��� Ȯ�����ش�
	if(cnt==num*2-1)
	{
		int sum=getSum(coor);

		// ���� ���� ������� ���� �Ǿ��ٸ�
		if(sum==target)
		{
			// ��ǥ�� ����Ѵ�
			puts("1");
			for(int i=0 ; i<coor.size() ; i++)
				printf("%d %d\n", coor[i].first, coor[i].second);

			// �׸��� �ٷ� ���α׷� ����.
			exit(0);
		}

		// �ƴ϶�� ���� ��ǥ�� �ٽ� false�� ������ش�. �̰� ���ؼ� �ι� Ʋ�ȴ�
		isUse[x][y]=false;
		return;
	}

	// ���� ���⿡�� 4�������� �������ش�
	// ��, ��, ��, �� 4�������� �����̸� 
	// ���� ������ ������, ������ ������ ���ڰ� �ڿ������� ������ �ȴ�
	// �������� ��Ʈ��ŷ�� �����̴�
	for(int i=0 ; i<4 ; i++)
	{
		int nextX=x+dx[i], nextY=y+dy[i];
		if(!isPossible(nextX, nextY)) continue;
		solution(nextX, nextY, cnt+1, coor);
	}

	// ���� �Լ� ���� ���� ����ߴٰ� üũ�Ѱ��� ������ �ش�
	isUse[x][y]=false;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &target, &num);
	for(int i=0 ; i<3 ; i++)
	{
		getchar();
		for(int j=0 ; j<3 ; j++)
			scanf("%c", &data[i][j]);
	}

	for(int i=0 ; i<3 ; i++)
		for(int j=0 ; j<3 ; j++)
			if(data[i][j]>='0' && data[i][j]<='9') 
				solution(i, j, 1, vector< pair<int, int> >());
	puts("0");
}
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

// 좌표의 유효성 검사
bool isPossible(int x, int y)
{
	if(x==-1 || y==-1 || x==3 || y==3 || isUse[x][y]) return false;
	return true;
}

// 현재 저장된 좌표들의 리스트로 합을 구하는 함수
int getSum(const vector< pair<int, int> >& pii)
{
	// 시작은 무조건 더하기므로 plus를 true로 만들어준다
	bool plus=true;
	int ret=0;

	for(int i=0 ; i<pii.size() ; i++)
	{
		int x=pii[i].first, y=pii[i].second;

		// 짝수번째 좌표는 수의 가감이 이루어진다
		if(i%2==0)
		{
			if(plus) ret+=data[x][y]-'0';
			else ret-=data[x][y]-'0';
		}
		// 홀수번째 좌표는 연산자가 정해진다
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
	// 현재 함수가 호출된 좌표를 사용했다고 체크해줌과 동시에 좌표 리스트에 추가한다
	isUse[x][y]=true;
	coor.push_back(make_pair(x, y));

	// 수를 다 사용했다면 답이 맞는지 확인해준다
	if(cnt==num*2-1)
	{
		int sum=getSum(coor);

		// 만약 내가 만들려는 수가 되었다면
		if(sum==target)
		{
			// 좌표를 출력한다
			puts("1");
			for(int i=0 ; i<coor.size() ; i++)
				printf("%d %d\n", coor[i].first, coor[i].second);

			// 그리고 바로 프로그램 종료.
			exit(0);
		}

		// 아니라면 현재 좌표를 다시 false로 만들어준다. 이거 안해서 두번 틀렸다
		isUse[x][y]=false;
		return;
	}

	// 현재 방향에서 4방향으로 움직여준다
	// 상, 하, 좌, 우 4방향으로 움직이면 
	// 숫자 다음엔 연산자, 연산자 다음엔 숫자가 자연스럽게 선택이 된다
	// 전형적인 백트래킹의 형태이다
	for(int i=0 ; i<4 ; i++)
	{
		int nextX=x+dx[i], nextY=y+dy[i];
		if(!isPossible(nextX, nextY)) continue;
		solution(nextX, nextY, cnt+1, coor);
	}

	// 역시 함수 종료 전에 사용했다고 체크한것을 해제해 준다
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
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

const int INF=987654321;
int t, x, y, DP[5010][5010], alpha[26], countX[26][5010], countY[26][5010];
char X[5010], Y[5010];

// 알파벳의 개수를 세주는 함수
void alphaCount(int len, char str[], int data[][5010])
{
	for(int i=1 ; i<=len ; i++)
	{
		int idx=str[i]-'A';

		// 해당 알파벳이 전체 몇번 나왔는가?
		alpha[idx]++;

		// 해당 문자열의 i번째 까지 왔을때 알파벳은 몇번 나왔는가?
		for(int j=0 ; j<26 ; j++)
		{
			if(idx==j) data[j][i]++;
			data[j][i]+=data[j][i-1];
		}
	}
}

// 초기화 함수.
void inIt()
{
	memset(alpha, 0, sizeof(alpha));
	memset(countX, 0, sizeof(countX));
	memset(countY, 0, sizeof(countY));
	alphaCount(x, X, countX);
	alphaCount(y, Y, countY);
	for(int i=0 ; i<5010 ; i++) for(int j=0 ; j<5010 ; j++) DP[i][j]=INF;
}

// 첫번째 문자열에서 x, 두번째 문자열에서 y번째 까지 왔을 때 점수를 계산해주는 함수
int getCost(int x, int y, char ch)
{
	int ret=0;

	// X문자열과 Y문자열을 합했을 때 1이라면 처음 등장한 것이다.
	if(countX[ch-'A'][x]+countY[ch-'A'][y]==1) ret-=x+y;

	// X문자열과 Y문자열을 합했을 때 전체 개수와 같다면 마지막으로 등장한 것이다.
	if(countX[ch-'A'][x]+countY[ch-'A'][y]==alpha[ch-'A']) ret+=x+y;

	return ret;
}

// DP[i][j] 는 첫 번째 문자열에서 i 번째까지, 두 번째 문자열에서 j 번째까지 봤을 때 최소 점수이다.
// DP[i][j]가 올 수 있는 가능성을 가진 위치는 DP[i-1][j] 와 DP[i][j-1]이다.
// DP[i-1][j]에서 왔다면 첫번째 문자열의 i번째 문자를 뽑아 온 것이므로 DP[i-1][j] + getCost(i, j, X[i]) 와 비교
// DP[i][j-1]에서 왔다면 두번째 문자열의 j번째 문자를 뽑아 온 것이므로 DP[i][j-1] + getCost(i, j, Y[i]) 와 비교
// getCost(i, j, ch)는 colorScore = LastIndex + (-FirstIndex)인 점을 이용한다.

// 사실 이 점화식에 정당성이 와닿지 않는다.
// 알파벳을 어떻게 뽑았냐에 따라서 뒤에 결과에 영향을 미치는 않을까?
// 바로 전에 최적값을 가져온다고 해서 현재상태의 최적값을 보장할 수 있을까.
// 알거 같기도 하고 모를거 같기도 하다. 아리송 함.

int solution()
{
	DP[1][0]=DP[0][1]=0;

	for(int i=0 ; i<=x ; i++)
	{
		for(int j=0 ; j<=y ; j++)
		{
			char first=X[i], second=Y[j];

			// 첫 번째 문자열을 뽑아서 현재 상태에 왔을 때 
			if(i!=0) DP[i][j]=min(DP[i][j], DP[i-1][j]+getCost(i, j, first));

			// 두 번째 문자열을 뽑아서 현재 상태에 왔을 때
			if(j!=0) DP[i][j]=min(DP[i][j], DP[i][j-1]+getCost(i, j, second));

			//printf("DP[ %d ][ %d ] : %d\n", i, j, DP[i][j]);
		}
	}

	return DP[x][y];
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s%s", X+1, Y+1);
		x=strlen(X+1); y=strlen(Y+1);
		inIt();

		// 여기서 왜 -1을 해줘야 답이 나오는 걸까....
		printf("%d\n", solution()-1);
	}
}
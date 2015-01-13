#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF=987654321;
int t, len, DP[10010];
char str[10010];

// pos번째 위치에서 길이가 len일 때 난이도를 계산하는 함수
int diff(int pos, int len)
{
	// 난이도가 1인 경우, 모든 자리의 수가 같아야 한다
	bool diffOne=true;
	for(int i=pos+1 ; i<pos+len ; i++)
		if(str[i-1]!=str[i]) diffOne=false;
	if(diffOne) return 1;

	// 난이도가 2인 경우, 각 자리의 차이는 1또는 -1이여야 한다
	bool diffTwo_1=true, diffTwo_2=true;
	for(int i=pos+1 ; i<pos+len ; i++)
	{
		if(str[i-1]-str[i]!=1) diffTwo_1=false;
		if(str[i-1]-str[i]!=-1) diffTwo_2=false;
	}
	if(diffTwo_1 || diffTwo_2) return 2;

	// 난이도가 4인 경우, 두 개의 숫자가 번갈아 가며 출력이 되어야 한다
	bool diffThree=true;
	for(int i=pos+2 ; i<pos+len ; i++)
		if(str[i-2]!=str[i]) diffThree=false;
	if(diffThree) return 4;

	// 난이도가 5인 경우, 각 숫자들의 차이가 동일해야 한다
	bool diffFour=true;
	for(int i=pos+2 ; i<pos+len ; i++)
		if(str[i-1]-str[i-2]!=str[i]-str[i-1]) diffFour=false;
	if(diffFour) return 5;

	// 그 외는 난이도가 10 이다
	return 10;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0 ; i<10010 ; i++) DP[i]=INF;

		// 기저사례를 쉽게 정해주기 위해 문자열의 시작 위치를 1로 잡아준다
		scanf("%s", str+1);
		len=strlen(str+1);

		// 기저사례, 0번째 위치는 문자가 없으므로 난이도가 0이다
		DP[0]=0;

		// DP 테이블을 채우기 전 점화식을 쉽게 쓰기 위해 함수를 하나 정의한다
		// diff(pos, len) => pos번째 위치부터 len만큼의 길이의 수를 봤을 때의 난이도
		// DP[pos] => pos번째 위치까지 봤을 때 최소의 난이도를 의미
		// DP[pos] = min(DP[pos], DP[pos-sel]+diff(pos-sel+1, sel)) : 3<= sel <= 5
		for(int i=3 ; i<=len ; i++)
			for(int j=3 ; j<=5 ; j++)
				if(i-j+1>=1) DP[i]=min(DP[i], DP[i-j]+diff(i-j+1, j));

		printf("%d\n", DP[len]);
	}
}
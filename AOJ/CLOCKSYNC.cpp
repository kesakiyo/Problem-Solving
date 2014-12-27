#include <cstdio>
#define min(a, b) (a)<(b) ? (a):(b)

// 각각의 버튼마다 눌려지는 시계를 표현, 3시간 단위
const int clock[10][16]={
	   //0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
		{3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 0},
		{0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 3},
		{3, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 0, 3, 0, 0, 0},
		{3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
		{0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
		{0, 0, 0, 0, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3},
		{0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0}};
const int INF=987654321;
int t, state[16], sol;

// 현재 모두 12시인지 확인, 12시라면 12로 나누어 떨어지는 것을 이용
bool isPossible()
{
	for(int i=0 ; i<16 ; i++)
		if(state[i]%12) return false;
	return true;
}

void solution(int pos, int cnt)
{
	// 기저 사례
	if(pos==10)
	{
		// 만약 시계가 모두 12시라면 현재 알려진 답과 가장 작은 답을 비교해본다
		if(isPossible()) sol=min(sol, cnt);
		return;
	}

	// 현재 버튼은 4번이상 누를 필요가 없다.
	// 4번 누르는 순간 원래모양으로 돌아가기 때문에 최대 3번까지만 눌러준다
	for(int repeat=0 ; repeat<4 ; repeat++)
	{
		// 전형적인 완전탐색의 형태
		for(int i=0 ; i<16 ; i++) state[i]+=clock[pos][i]*repeat;
		solution(pos+1, cnt+repeat);
		for(int i=0 ; i<16 ; i++) state[i]-=clock[pos][i]*repeat;
	}
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0 ; i<16 ; i++) scanf("%d", &state[i]);

		sol=INF;
		solution(0, 0);
		printf("%d\n", sol==INF ? -1:sol);
	}
}
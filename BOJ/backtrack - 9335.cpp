#include <cstdio>
#include <cstring>
#define min(a, b) (a)<(b) ? (a):(b)

const int INF=987654321;
int T, N, n, d, sol, isCover[21];
bool isFriend[21][21];

// 현재 모든 사람들이 광고를 볼 수 있는지 체크를 해 주는 함수
bool isPossible()
{
	for(int i=1 ; i<=N ; i++)
		if(!isCover[i]) return false;
	return true;
}

// 백트래킹을 이용해 풀 수 있는 전형적인 문제의 형태이다
// 전역변수를 이용해 상태공간을 관리를 해 준다
void solution(int pos, int cnt)
{
	// 만약 상태공간트리의 리프노드에 도달했을 때
	if(pos==N+1)
	{
		// 모든 사람들이 광고를 볼 수 있다면 현재 선택한 사람과 답 중 최소값을 선택
		if(isPossible()) sol=min(sol, cnt);
		return;
	}

	// 현재 위치의 사람을 선택하지 않은 경우
	solution(pos+1, cnt);

	// 현재 위치의 사람을 선택한 경우
	// 현재 사람, 즉 pos와 친구인 i를 찾아 광고를 보는 횟수를 증가시켜 준다
	// boolean 값으로 하지 않는 이유는 광고를 볼 수 있는 친구임에도 불구하고
	// 보지 않는다고 설정하게 되는 경우가 생기게 된다
	for(int i=1 ; i<=N ; i++)
		if(isFriend[pos][i]) isCover[i]++;

	// 다음 상태공간으로 넘어가기 위해 재귀호출
	solution(pos+1, cnt+1);

	// 현재 위치의 사람을 선택한 경우가 끝났으므로 원래대로 상태를 되돌려 줘야 한다(전역변수 이기 때문)
	// 위에서 했던것과 반대로 하나씩 감소시켜 준다
	for(int i=1 ; i<=N ; i++)
		if(isFriend[pos][i]) isCover[i]--;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	// 이 문제는 데이터의 입력 형식이 약간 까다로운 편이므로 주의해서 받는다
	scanf("%d", &T);
	while(T--)
	{
		// 초기 값들을 설정해 준다. 친구관계, 광고를 보게 되는 회수, sol값등.
		memset(isFriend, false, sizeof(isFriend));
		memset(isCover, 0, sizeof(isCover));
		sol=INF;

		scanf("%d", &N);
		for(int i=1 ; i<=N ; i++)
		{
			// 구현의 편의성을 위해 자기 자신또한 친구라고 체크를 해 준다
			isFriend[i][i]=true;

			scanf("%d", &n);
			while(n--)
			{
				scanf("%d", &d);

				// 아마 별 하자 없이 들어오겠지만 혹시 모르므로 양방향으로 설정
				isFriend[i][d]=isFriend[d][i]=true;
			}
		}
		
		solution(1, 0);
		printf("%d\n", sol);
	}
}
#include <cstdio>
#include <cstring>
#define min(a, b) (a)<(b) ? (a):(b)

const int INF=987654321;
int T, N, n, d, sol;
bool isFriend[21][21];

// 전역변수로 상태공간을 관리하기 번거로우므로 함수의 인자로 현재 광고를 보는 친구를 넘겨 준다
// 그렇게 된다면 다시 원래되로 돌려주는 코드가 없어지게 되므로 신경쓸게 하나 줄어든다
// 이 때 state는 bit mask를 이용해 손쉽게 관리해 줄 수 있다
// 구현 편의상 사람 번호가 1~N 번이 아니라 0~N-1 번으로 바꾸어 준다
void solution(int pos, int state, int cnt)
{
	// 상태공간트리의 리프노드에 도달했을때
	if(pos==N)
	{
		// 모든 사람들이 광고를 볼 수있다면 선택한 사람의 수화 sol값 중 최소값을 선택
		if(state==(1<<N)-1) sol=min(sol, cnt);
		return;
	}

	// 현재 위치의 사람을 선택하지 않은 경우
	solution(pos+1, state, cnt);
	
	// 현재 위치의 사람을 선택한 경우
	// 현재 위치의 사람과 친구라면 해당 bit를 on시켜준다
	// 그 뒤 재귀호출을 실행.
	for(int i=0 ; i<N ; i++)
		if(isFriend[pos][i]) state|=(1<<i);
	solution(pos+1, state, cnt+1);

	// call by value로 넘기기 때문에 다시 되돌려 줄 필요가 없다
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
		// 초기 값들을 설정해 준다. 친구관계, sol값등.
		memset(isFriend, false, sizeof(isFriend));
		sol=INF;

		scanf("%d", &N);
		for(int i=0 ; i<N ; i++)
		{
			// 구현의 편의성을 위해 자기 자신또한 친구라고 체크를 해 준다
			isFriend[i][i]=true;

			scanf("%d", &n);
			while(n--)
			{
				scanf("%d", &d);

				// 아마 별 하자 없이 들어오겠지만 혹시 모르므로 양방향으로 설정
				// 구현 편의 상 사람의 번호를 0번부터 시작되게 설정
				isFriend[i][d-1]=isFriend[d-1][i]=true;
			}
		}
		
		solution(0, 0, 0);
		printf("%d\n", sol);
	}
}
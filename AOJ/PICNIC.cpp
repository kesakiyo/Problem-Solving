#include <cstdio>
#include <cstring>

int t, n, m, u, v;
bool isFriend[11][11], isMatched[11];

// 모든 학생들이 짝을 지었는지 확인해주는 함수
bool isAllMatched()
{
	for(int i=0 ; i<n ; i++)
		if(!isMatched[i]) return false;
	return true;
}

int solution(int pos)
{
	// 기저사례
	if(pos==n)
	{
		// 모든 학생들이 짝이 지어져이쓰면 1을, 아니면 0을 반환
		if(isAllMatched()) return 1;
		else return 0;
	}

	if(isMatched[pos]) return solution(pos+1);
	else
	{
		// 현재 위치의 학생이 짝이 안지어 졌을때 새롭게 짝을 지어준다
		int ret=0;

		// 나보다 번호가 큰 학생이랑만 짝을 지어줌으로 순서를 강제할 수 있다
		// 순서 강제의 이유는 중복되게 짝을 지어주는 것을 피해주기 위해서
		for(int i=pos+1 ; i<n ; i++)
		{
			// 현재 짝이 지어져 있지 않으면서 친구인 학생을 찾아 짝을 지어준다
			if(!isMatched[i] && isFriend[pos][i])
			{
				// 전형적인 완전탐색의 형태
				isMatched[pos]=isMatched[i]=true;
				ret+=solution(pos+1);
				isMatched[pos]=isMatched[i]=false;
			}
		}
		return ret;
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
		scanf("%d%d", &n, &m);
		memset(isFriend, false, sizeof(isFriend));
		while(m--)
		{
			scanf("%d%d", &u, &v);
			isFriend[u][v]=isFriend[v][u]=true;
		}

		int sol=solution(0);
		printf("%d\n", sol);
	}
}
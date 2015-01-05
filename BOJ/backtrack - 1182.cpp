#include <cstdio>

int n, s, data[21];

// 백트래킹을 이용해 풀 수 있는 가장 기본적인 문제(물론 인풋이 작을 때)
int solution(int pos, int sum)
{
	// pos가 n일 때, 즉 상태공간트리에서 리프노드까지 내려왔을 때
	if(pos==n)
	{
		// 지금까지 더해온 수가 s와 같다면 1을 반환
		if(sum==s) return 1;

		// 아니라면 0을 반환
		return 0;
	}

	// 현재의 수를 선택한 경우와 선택하지 않은 경우를 더한뒤 반환
	return solution(pos+1, sum+data[pos]) + solution(pos+1, sum);
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &s);
	for(int i=0 ; i<n ; i++) scanf("%d", &data[i]);

	int sol=solution(0, 0);

	// 만약 찾으련는 합이 0이라면 공집합도 개수에 포함하게 되므로 1을 감소
	if(s==0) sol--;

	printf("%d\n", sol);
}
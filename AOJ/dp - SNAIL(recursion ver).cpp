#include <stdio.h>

int t, n, m;
double DP[1010][1010];

// 메모이제이션을 이용한 완전탐색 코드
double solution(int day, int dist) {

	// 기저사례
	// 첫 번째로 달팽이가 올라간 거리가 n이상이면 1.0을 반환한다
	// 두 번째로 day가 m이 되면 0.0을 반환 한다.
	// 이렇게 하면 추가적인 분기문 없이 성공, 실패 여부를 확인할 수 있다
	if(dist>=n) return 1.0;
	else if(day==m) return 0.0;

	// 현재 상태가 메모이제이션이 됐는가 확인한다
	double& ret=DP[day][dist];
	if(ret!=-1.0) return ret;

	// 두 가지의 확률을 구해서 더한다
	// 첫 번째는 현재 상태에서 비가 온 경우, 두 번째는 현재 상태에서 비가 오지 않은 경우
	// 비가 올 확률은 3/4 이므로 0.75를 곱해주고, 비가 오지 않을 확률은 1/4 이므로 0.25를 곱해준다
	return ret=solution(day+1, dist+2)*0.75+solution(day+1, dist+1)*0.25;
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		// DP테이블을 초기화 해주는 부분
		// 이 때 초기값을 무엇으로 해 줘야 하는가는 고민을 해 봐야 한다
		// 0.0 으로 초기값을 잡아준다고 가정을 하자
		// 그렇게 된다면 0.0 이란 값은 현재 상태에서 절대 탈출을 못한다는 의미와 탐색을 안했다는 두 가지 의미를
		// 가지게 된다. 하지만 컴퓨터는 탐색을 안했다는 것으로 생각을 하고 이미 탐색을 했음에도 불구하고 또다시
		// 탐색을 하게 된다. 메모이제이션을 한 이유가 사라지게 되는 것이다. 따라서 DP테이블을 초기화 할 때는
		// 절대로 나올 수 없는 값을 선택하는 것이 중요하다.
		for(int i=0 ; i<1010 ; i++) for(int j=0 ; j<1010 ; j++) DP[i][j]=-1.0;

		scanf("%d%d", &n, &m);

		double sol=solution(0, 0);
		printf("%.10lf\n", sol);
	}
}
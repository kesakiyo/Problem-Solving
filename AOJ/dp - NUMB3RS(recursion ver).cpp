#include <stdio.h>
#include <string.h>

int T, t, n, d, p, q, isConnected[51][51];
double DP[51][101], prob[51];

// 메모이제이션을 통한 완전탐색
double solution(int here, int day) {
	// 만약 기저사례를 < d일째 되는 날 q에 있는가? > 로 잡아주게 된다면
	// q가 달라질 때마다 새롭게 디피테이블을 작성해 줘야하는 번거로움이 생기게 된다
	// 왜냐면 우리가 구한 것은 day일이 지났을 때 q에 도달할 확률을 구한 것이므로...
	// 이해가 안간다면 다시한면 곱씹어 생각해 본다면 이해가 갈 것이다
	// 따라서 우리는 구하는 값을 day일이 지났을 때 here에 있는 확률로 바꿔서 계산을 해 줄 필요가 있다
	// 기저사례를 < 0일째 되는날 p, 즉 교도소에 있는가? > 라고 잡아주면 
	// 우리가 구하려는 값을 계산할 수 있지 않을까?
	if(day==0) {
		if(here==p) return 1.0;
		return 0.0;
	}

	// 현재 상태가 메모이제이션이 됐는지 확인한다
	double& ret=DP[here][day];
	if(ret!=-1.0) return ret;

	// ret이 -1.0이기 때문에 ret을 0.0으로 바꿔 줄 필요가 있다
	// 왜냐하면 확률을 계속해서 누적해 나갈 것인데 -1.0에서 누적해 나가면 안되기 때문
	ret=0.0;

	// here위치로 올 수 있는 there들에 대해 확률을 계산한다
	// here위치로 올 수 있는 there들에 대한 확률이기 때문에 곱하는 것은 prob[here]이 아니라
	// prob[there]이 되는것임을 명심한다
	// here로 올 수 있는것이 한가지가 아니기 때문에 += 연산자를 이용해 확률을 누적한다
	for(int there=0 ; there<n ; there++)
		if(isConnected[here][there]) 
			ret+=solution(there, day-1)*prob[there];

	return ret;
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		// 초기화를 하는 부분
		// 메모이제이션의 초기값은 -1.0으로 설정해 준다.(0.0은 두가지 의미를 내포하기 때문)
		for(int i=0 ; i<51 ; i++) for(int j=0 ; j<101 ; j++) DP[i][j]=-1.0;
		memset(isConnected, 0, sizeof(isConnected));

		scanf("%d%d%d", &n, &d, &p);
		for(int i=0 ; i<n ; i++) 
			for(int j=0 ; j<n ; j++) 
				scanf("%d", &isConnected[i][j]);

		// 현재 위치에서 다른 위치로 갈 수 있는 확률을 계산한다
		// 이 때 ( 정수 / 정수 ) 의 형태로 계산하는 일이 없도록 한다
		for(int i=0 ; i<n ; i++) {
			int cnt=0;
			for(int j=0 ; j<n ; j++)
				if(isConnected[i][j]) cnt++;
			prob[i]=1.0/cnt;
		}

		// 우리가 기저사례를 바꿔서 생각했기 때문에 새로운 질의가 들어올 때에도
		// DP테이블을 새롭게 갱신시켜줄 필요가 없어졌다
		scanf("%d", &t);
		while(t--) {
			scanf("%d", &q);
			double sol=solution(q, d);
			printf("%.10lf ", sol);
		}
		puts("");
	}
}
#include <stdio.h>
#include <string.h>

int T, t, n, d, p, q, isConnected[51][51];
double DP[101][51], prob[51];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		// 초기화를 하는 부분
		memset(DP, 0, sizeof(DP));
		memset(isConnected, 0, sizeof(isConnected));
		memset(prob, 0, sizeof(prob));

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

		// DP[day][here] => day일이 지났을 때 here에 있을 확률
		// DP[day][here] = sigma(1, n) DP[day-1][there.i] * prob[there.i] : (there은 here로 올 수 있는 마을들)
		// 위와같은 점화식을 쓸 수 있다.
		// 기저사례는 0일일 때 교도소에 있을 확률은 100% 이므로 1.0으로 설정을 해 준다
		DP[0][p]=1.0;
		for(int day=1 ; day<=d ; day++)
			for(int here=0 ; here<n ; here++)
				for(int there=0 ; there<n ; there++)
					if(isConnected[here][there]) DP[day][here]+=DP[day-1][there]*prob[there];

		scanf("%d", &t);
		while(t--) {
			scanf("%d", &q);
			printf("%.10lf ", DP[d][q]);
		}
		puts("");
	}
}
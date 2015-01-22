#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF=987654321;
int t, n, s, data[110], psum[110], DP[11][110], qunt[110][110];

// left부터 right까지 해당 수열을 양자화 하는 부분
// 평균과 평균+1, 두개의 수를 선택해 직접 계산해 본 뒤 최소값을 반환
int quntize(int left, int right) {
	int avg=(psum[right]-psum[left-1])/(right-left+1);

	int ret1=0, ret2=0;
	for(int i=left ; i<=right ; i++) {
		int diff1=data[i]-avg;
		ret1+=diff1*diff1;

		int diff2=data[i]-(avg+1);
		ret2+=diff2*diff2;
	}

	return min(ret1, ret2);
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		// DP테이블의 초기화, 최소값을 구하는 문제이므로 INF로 초기화를 기켜준다
		for(int i=0 ; i<11 ; i++) for(int j=0 ; j<110 ; j++) DP[i][j]=INF;

		scanf("%d%d", &n, &s);
		for(int i=1 ; i<=n ; i++) scanf("%d", &data[i]);

		// 문제 해결의 첫 번째 아이디어.
		// 양자화를 진행할 때 선택할 수 있는 수는 임의로 정할 수 있다.
		// 그렇다면 경우의 수는 너무 많아져 생각하기 영 까다로운게 아니다
		// 하지만 생각을 조금 해 본다면 양자화를 진행할 때 최선의 선택은 정해져 있다는 것을 알 수 있다
		// 양자화를 진행할 때 최선은 선택한 부분수열의 최솟값과 최댓값의 차이가 최소가 되게 선택을 하는것이다.
		// 그렇다면 수열을 정렬해 선택을 한다면 경우의 수를 줄일 수 있다
		sort(data+1, data+1+n);

		// 모든 경우에 대해 양자화를 진행하는 부분
		// 양자화를 할 때 선택할 수 있는 경우의 수는 n combination 2 이므로 O(n^2) 정도가 된다.
		// 이 때 부분합 배열을 이용해 연속된 구간의 합을 빠르게 계산할 수 있다
		// psum 은 partial sum의 약자
		for(int i=1 ; i<=n ; i++) psum[i]=psum[i-1]+data[i];
		for(int i=1 ; i<=n ; i++) for(int j=i ; j<=n ; j++) qunt[i][j]=quntize(i, j);

		// DP[cnt][pos] => 양자화를 cnt번 해서 pos번째 위치까지 왔을 때 최대값
		// DP[cnt][pos] = min(DP[cnt-1][prev-1] + Quntize(prev, pos)) : ( 1 <= prev <= pos)
		// 위와같은 점화식을 생각해 볼 수 있다
		DP[0][0]=0;
		for(int cnt=1 ; cnt<=s ; cnt++)
			for(int pos=1 ; pos<=n ; pos++)
				for(int prev=1 ; prev<=pos ; prev++)
					DP[cnt][pos] = min(DP[cnt][pos], DP[cnt-1][prev-1]+qunt[prev][pos]);

		// 답을 출력할 때 주의할 점은 양자화를 꼭 s번 해야된다는 것이 아니라는 점이다
		// 양자화는 최소 1번부터 최대 s번까지 가능하므로 모든 값을 비교해 최솟값을 출력해준다
		int sol=INF;
		for(int i=1 ; i<=s ; i++) sol=min(sol, DP[i][n]);

		printf("%d\n", sol);
	}
}
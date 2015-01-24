#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;
int t;
const ll INF=987654321234;
ll n, m, k, DP[210][210];
char str[210];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	// 이항계수를 미리 계산해 둔다
	// 오버플로가 발생할 수 있으므로 INF값을 설정해 놓고 더 작은값을 기록한다
	for(int i=0 ; i<210 ; i++) DP[i][0]=DP[i][i]=1;
	for(int i=1 ; i<210 ; i++)
		for(int j=1 ; j<=i-1 ; j++)
			DP[i][j]=min(INF, DP[i-1][j]+DP[i-1][j-1]);

	scanf("%d", &t);
	while(t--) {
		scanf("%lld%lld%lld", &n, &m, &k);
		int pos=0;

		// k번 째 수를 계산하는 과정
		// 총 네가지의 경우의 수를 가진다
		while(k && (n||m)) {

			// 첫 번째, n을 더이상 사용할 수 없을 때. 당연히 m을 사용해야 한다
			if(n==0) str[pos]='o', m--;

			// 두 번째, m을 더이상 사용할 수 없을 때. 당연히 n을 사용해야 한다
			else if(m==0) str[pos]='-', n--;
			else {
				// 세 번째. n을 사용했는데 k번째 문자열이 그것보다 작거나 같은 순서일때, n을 사용한다
				if(k<=DP[n-1+m][n-1]) {
					str[pos]='-';
					n--;
				}
				// 마지막 네 번째. n을 사용했는데 k번 째 문자열이 그것보다 크다면 k번째 문자열은 n을 사용하면
				// 안된다는 얘기와 마찬가지다. 따라서 m을 사용해 주고, n을 사용했을 때 가능한 순서을들 k에서 빼준다.
				else {
					k-=DP[n-1+m][n-1];
					str[pos]='o';
					m--;
				}
			}
			pos++;
		}
		str[pos]='\0';
		printf("%s\n", str);
	}
}
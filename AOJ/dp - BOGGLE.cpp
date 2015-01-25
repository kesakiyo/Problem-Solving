#include <stdio.h>
#include <string.h>

const int dx[]={0, -1, -1, -1, 0, 1, 1, 1};
const int dy[]={-1, -1, 0, 1, 1, 1, 0, -1};
int t, n, DP[11][11][11];
char data[15][15], str[20];

bool isPossible(int x, int y) {
	if(x==-1 || x==5 || y==-1 || y==5) return false;
	return true;
}

bool solution() {
	memset(DP, 0, sizeof(DP));

	int len=strlen(str);

	// DP[pos][x][y] => (x, y)의 문자를 str의 pos번째 문자와 매칭시켰을 때 경우의 수(그 전 글자들도 매칭이 되야 함)
	// DP[pos][x][y] += if(data[x][y]==str[pos]) DP[pos-1][x.1][y.1]
	// (x, y)의 문자와 str의 pos번째 문자가 같다면 현재 위치의 경우의 수는 현재 위치로 올 가능성이 있는 8방향의
	// pos-1번째 DP테이블의 값을 더해주면 구할 수 있다.
	// 하지만 전 값을 가져오기 귀찮으므로 pos+1번째로 보내주는 형식으로 구현을 했다

	// 기저사례, 첫 글자가 같으면 1로 설정을 해 준다
	for(int i=0 ; i<5 ; i++)
		for(int j=0 ; j<5 ; j++)
			if(str[0]==data[i][j]) DP[0][i][j]=1;

	for(int pos=0 ; pos<len ; pos++) {
		for(int x=0 ; x<5 ; x++) {
			for(int y=0 ; y<5 ; y++) {
				// 현재 글자가 일치하지 않으면 볼 필요가 없다
				if(str[pos]!=data[x][y]) continue;

				// 글자가 같다면 다음 위치로 가능한 8방향에 현재의 값을 더해준다
				for(int k=0 ; k<8 ; k++) {
					int nextX=x+dx[k], nextY=y+dy[k];
					if(!isPossible(nextX, nextY)) continue;
					DP[pos+1][nextX][nextY]+=DP[pos][x][y];
				}
			}
		}
	}

	// 마지막 글자까지 확인할 수 있는 방법이 있다면 true를 반환
	for(int i=0 ; i<5 ; i++)
		for(int j=0 ; j<5 ; j++)
			if(DP[len][i][j]) return true;

	// 방법이 없다면 false를 반환
	return false;
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		for(int i=0 ; i<5 ; i++) scanf("%s", data[i]);
		scanf("%d", &n);
		while(n--) {
			scanf("%s", str);
			printf("%s ", str);
			if(solution()) puts("YES");
			else puts("NO");
		}
	}
}
#include <stdio.h>
#include <algorithm>

using namespace std;

const int INF=987654321;
int n, d, MIN[2][3], MAX[2][3];

int main(void){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);

	// DP[x][y] => (x, y)까지 내려왔을 때 최적값이라고 하자. 최적값은 문제에 따라 최소가 될수도 최대가 될수도 있다
	// DP[x][y] = comp(DP[x][y], DP[x-1][prevY] + data[x][y])
	// 여기서 prevY는 현재 (x, y)에 올 수 있는 (x-1, prevY) 일때의 값이라 하자
	// 만약 현재 y가 1이라면 prevY는 (0, 1, 2)가 되는 것이고 y가 0이라면 (0, 1)이 되는 것이다.
	// 위 점화식대로 풀련 답이 나오는 것은 당여한다. 하지만 메모리제한이 4MB라는 것을 주목해야 한다
	// 따라서 Sliding Window 기법을 이용해 DP테이블의 크기를 줄여줘야 한다
	// (x, y)를 구하기 위해서는 x-1의 행만 이용하는것에 착안을 둬 DP테이블의 크기를 2 * 3으로 줄일 수 있다
	// 행렬의 값이 계속해서 변하기 때문에 (x, y)의 행렬을 계속해서 초기화 해주는 것도 한가지 방법이다
	for(int x=1 ; x<=n ; x++){
		for(int y=0 ; y<3 ; y++){
			scanf("%d", &d);

			// 행렬의 값을 초기화 해준다
			MIN[x%2][y]=INF;
			MAX[x%2][y]=0;

			// 전에 올 수 있는 위치를 결정해 주는 반복문
			for(int dy=-1 ; dy<=1 ; dy++){
				int prevX=x-1, prevY=y+dy;

				// 만약 올 수 없는 위치라면 continue
				if(prevY==-1 || prevY==3) continue;
				MAX[x%2][y]=max(MAX[x%2][y], MAX[prevX%2][prevY]+d);
				MIN[x%2][y]=min(MIN[x%2][y], MIN[prevX%2][prevY]+d);
			}
		}
	}

	// 마지막에 어느곳으로 내려왔는지에 따라 최적값이 다르기 때문에 모두 탐색
	int mmin=INF, mmax=0;
	for(int i=0 ; i<3 ; i++){
		mmin=min(mmin, MIN[n%2][i]);
		mmax=max(mmax, MAX[n%2][i]);
	}
	
	printf("%d %d\n", mmax, mmin);
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int dx[]={ 0, -1, -1};
const int dy[]={-1, -1,  0};
int t, n, w, v[110], c[110], DP[110][1010], P[110][1010];
string str[110];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin>>t;
	while(t--) {
		memset(DP, 0, sizeof(DP));
		cin>>n>>w;
		for(int i=1 ; i<=n ; i++) cin>>str[i]>>v[i]>>c[i];

		// DP[pos][weight] => pos번째 물건을 봤고 무게가 weight일때 가능한 최댓값
		// DP[pos][weight] = if(w.i>weight) DP[pos-1][weight]
		//                   else max(DP[pos-1][weight], DP[pos-1][weight-w.i]+cost.i)
		// DP테이블을 계산하기 전에 한가지 고려해야 될 사항은 현재 보고있는 물건의 무게가 weight보다 무거운가를 봐야한다
		// 만약 무겁다면 나에게는 선택지가 없기때문에 바로 전 물건에서 계산이 되었던 DP[pos-1][weight]을 그대로 가져온다
		// 그게 아니라면 이제 다시 선택지가 두개로 나눠진다. 이 물건을 선택하는 경우와 선택하지 않는 경우로.
		// 선택하지 않는 경우라면 DP[pos-1][weight]이 현재 테이블에 가져올 수 있는 값이 될 것이고
		// 선택하는 경우라면 DP[pos-1][weight-w.i]+cost.i 가 현재 테이블에 가져올 수 있는 값이 될 것이다
		// 이 두가지 값중 더 큰 값을 가져오면 된다.
		// 이 과정을 마치면 절박도의 최댓값을 구할 수 있지만 내가 무엇을 선택했는지에 대해서는 알 수 없다
		// 그렇기 때문에 DP테이블을 역추적해갈 수 있는 parnet배열이 필요하다
		// 여기서 생각할 수 있는점은 물건을 선택할 때 변경이 되는것은 weight이라는 점이다.
		// 이 물건을 선택하건 선택하지 않건 pos는 항상 하나씩 증가하기 때문에 parent배열에 기록해 줄 값은 현재 DP테이블의
		// 최댓값을 기록하게 해준 pos-1의 weight이다. 만약 parnet배열의 값의 weight이 pos-1과 동일하다면 현재 물건은 선택하지
		// 않은것이 되고, weight이 변경이 된다면 현재 물건을 선택한 경우이다. 이러한 것을 고려해 DP테이블을 역추적해가면 된다
		for(int i=1 ; i<=n ; i++) {
			for(int j=0 ; j<=w ; j++)
				if(j<v[i]) {
					DP[i][j]=DP[i-1][j];
					P[i][j]=j;
				}
				else {
					if(DP[i-1][j]>DP[i-1][j-v[i]]+c[i]) {
						DP[i][j]=DP[i-1][j];
						P[i][j]=j;
					}
					else {
						DP[i][j]=DP[i-1][j-v[i]]+c[i];
						P[i][j]=j-v[i];
					}
				}
		}

		vector<string> sol;
		int x=n, y=w;
		while(x&&y) {
			int parent=P[x][y];
			if(parent!=y) {
				y=parent;
				sol.push_back(str[x]);
			}
			x--;
		}
		cout<<DP[n][w]<<" "<<sol.size()<<endl;
		for(int i=0 ; i<sol.size() ; i++) cout<<sol[i]<<endl;
	}
}
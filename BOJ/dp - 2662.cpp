#include <cstdio>
#include <algorithm>

using namespace std;

const int INF=987654321;
int n, k, m, d, data[21][310], DP[21][310], parent[21][310], invest[21];

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	// 데이터를 입력받는 부분, row는 기업 번호, 각 행은 투자 금액을 의미
	scanf("%d%d", &n, &k);
	while(scanf("%d", &m)!=EOF)
	{
		for(int i=0 ; i<k ; i++)
		{
			scanf("%d", &d);
			data[i][m]=d;
		}
	}

	// DP[pos][money] : pos번째 기업에 money원을 투자 했을 때 얻을 수 있는 최대 수익
	// DP[pos][money] = max(DP[pos][money], for each possible select money M : DP[pos-1][money-M])
	// 위 점화식과 같이 단순하게 계산을 하면 최대 수익은 쉽게 구할 수 있다.
	// 하지만 본 문제는 최적해 뿐만 아니라 각 기업에 투자 한 금액을 구할 수 있어야 한다
	// 따라서 DP[pos][money]가 최적해를 가질 때 얼마 투자를 했는지 기록할 수 있는 parnet[pos][money]를 따로 기록해준다
	for(int pos=0 ; pos<k ; pos++)
	{
		for(int money=0 ; money<=m ; money++)
		{
			for(int sel=0 ; sel<=m ; sel++)
			{
				if(money-sel<0) break;

				int investMoney=DP[pos-1][money-sel]+data[pos][sel];

				// 만약 더 좋은 최적해가 발견이 되었다면?
				if(DP[pos][money]<investMoney)
				{
					// DP테이블을 갱신해준다
					DP[pos][money]=investMoney;

					// 또한 parent배열에 현재 선택한 금액을 기록해준다
					parent[pos][money]=sel;
				}
			}
		}
	}

	printf("%d\n", DP[k-1][n]);

	// parent배열을 이용해 최적해를 구하는 과정을 역추적 한다
	int pos=k-1, cur=n;
	while(pos!=-1)
	{
		// parent배열에 기록된 값을 가져온다
		int curInvest=parent[pos][cur];
		invest[pos]=curInvest;

		// 현재 투자한 금액에서 parent배열에 기록된 값을 뺀다
		// 그럼 그 전에 기업에 투자한 금액을 알 수 있다
		cur-=curInvest;
		pos--;
	}

	for(int i=0 ; i<k ; i++) printf("%d ", invest[i]);
}
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

		// DP[pos][weight] => pos��° ������ �ð� ���԰� weight�϶� ������ �ִ�
		// DP[pos][weight] = if(w.i>weight) DP[pos-1][weight]
		//                   else max(DP[pos-1][weight], DP[pos-1][weight-w.i]+cost.i)
		// DP���̺��� ����ϱ� ���� �Ѱ��� ����ؾ� �� ������ ���� �����ִ� ������ ���԰� weight���� ���ſ�� �����Ѵ�
		// ���� ���̴ٸ� �����Դ� �������� ���⶧���� �ٷ� �� ���ǿ��� ����� �Ǿ��� DP[pos-1][weight]�� �״�� �����´�
		// �װ� �ƴ϶�� ���� �ٽ� �������� �ΰ��� ��������. �� ������ �����ϴ� ���� �������� �ʴ� ����.
		// �������� �ʴ� ����� DP[pos-1][weight]�� ���� ���̺� ������ �� �ִ� ���� �� ���̰�
		// �����ϴ� ����� DP[pos-1][weight-w.i]+cost.i �� ���� ���̺� ������ �� �ִ� ���� �� ���̴�
		// �� �ΰ��� ���� �� ū ���� �������� �ȴ�.
		// �� ������ ��ġ�� ���ڵ��� �ִ��� ���� �� ������ ���� ������ �����ߴ����� ���ؼ��� �� �� ����
		// �׷��� ������ DP���̺��� �������ذ� �� �ִ� parnet�迭�� �ʿ��ϴ�
		// ���⼭ ������ �� �ִ����� ������ ������ �� ������ �Ǵ°��� weight�̶�� ���̴�.
		// �� ������ �����ϰ� �������� �ʰ� pos�� �׻� �ϳ��� �����ϱ� ������ parent�迭�� ����� �� ���� ���� DP���̺���
		// �ִ��� ����ϰ� ���� pos-1�� weight�̴�. ���� parnet�迭�� ���� weight�� pos-1�� �����ϴٸ� ���� ������ ��������
		// �������� �ǰ�, weight�� ������ �ȴٸ� ���� ������ ������ ����̴�. �̷��� ���� ����� DP���̺��� �������ذ��� �ȴ�
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
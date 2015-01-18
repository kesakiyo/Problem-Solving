#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int t, n, DP[110][110];
string pattern, str;

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin>>t;
	while(t--) {
		vector<string> sol;
		cin>>pattern>>n;

		while(n--) {
			memset(DP, 0, sizeof(DP));
			cin>>str;

			// DP[x][y] => pattern�� x���ڱ���, string�� y���ڱ��� ���� �� ��Ī�� �� �� �ִ°�?
			// DP[x][y]�� �ٷ� �� �ܰ迡�� �������⿡�� ��������� ���� �ֱ� ������ �ణ �ٸ� ����� ����Ѵ�
			// �׸��� ������ʸ� ����� �ֱ� ���� DP���̺��� ����� �� �ε����� �ϳ��� �������� ����� ���ش�
			// 1. ���� x, y�� ���ɼ��� ���ٸ� �� �ڴ� ���̻� �� �ʿ䰡 ����.
			// 2. ���� x �� '?' �̰ų� pattern[x]�� str[y] �� ���ٸ� DP[x+1][y+1]�� true�̴�.
			// 3. ���� x �� '*' ��� string�� 0���ں��� ���� ��Ī���Ѻ���. DP���̺� ǥ�ø� ���ִ°��� ���� true��
			// 4. string���ڰ� ������ ���ϵ� ���ڿ��� �ִ� '*'�� 0���� ��Ī�� �� ���� �ֱ� ������ y�� ��Ʈ�� ������ ��ŭ
			//    ������ ������� �Ѵ�(�� �κ��� ���ذ� �Ȱ��� DP���̺��� ���� �׷����� ���� ��õ)
			DP[0][0]=1;
			for(int i=0 ; i<pattern.size() ; i++) {
				for(int j=0 ; j<=str.size() ; j++) {
					if(DP[i][j]) {
						if(j!=str.size() && (pattern[i]=='?' || pattern[i]==str[j])) DP[i+1][j+1]=1;
						else if(pattern[i]=='*')
							for(int k=j ; k<=str.size() ; k++) DP[i+1][k]=1;
					}
				}
			}

			if(DP[pattern.size()][str.size()]) sol.push_back(str);
		}

		sort(sol.begin(), sol.end());
		for(int i=0 ; i<sol.size() ; i++) cout<<sol[i]<<endl;
	}
}
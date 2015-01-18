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

			// DP[x][y] => pattern을 x글자까지, string을 y글자까지 봤을 때 매칭이 될 수 있는가?
			// DP[x][y]를 바로 전 단계에서 가져오기에는 제약사항이 많이 있기 때문에 약간 다른 방법을 사용한다
			// 그리고 기저사례를 만들어 주기 위해 DP테이블을 기록할 때 인덱스를 하나씩 증가시켜 기록을 해준다
			// 1. 현재 x, y가 가능성이 없다면 그 뒤는 더이상 볼 필요가 없다.
			// 2. 현재 x 가 '?' 이거나 pattern[x]와 str[y] 가 같다면 DP[x+1][y+1]은 true이다.
			// 3. 현재 x 가 '*' 라면 string을 0글자부터 전부 매칭시켜본다. DP테이블에 표시를 해주는것은 역시 true값
			// 4. string문자가 끝나고 와일드 문자열에 있는 '*'이 0글자 매칭이 될 수도 있기 때문에 y는 스트링 사이즈 만큼
			//    진행을 시켜줘야 한다(이 부분이 이해가 안가면 DP테이블을 직접 그려보는 것을 추천)
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
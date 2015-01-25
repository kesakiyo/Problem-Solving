#include <stdio.h>
#include <string>

using namespace std;

typedef long long ll;

int t, n;
ll p, l, gen[51];

void solution(string str, ll& pos, int g) {
	// 기저사례, pos가 p+l보다 더 크다면 함수를 종료한다
	if(pos>=p+l) return;

	// 인자로 받은 문자열을 가지고 넘겨 뛸 부분과 탐색 할 부분을 나눈다
	for(int i=0 ; i<str.length() ; i++) {
		// F, -, +와 같은 경우는 문자열이 길어지지 않으므로 바로 확인을 한다
		// 현재 위치가 p이상, p+l 미만일 경우 출력을 해 준다
		if(str[i]=='F' || str[i]=='-' || str[i]=='+') {
			if(p<=pos && pos<p+l) printf("%c", str[i]);
			pos++;
		}
		// 현재 문자가 X 또는 Y일 경우는 문자열이 세대를 거듭하면서 길어진다
		else {
			// 현재 세대가 마지막 세대이고 pos가 구하려는 범위안에 있다면 출력을 한다
			if(g==n && p<=pos && pos<p+l) {
				printf("%c", str[i]);
				pos++;
			}
			// 마지막 세대가 아니라면 확장을 한다. 따라서 봐야되는지 안봐도 되는지 확인을 한다
			else {
				// 앞으로 몇글자가 확장이 될지 확인을 한다
				ll leftGen=gen[n-g];

				// 만약 확장을 해도 p번째 글자에 미치지 못한다면 pos에 확장된 글자수만큼을 더해준다
				// 볼 필요가 없는 부분은 건너뛰겠다는 의미를 가진다
				if(pos+leftGen-1<p) pos+=leftGen;

				// 그게 아니라면 확장된 문자열 내에 찾으려는 문자가 있다는 뜻이 된다
				// 따라서 X, Y에 따라 알맞은 확장 문자를 넣어준 뒤 세대를 증가시켜준다
				else solution(str[i]=='X' ? "X+YF":"FX-Y", pos, g+1);
			}
		}
	}
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	// 드래곤 커브에서 한 세대가 지날수록 X또는 Y는 x*2+2 가 됨을 알 수 있다
	// 이러한 값을 미리 계산해 둔다
	gen[0]=1;
	for(int i=1 ; i<=50 ; i++) gen[i]=gen[i-1]*2+2;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%lld%lld", &n, &p, &l);
		ll pos=1;
		solution("FX", pos, 0);
		puts("");
	}
}
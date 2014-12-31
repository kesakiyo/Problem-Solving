#include <cstdio>
#include <stdlib.h>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
const ll INF=1000000010;
ll total=0, cur=3, n;
vector<ll> s;
bool isRecur[1010];
 
// 답을 구하는 함수
void solution(ll cnt, int pos)
{
	// 현재의 길이가 남은 길이보다 길때까지 반복
    while(cnt>s[pos]) cnt-=s[pos++];
 
	// 만약 재귀적으로 생성된 부분이라면 앞쪽에서 다시 찾아본다
    if(isRecur[pos]) solution(cnt, 0);

	// 아니라면? 첫번째 글자가 'm'이고 나머지는 'o'이다
    else if(cnt==1) puts("m");
    else puts("o");

	// 답을 찾은 뒤에는 프로그램 종료
    exit(0);
}
 
int main(void)
{
	// 답을 계산하기 전 Moo 수열을 미리 계산해 놓는다
	// Moo 수열의 규칙을 이해했다면 새롭게 추가된 뒤 새롭게 추가되기 전
	// 수열이 그대로 뒤에 붙는다는 것을 알 수 있다
	// 이 점을 이용해 재귀적으로 답을 도출 해 낼 것이다
    while(total<INF)
    {
		// 새롭게 수열을 추가한다
        total+=cur;
        s.push_back(cur);
        isRecur[s.size()-1]=false;
 
		// 새로운 수열이 추가되기 전 길이를 계산한다
        int last=s.size()-1;
        ll temp=0;
        for(int i=0 ; i<last ; i++) temp+=s[i];
 
		// 새로운 수열이 추가된 뒤의 뒤따라 오는 수열은 재귀적으로 생성된 수열이다
		// 따라서 재귀적으로 생성이 됐다는 것을 알려준다
        s.push_back(temp);
        isRecur[s.size()-1]=true;
        total+=temp;
 
        cur++;
    }
 
    scanf("%lld", &n);
    solution(n, 0);
}
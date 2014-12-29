#include <cstdio>
#include <queue>
 
using namespace std;
 
int n, k;
 
// 현재 수에서 작거나 같은 2의 거듭제곱의 수를 반환
int upper(int num)
{
    int ret=1;
    while(ret<=num) ret*=2;
    return ret/2;
}
 
// 문제의 속성을 파악해 본다면 현재의 수를 최대 k개의 2의 거듭제곱의 수들을 사용해 
// 표현할 수 있는가의 문제가 된다. 현재 수를 가장 작은 2의 거듭제곱의 수들로 표현한 후
// 그 수들을 다시 합쳐 2의 거듭제곱 형태로 만들어 나가 최종적으로 k개로 만든다면 답이 된다
int solution(int num)
{
    priority_queue<int> pq;
    int ret=0;
 
	// 처음 입력받은 수를 2의 거듭제곱의 형태로 표현한다. 가장 큰 것부터 만들어 나가면 된다
    while(num)
    {
        int least=upper(num);
        num-=least;
        pq.push(-least);
    }
 
	// pq에 들어있는 수 들의 개수가 k개보다 클 때
    while(pq.size()>k)
    {
        int first=-pq.top(); pq.pop();
        int second=-pq.top(); pq.pop();

		// 첫 번째와 두 번째로 작은 수를 뽑아 합해서 다시 2의 거듭제곱으로 만드는게 최선의 방법이다.
		// first = 2^a, second = 2^b ( first <= second )
		// ret = second - first
		// (first+ret) + (second) = (2^a + ret) + (2^b) = 2^b + 2^b = 2^(b+1).
        ret+=second-first;
        pq.push(-second*2);
    }
 
    return ret;
}
 
int main(void)
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
 
    printf("%d\n", solution(n));
}
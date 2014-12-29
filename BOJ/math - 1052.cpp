#include <cstdio>
#include <queue>
 
using namespace std;
 
int n, k;
 
// ���� ������ �۰ų� ���� 2�� �ŵ������� ���� ��ȯ
int upper(int num)
{
    int ret=1;
    while(ret<=num) ret*=2;
    return ret/2;
}
 
// ������ �Ӽ��� �ľ��� ���ٸ� ������ ���� �ִ� k���� 2�� �ŵ������� ������ ����� 
// ǥ���� �� �ִ°��� ������ �ȴ�. ���� ���� ���� ���� 2�� �ŵ������� ����� ǥ���� ��
// �� ������ �ٽ� ���� 2�� �ŵ����� ���·� ����� ���� ���������� k���� ����ٸ� ���� �ȴ�
int solution(int num)
{
    priority_queue<int> pq;
    int ret=0;
 
	// ó�� �Է¹��� ���� 2�� �ŵ������� ���·� ǥ���Ѵ�. ���� ū �ͺ��� ����� ������ �ȴ�
    while(num)
    {
        int least=upper(num);
        num-=least;
        pq.push(-least);
    }
 
	// pq�� ����ִ� �� ���� ������ k������ Ŭ ��
    while(pq.size()>k)
    {
        int first=-pq.top(); pq.pop();
        int second=-pq.top(); pq.pop();

		// ù ��°�� �� ��°�� ���� ���� �̾� ���ؼ� �ٽ� 2�� �ŵ��������� ����°� �ּ��� ����̴�.
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
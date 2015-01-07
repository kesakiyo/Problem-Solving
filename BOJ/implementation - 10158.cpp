#include <cstdio>
#include <vector>

using namespace std;

int c, r, x, y, t;
vector<int> col, row;

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &c, &r);
	scanf("%d%d", &y, &x);
	scanf("%d", &t);

	// 이 문제는 직접 시뮬레이션을 다 돌려본다면 쉽게 구할 수 있지만
	// t가 2억이나 되기 때문에 다 돌려보기에는 위험 부담이 따른다
	// 또한 반사되는 위치를 일일히 계산을 해야하기 때문에 귀찮기도 하다
	// 이 문제를 수학적으로 접근하게 되면 생각할게 많아지기 때문에
	// 약간의 수학을 가미한 완전탐색방법을 이용하도록 한다

	// 약간의 생각을 하면 떠올릴 수 있는 사실
	// 1. 가로의 움직임과 세로의 움직임을 따로따로 계산을 해도 된다
	// 2. 각각의 움직임들은 일정 시퀀스의 반복이다
	// 3. 따라서 각각의 위치에 t을 더한 뒤 모듈러 연산을 통해 답을 구할 수 있다
	// [ 0, 1, 2, 3, 4, ... n-1, n, n-1, n-2, ... 3, 2, 1 ] 이런형태의 시퀀스의 반복

	for(int i=0 ; i<=c ; i++) col.push_back(i);
	for(int i=c-1 ; i>=1 ; i--) col.push_back(i);
	for(int i=0 ; i<=r ; i++) row.push_back(i);
	for(int i=r-1 ; i>=1 ; i--) row.push_back(i);

	x+=t; y+=t;
	x%=(int)row.size();
	y%=(int)col.size();

	printf("%d %d\n", col[y], row[x]);
}
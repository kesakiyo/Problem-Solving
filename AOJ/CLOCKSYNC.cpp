#include <cstdio>
#define min(a, b) (a)<(b) ? (a):(b)

// ������ ��ư���� �������� �ð踦 ǥ��, 3�ð� ����
const int clock[10][16]={
	   //0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
		{3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 0},
		{0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 3},
		{3, 0, 0, 0, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 0, 3, 0, 0, 0},
		{3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
		{0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3},
		{0, 0, 0, 0, 3, 3, 0, 3, 0, 0, 0, 0, 0, 0, 3, 3},
		{0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 3, 3, 3, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0}};
const int INF=987654321;
int t, state[16], sol;

// ���� ��� 12������ Ȯ��, 12�ö�� 12�� ������ �������� ���� �̿�
bool isPossible()
{
	for(int i=0 ; i<16 ; i++)
		if(state[i]%12) return false;
	return true;
}

void solution(int pos, int cnt)
{
	// ���� ���
	if(pos==10)
	{
		// ���� �ð谡 ��� 12�ö�� ���� �˷��� ��� ���� ���� ���� ���غ���
		if(isPossible()) sol=min(sol, cnt);
		return;
	}

	// ���� ��ư�� 4���̻� ���� �ʿ䰡 ����.
	// 4�� ������ ���� ����������� ���ư��� ������ �ִ� 3�������� �����ش�
	for(int repeat=0 ; repeat<4 ; repeat++)
	{
		// �������� ����Ž���� ����
		for(int i=0 ; i<16 ; i++) state[i]+=clock[pos][i]*repeat;
		solution(pos+1, cnt+repeat);
		for(int i=0 ; i<16 ; i++) state[i]-=clock[pos][i]*repeat;
	}
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0 ; i<16 ; i++) scanf("%d", &state[i]);

		sol=INF;
		solution(0, 0);
		printf("%d\n", sol==INF ? -1:sol);
	}
}
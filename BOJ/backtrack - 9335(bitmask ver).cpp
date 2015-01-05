#include <cstdio>
#include <cstring>
#define min(a, b) (a)<(b) ? (a):(b)

const int INF=987654321;
int T, N, n, d, sol;
bool isFriend[21][21];

// ���������� ���°����� �����ϱ� ���ŷο�Ƿ� �Լ��� ���ڷ� ���� ���� ���� ģ���� �Ѱ� �ش�
// �׷��� �ȴٸ� �ٽ� �����Ƿ� �����ִ� �ڵ尡 �������� �ǹǷ� �Ű澵�� �ϳ� �پ���
// �� �� state�� bit mask�� �̿��� �ս��� ������ �� �� �ִ�
// ���� ���ǻ� ��� ��ȣ�� 1~N ���� �ƴ϶� 0~N-1 ������ �ٲپ� �ش�
void solution(int pos, int state, int cnt)
{
	// ���°���Ʈ���� ������忡 ����������
	if(pos==N)
	{
		// ��� ������� ���� �� ���ִٸ� ������ ����� ��ȭ sol�� �� �ּҰ��� ����
		if(state==(1<<N)-1) sol=min(sol, cnt);
		return;
	}

	// ���� ��ġ�� ����� �������� ���� ���
	solution(pos+1, state, cnt);
	
	// ���� ��ġ�� ����� ������ ���
	// ���� ��ġ�� ����� ģ����� �ش� bit�� on�����ش�
	// �� �� ���ȣ���� ����.
	for(int i=0 ; i<N ; i++)
		if(isFriend[pos][i]) state|=(1<<i);
	solution(pos+1, state, cnt+1);

	// call by value�� �ѱ�� ������ �ٽ� �ǵ��� �� �ʿ䰡 ����
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	// �� ������ �������� �Է� ������ �ణ ��ٷο� ���̹Ƿ� �����ؼ� �޴´�
	scanf("%d", &T);
	while(T--)
	{
		// �ʱ� ������ ������ �ش�. ģ������, sol����.
		memset(isFriend, false, sizeof(isFriend));
		sol=INF;

		scanf("%d", &N);
		for(int i=0 ; i<N ; i++)
		{
			// ������ ���Ǽ��� ���� �ڱ� �ڽŶ��� ģ����� üũ�� �� �ش�
			isFriend[i][i]=true;

			scanf("%d", &n);
			while(n--)
			{
				scanf("%d", &d);

				// �Ƹ� �� ���� ���� ���������� Ȥ�� �𸣹Ƿ� ��������� ����
				// ���� ���� �� ����� ��ȣ�� 0������ ���۵ǰ� ����
				isFriend[i][d-1]=isFriend[d-1][i]=true;
			}
		}
		
		solution(0, 0, 0);
		printf("%d\n", sol);
	}
}
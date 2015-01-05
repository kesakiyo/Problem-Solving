#include <cstdio>
#include <cstring>
#define min(a, b) (a)<(b) ? (a):(b)

const int INF=987654321;
int T, N, n, d, sol, isCover[21];
bool isFriend[21][21];

// ���� ��� ������� ���� �� �� �ִ��� üũ�� �� �ִ� �Լ�
bool isPossible()
{
	for(int i=1 ; i<=N ; i++)
		if(!isCover[i]) return false;
	return true;
}

// ��Ʈ��ŷ�� �̿��� Ǯ �� �ִ� �������� ������ �����̴�
// ���������� �̿��� ���°����� ������ �� �ش�
void solution(int pos, int cnt)
{
	// ���� ���°���Ʈ���� ������忡 �������� ��
	if(pos==N+1)
	{
		// ��� ������� ���� �� �� �ִٸ� ���� ������ ����� �� �� �ּҰ��� ����
		if(isPossible()) sol=min(sol, cnt);
		return;
	}

	// ���� ��ġ�� ����� �������� ���� ���
	solution(pos+1, cnt);

	// ���� ��ġ�� ����� ������ ���
	// ���� ���, �� pos�� ģ���� i�� ã�� ���� ���� Ƚ���� �������� �ش�
	// boolean ������ ���� �ʴ� ������ ���� �� �� �ִ� ģ���ӿ��� �ұ��ϰ�
	// ���� �ʴ´ٰ� �����ϰ� �Ǵ� ��찡 ����� �ȴ�
	for(int i=1 ; i<=N ; i++)
		if(isFriend[pos][i]) isCover[i]++;

	// ���� ���°������� �Ѿ�� ���� ���ȣ��
	solution(pos+1, cnt+1);

	// ���� ��ġ�� ����� ������ ��찡 �������Ƿ� ������� ���¸� �ǵ��� ��� �Ѵ�(�������� �̱� ����)
	// ������ �ߴ��Ͱ� �ݴ�� �ϳ��� ���ҽ��� �ش�
	for(int i=1 ; i<=N ; i++)
		if(isFriend[pos][i]) isCover[i]--;
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
		// �ʱ� ������ ������ �ش�. ģ������, ���� ���� �Ǵ� ȸ��, sol����.
		memset(isFriend, false, sizeof(isFriend));
		memset(isCover, 0, sizeof(isCover));
		sol=INF;

		scanf("%d", &N);
		for(int i=1 ; i<=N ; i++)
		{
			// ������ ���Ǽ��� ���� �ڱ� �ڽŶ��� ģ����� üũ�� �� �ش�
			isFriend[i][i]=true;

			scanf("%d", &n);
			while(n--)
			{
				scanf("%d", &d);

				// �Ƹ� �� ���� ���� ���������� Ȥ�� �𸣹Ƿ� ��������� ����
				isFriend[i][d]=isFriend[d][i]=true;
			}
		}
		
		solution(1, 0);
		printf("%d\n", sol);
	}
}
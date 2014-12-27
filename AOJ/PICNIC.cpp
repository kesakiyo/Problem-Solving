#include <cstdio>
#include <cstring>

int t, n, m, u, v;
bool isFriend[11][11], isMatched[11];

// ��� �л����� ¦�� �������� Ȯ�����ִ� �Լ�
bool isAllMatched()
{
	for(int i=0 ; i<n ; i++)
		if(!isMatched[i]) return false;
	return true;
}

int solution(int pos)
{
	// �������
	if(pos==n)
	{
		// ��� �л����� ¦�� �������̾��� 1��, �ƴϸ� 0�� ��ȯ
		if(isAllMatched()) return 1;
		else return 0;
	}

	if(isMatched[pos]) return solution(pos+1);
	else
	{
		// ���� ��ġ�� �л��� ¦�� ������ ������ ���Ӱ� ¦�� �����ش�
		int ret=0;

		// ������ ��ȣ�� ū �л��̶��� ¦�� ���������� ������ ������ �� �ִ�
		// ���� ������ ������ �ߺ��ǰ� ¦�� �����ִ� ���� �����ֱ� ���ؼ�
		for(int i=pos+1 ; i<n ; i++)
		{
			// ���� ¦�� ������ ���� �����鼭 ģ���� �л��� ã�� ¦�� �����ش�
			if(!isMatched[i] && isFriend[pos][i])
			{
				// �������� ����Ž���� ����
				isMatched[pos]=isMatched[i]=true;
				ret+=solution(pos+1);
				isMatched[pos]=isMatched[i]=false;
			}
		}
		return ret;
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
		scanf("%d%d", &n, &m);
		memset(isFriend, false, sizeof(isFriend));
		while(m--)
		{
			scanf("%d%d", &u, &v);
			isFriend[u][v]=isFriend[v][u]=true;
		}

		int sol=solution(0);
		printf("%d\n", sol);
	}
}
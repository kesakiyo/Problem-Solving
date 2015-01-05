#include <cstdio>

int n, s, data[21];

// ��Ʈ��ŷ�� �̿��� Ǯ �� �ִ� ���� �⺻���� ����(���� ��ǲ�� ���� ��)
int solution(int pos, int sum)
{
	// pos�� n�� ��, �� ���°���Ʈ������ ���������� �������� ��
	if(pos==n)
	{
		// ���ݱ��� ���ؿ� ���� s�� ���ٸ� 1�� ��ȯ
		if(sum==s) return 1;

		// �ƴ϶�� 0�� ��ȯ
		return 0;
	}

	// ������ ���� ������ ���� �������� ���� ��츦 ���ѵ� ��ȯ
	return solution(pos+1, sum+data[pos]) + solution(pos+1, sum);
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &s);
	for(int i=0 ; i<n ; i++) scanf("%d", &data[i]);

	int sol=solution(0, 0);

	// ���� ã���ô� ���� 0�̶�� �����յ� ������ �����ϰ� �ǹǷ� 1�� ����
	if(s==0) sol--;

	printf("%d\n", sol);
}
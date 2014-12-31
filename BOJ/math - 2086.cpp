#include <cstdio>

typedef long long ll;

const ll MOD=1000000000;
ll a, b;

// ����� ������ �������ִ� �Լ�, 3�� ������ ���� ������ ������ �� �ִ�
void arrayMul(ll copy[][2], ll left[][2], ll right[][2])
{
	ll temp[2][2]={0, };

	for(int i=0 ; i<2 ; i++)
		for(int j=0 ; j<2 ; j++)
			for(int k=0 ; k<2 ; k++)
				temp[i][j]+=left[i][k]*right[k][j], temp[i][j]%=MOD;

	for(int i=0 ; i<2 ; i++)
		for(int j=0 ; j<2 ; j++)
			copy[i][j]=temp[i][j];
}

// ����� �ŵ����� ����� ������ ���ִ� �Լ�, Square and Multiply�� ����Ѵ�
void fastArrayMul(ll copy[][2], ll n)
{
	ll ret[2][2]={{1, 0}, {0, 1}}, mul[2][2]={{1, 1}, {1, 0}};

	while(n)
	{
		if(n&1) arrayMul(ret, ret, mul);
		arrayMul(mul, mul, mul);
		n>>=1;
	}

	for(int i=0 ; i<2 ; i++)
		for(int j=0 ; j<2 ; j++)
			copy[i][j]=ret[i][j];
}

// n��° �Ǻ���ġ ���� �����ִ� �Լ��̴�.
// {{1, 0}, {0, 1}}^n �� {{F(n+1), F(n)}, {F(n), F(n-1)} �� ��Ÿ����
// ������ n�� ����� ũ�Ƿ� ������ ������ fastArrayMul�Լ��� �̿��� O(logN)�� ����Ѵ�
ll getFibo(ll n)
{
	if(n==0) return 0;

	ll ret[2][2]={{1, 0}, {0, 1}};
	fastArrayMul(ret, n);

	return ret[0][1];
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%lld%lld", &a, &b);

	// a�׺��� b�ױ��� �Ǻ���ġ ���� ���� �����ش�.
	// sigma(1, n) : F(k) = F(n+2) - 1 �� �̿��Ѵ�
	// �� ������ �ͳ����� ������� ������ �� �ִ�
	// sigma(1, k+1) : F(k+1) �� sigma(1, k) : F(k) + F(n+1) �� �ȴ�.
	// �׷��ٸ� F(n+2) + F(n+1) - 1 �� ����� �ǰ� �� ������ F(n+3) - 1 �̵ȴ�.
	// sigma(1, n+1) : F(k) = F(n+3) - 1 �� ����� �ȴ�
	// �� ���� �̿��� 1�׺��� b�ױ��� ���� ��� �� �� �� ���� 1�׺��� a-1�ױ����� ���� ����� ����
	// a�׺��� b�ױ����� ���� �ȴ�.
	ll sol = getFibo(b+2) - getFibo(a-1+2);

	printf("%lld\n", (sol+MOD)%MOD);
}
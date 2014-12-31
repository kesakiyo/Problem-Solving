#include <cstdio>

typedef long long ll;

const ll MOD=1000000000;
ll a, b;

// 행렬의 곱셈을 진행해주는 함수, 3중 포문을 통해 간단히 구현할 수 있다
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

// 행렬의 거듭제곱 계산을 빠르게 해주는 함수, Square and Multiply를 사용한다
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

// n번째 피보나치 항을 구해주는 함수이다.
// {{1, 0}, {0, 1}}^n 은 {{F(n+1), F(n)}, {F(n), F(n-1)} 을 나타낸다
// 하지만 n이 상당히 크므로 위에서 정의한 fastArrayMul함수를 이용해 O(logN)에 계산한다
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

	// a항부터 b항까지 피보나치 수의 합을 구해준다.
	// sigma(1, n) : F(k) = F(n+2) - 1 을 이용한다
	// 위 수식은 귀납적인 방법으로 증명할 수 있다
	// sigma(1, k+1) : F(k+1) 은 sigma(1, k) : F(k) + F(n+1) 이 된다.
	// 그렇다면 F(n+2) + F(n+1) - 1 로 계산이 되고 이 수식은 F(n+3) - 1 이된다.
	// sigma(1, n+1) : F(k) = F(n+3) - 1 로 계산이 된다
	// 이 점을 이용해 1항부터 b항까지 합을 계산 한 뒤 이 값에 1항부터 a-1항까지의 합을 계산해 빼면
	// a항부터 b항까지의 합이 된다.
	ll sol = getFibo(b+2) - getFibo(a-1+2);

	printf("%lld\n", (sol+MOD)%MOD);
}
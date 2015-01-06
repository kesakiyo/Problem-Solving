#include <cstdio>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long ll;

ll data[5000010], cnt[10010], n, sum, avg, diff1, diff2;

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%lld", &n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%lld", &data[i]);

		// 해당 자연수가 1~10000 사이인 점을 이용해 counting sort방식을 사용한다
		cnt[data[i]]++;
		sum+=data[i];
	}
	avg=sum/n;

	int temp=0;
	for(int i=1 ; i<=10000 ; i++)
	{
		// 같은 수를 한 묶음으로 생각하고 중간에 오는 값이 무엇인지 찾는다
		temp+=cnt[i];
		if(temp*2>=n) 
		{
			printf("%d ", i);
			break;
		}
	}

	// 두 번째 대표 자연수는 주어진 수들의 평군이다
	// 두 번째 대표 자연수를 미지수로 두고 sigma 식을 계산 한다면
	// 그 미지수는 평균이 되어야 한다고 증명할 수 있다(사실 잘 모름, 듣기만 함)
	// 이 때 평균이 유리수가 될 수 있는데 avg와 avg+1 둘다 해보고 더 작은것을 출력한다
	for(int i=0 ; i<n ; i++)
	{
		diff1+=abs(data[i]-avg)*abs(data[i]-avg);
		diff2+=abs(data[i]-avg-1)*abs(data[i]-avg-1);
	}

	if(diff1<=diff2) printf("%lld\n", avg);
	else printf("%lld\n", avg+1);
}
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define	x	first
#define y	second

using namespace std;

int t, n;
vector< pair<int, int> > cor;

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		cor.clear();
		int mmin=987654321, mmax=0;
		scanf("%d", &n);

		cor.resize(n);
		for(int i=0 ; i<n ; i++) scanf("%d%d", &cor[i].x, &cor[i].y);
		sort(cor.begin(), cor.end());

		// 인풋이 작기때문에 딱히 신경을 써 줘야 할 게 없다
		// 그냥 사중포문으로 구현을 하면 된다
		for(int a=0 ; a<n ; a++) {
			for(int b=a+1 ; b<n ; b++) {
				for(int c=b+1 ; c<n ; c++) {
					for(int d=c+1 ; d<n ; d++) {
						// 선택한 네 점이 정사각형인지 확인을 한다
						// 정렬을 했기 때문에 점의 순서를 알 고 있다
						if(cor[a].x==cor[b].x && cor[c].x==cor[d].x
							&& cor[a].y==cor[c].y && cor[b].y==cor[d].y) {
							int width=cor[c].x-cor[a].x, height=cor[b].y-cor[a].y;
							if(width==height) {
								mmin=min(mmin, width);
								mmax=max(mmax, width);
							}
						}	
					}
				}
			}
		}

		printf("%d %d\n", mmin, mmax);
	}
}
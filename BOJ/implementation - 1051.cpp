#include <cstdio>
#include <algorithm>

using namespace std;

int row, col;
char data[52][52];

// 네 개의 문자가 같은지 반환하는 함수
bool isSame(char a, char b, char c, char d)
{
	return a==b && b==c && c==d;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &row, &col);
	for(int i=0 ; i<row ; i++) scanf("%s", data[i]);

	int sol=0;

	// 전체탐색을 이용해 풀 수 있는 전형적인 문제
	// 한 변의 길이가 1인 정사각형, 즉 한개의 수로 이루어진 정사각형은 무조건 만들 수 있으므로
	// 처음 시작은 한 변의 길이가 2인 정사각형부터 시작을 한다
	// 정사각형의 길이를 정해두고(이 떄 정사가형의 최대 변의 길이는 row와 col중에 작은것이 됨은 자명한 사실이다)
	// 가능한 모든 시작점을 탐색해 네 꼭지점이 같을때만 sol을 초기화 시켜준다
	// O(n^3)의 솔루션이지만 n이 50밖에 안되기 때문에 충분히 시간내에 풀 수 있는 솔루션이다
	for(int len=1 ; len<min(row, col) ; len++)
		for(int x=0 ; x<row-len ; x++)
			for(int y=0 ; y<col-len ; y++)
				if(isSame(data[x][y], data[x+len][y], data[x][y+len], data[x+len][y+len]))
					sol=len;

	printf("%d\n", (sol+1)*(sol+1));
}
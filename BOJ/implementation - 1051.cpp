#include <cstdio>
#include <algorithm>

using namespace std;

int row, col;
char data[52][52];

// �� ���� ���ڰ� ������ ��ȯ�ϴ� �Լ�
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

	// ��üŽ���� �̿��� Ǯ �� �ִ� �������� ����
	// �� ���� ���̰� 1�� ���簢��, �� �Ѱ��� ���� �̷���� ���簢���� ������ ���� �� �����Ƿ�
	// ó�� ������ �� ���� ���̰� 2�� ���簢������ ������ �Ѵ�
	// ���簢���� ���̸� ���صΰ�(�� �� ���簡���� �ִ� ���� ���̴� row�� col�߿� �������� ���� �ڸ��� ����̴�)
	// ������ ��� �������� Ž���� �� �������� �������� sol�� �ʱ�ȭ �����ش�
	// O(n^3)�� �ַ�������� n�� 50�ۿ� �ȵǱ� ������ ����� �ð����� Ǯ �� �ִ� �ַ���̴�
	for(int len=1 ; len<min(row, col) ; len++)
		for(int x=0 ; x<row-len ; x++)
			for(int y=0 ; y<col-len ; y++)
				if(isSame(data[x][y], data[x+len][y], data[x][y+len], data[x+len][y+len]))
					sol=len;

	printf("%d\n", (sol+1)*(sol+1));
}
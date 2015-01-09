#include <iostream>
#define PREORDER	1
#define	INORDER		2
#define	POSTORDER	3

using namespace std;

int n;
char node[26][2];

// ��ȸ �κ��� �װ� ������ �� ���� ����
// �ٸ� ���¸� ��Ÿ���� ������ ���� �Ѱ��� �Լ���
// ��ȸ ������ ��� ����� �� �ֵ��� ����� �� �� �ִ�
void treversal(const char& here, const int& state)
{
	// ���� ��������� �Լ� ����
	if(here=='.') return;

	// ������ȸ �� ���
	if(state==PREORDER) cout<<here;

	// ���� �ڽ� ȣ��
	treversal(node[here-'A'][0], state);

	// ������ȸ �� ���
	if(state==INORDER) cout<<here;

	// ������ �ڽ� ȣ��
	treversal(node[here-'A'][1], state);

	// ������ȸ �� ���
	if(state==POSTORDER) cout<<here;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin>>n;

	// �� �������� ������ �� �κ��� Ʈ���� ��� �����ϳ� �̴�
	// ���ĺ� �빮�ڰ� �����ϰ� ������ ������ 0������ 25������
	// �ε����� �ڽ��� ���� ��ġ���� ������ �� �ִ�.
	// ���� ������ �迭�� �̿��� ù��°�� ���� �ڽ�, �ι�°�� ������ �ڽ�����
	// ǥ���� �����ϰ� Ʈ���� ������ �� �ִ�
	for(int i=0 ; i<n ; i++)
	{
		char e, l, r;
		cin>>e>>l>>r;
		node[e-'A'][0]=l;
		node[e-'A'][1]=r;
	}

	// ��� ��� �κ�
	treversal('A', PREORDER); cout<<endl;
	treversal('A', INORDER); cout<<endl;
	treversal('A', POSTORDER); cout<<endl;
}
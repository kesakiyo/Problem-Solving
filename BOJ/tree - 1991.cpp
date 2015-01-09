#include <iostream>
#define PREORDER	1
#define	INORDER		2
#define	POSTORDER	3

using namespace std;

int n;
char node[26][2];

// 순회 부분은 그게 눈여겨 볼 곳이 없음
// 다만 상태를 나타내는 변수를 통해 한개의 함수로
// 순회 세개를 모두 출력할 수 있도록 만들어 줄 수 있다
void treversal(const char& here, const int& state)
{
	// 만약 리프노드라면 함수 종료
	if(here=='.') return;

	// 전위순회 시 출력
	if(state==PREORDER) cout<<here;

	// 왼쪽 자식 호출
	treversal(node[here-'A'][0], state);

	// 중위순회 시 출력
	if(state==INORDER) cout<<here;

	// 오른쪽 자식 호출
	treversal(node[here-'A'][1], state);

	// 후위순회 시 출력
	if(state==POSTORDER) cout<<here;
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin>>n;

	// 이 문제에서 눈여겨 볼 부분은 트리를 어떻게 구성하냐 이다
	// 알파벳 대문자가 고유하게 들어오기 때문에 0번부터 25번까지
	// 인덱스를 자신의 고유 위치가로 생각할 수 있다.
	// 따라서 이차원 배열을 이용해 첫번째는 왼쪽 자식, 두번째는 오른쪽 자식으로
	// 표현해 간단하게 트리를 구성할 수 있다
	for(int i=0 ; i<n ; i++)
	{
		char e, l, r;
		cin>>e>>l>>r;
		node[e-'A'][0]=l;
		node[e-'A'][1]=r;
	}

	// 답안 출력 부분
	treversal('A', PREORDER); cout<<endl;
	treversal('A', INORDER); cout<<endl;
	treversal('A', POSTORDER); cout<<endl;
}
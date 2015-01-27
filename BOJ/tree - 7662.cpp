#include <stdio.h>
#include <map>

using namespace std;

int t, n, d;
char q;

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while(t--) {
		// 최솟값과 최댓값에 손쉽게 접근할 수 있게 BST를 이용한다
		// 중복된 값이 들어올 수 있으므로 set을 사용하면 안된다
		// multiset을 사용할수도 있겠지만 map을 이용해 중복된 수들을 효율적으로 관리한다
		map<int, int> data;
		scanf("%d", &n);
		while(n--) {
			getchar();
			scanf("%c %d", &q, &d);

			// insert 질의라면 key 'd'의 value값을 1 증가시켜준다
			if(q=='I') data[d]++;

			// delete 질의
			else {
				// map이 비어있다면 질의 무시
				if(data.empty()) continue;

				// map이 비어있지 않다면
				else {
					map<int, int>::iterator it;

					// 최솟값을 삭제시키는 질의라면 이터레이터는 begin을
					if(d==-1) it=data.begin();

					// 최댓값을 삭제시키는 질의라면 end에서 --연산을 실행
					// end는 개행구간이기 때문에 꼭 감소를 한번 해 줘야 한다
					else it=--data.end();

					// 해당 key값의 value를 1 감소시켜 준다.
					// 만약 value가 0이 되었다는 말은 그 수가 완전히 사라졌단 얘기이므로
					// map에서 삭제를 시켜준다
					if(--it->second==0) data.erase(it);
				}
			}
		}

		// 출력부분. rbegin은 reverse begin의 뜻
		if(data.empty()) puts("EMPTY");
		else printf("%d %d\n", data.rbegin()->first, data.begin()->first);
	}
}
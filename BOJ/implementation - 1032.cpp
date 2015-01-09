#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int n;
vector<string> data;

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin>>n;

	// 입력받은 크기만큼 벡터를 리사이즈 시켜준다
	data.resize(n);
	for(int i=0 ; i<n ; i++) cin>>data[i];

	// 각각의 문자열들의 열에있는 문자들이 두개 이상인지 확인
	for(int i=0 ; i<data[0].size() ; i++)
	{
		// STL set을 사용하면 쉽게 답을 구할 수 있다
		// 동일한 원소가 중복되서 삽입이 되지 않아 중복된것을 걸러내는데 유용하게 사용
		// 사용방법은 cplusplus.com 에서 찾아볼 수 있다
		set<char> cnt;

		// 각각의 행을 돌며 문자를 뽑아 set 에 집어 넣는다
		for(int j=0 ; j<n ; j++) cnt.insert(data[j][i]);

		// 만약 set의 크기가 1이라면 한 문자만 등장한 것이므로 해당 문자를 출력하고
		// 아니라면 물음표를 출력한다
		if(cnt.size()==1) cout<<*cnt.begin();
		else cout<<"?";
	}
	cout<<endl;
}
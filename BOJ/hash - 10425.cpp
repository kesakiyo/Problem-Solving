#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

map< pair<ll, ll>, int > HashTable;
const ll MOD1=1000000000;
const ll MOD2=10000000000;
int t;
string str;

// 피보나치 수의 해쉬값을 계산해 주는 함수
// 이렇게 큰 수들에 대해서 한가지 해쉬값을 취하면 충돌의 확률이 크기 때문에
// 이중 해쉬를 사용하여 충돌 확률을 줄인다
// 첫 번째 해쉬는 10억으로 모듈러 연산을 한 값
// 두 번째 해쉬는 100억으로 모듈러 연산을 한 값을 취한다
// 충돌이 날 까 걱정을 했지만 의외로 충돌이 한 개도 안일어 나는것을 볼 수 있었다
void makeHashTable()
{
	pair<ll, ll> fibo[100010];
	fibo[0]=make_pair(0, 0);
	fibo[1]=make_pair(1, 1);
	for(int i=2 ; i<=100000 ; i++)
	{
		// 첫 번째와 두 번째 값을 계산해 준다
		// 계속해서 모듈러 연산을 누적해도 되는 것은 정수론 시간에 배웠다
		fibo[i].first=fibo[i-1].first+fibo[i-2].first;
		fibo[i].second=fibo[i-1].second+fibo[i-2].second;
		fibo[i].first%=MOD1; fibo[i].second%=MOD2;

		// 충돌이 일어난다면 이 부분이 실행이 될 것이다
		// 하지만 한번도 실행이 안된것으로 보아 충돌이 일어나지 않는다는 것을 알 수 있다
		if(HashTable.count(make_pair(fibo[i].first, fibo[i].second))) cout<<"Collision!!"<<endl;

		// 이렇게 생성된 두 해쉬값을 pair로 만든 뒤 key값으로 지정, value값은 피보나치 수의 항의 값으로 저장한다
		HashTable[make_pair(fibo[i].first, fibo[i].second)]=i;
	}
}

// 상당히 긴 수가 들어오기 때문에 적절하게 데이터를 파싱해줄 필요가 있다
pair<ll, ll> getHashValue(const string& str)
{
	// 예외처리를 하기 귀찮으므로 앞쪽에 11자리 이상의 0을 붙여놓도록 한다
	string numString = "000000000000" + str;
	ll num=0;

	// 뒤에서부터 12자리 수를 계산해 준다
	for(int i=numString.size()-12 ; i<numString.size() ; i++)
	{
		num*=10;
		num+=numString[i]-'0';
	}

	// 그 수의 두 해쉬값을 구해 반환한다
	return make_pair(num%MOD1, num%MOD2);
}

int main(void)
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	makeHashTable();

	cin>>t;
	while(t--)
	{
		cin>>str;

		// 만약 1이라면 2를 출력하도록 예외처리를 해 주고
		// 아니라면 해쉬값을 찾아 피보나치 항을 출력하도록 한다
		if(str=="1") cout<<2<<endl;
		else cout<<HashTable[getHashValue(str)]<<endl;
	}
}

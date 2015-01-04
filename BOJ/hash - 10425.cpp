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

// �Ǻ���ġ ���� �ؽ����� ����� �ִ� �Լ�
// �̷��� ū ���鿡 ���ؼ� �Ѱ��� �ؽ����� ���ϸ� �浹�� Ȯ���� ũ�� ������
// ���� �ؽ��� ����Ͽ� �浹 Ȯ���� ���δ�
// ù ��° �ؽ��� 10������ ��ⷯ ������ �� ��
// �� ��° �ؽ��� 100������ ��ⷯ ������ �� ���� ���Ѵ�
// �浹�� �� �� ������ ������ �ǿܷ� �浹�� �� ���� ���Ͼ� ���°��� �� �� �־���
void makeHashTable()
{
	pair<ll, ll> fibo[100010];
	fibo[0]=make_pair(0, 0);
	fibo[1]=make_pair(1, 1);
	for(int i=2 ; i<=100000 ; i++)
	{
		// ù ��°�� �� ��° ���� ����� �ش�
		// ����ؼ� ��ⷯ ������ �����ص� �Ǵ� ���� ������ �ð��� �����
		fibo[i].first=fibo[i-1].first+fibo[i-2].first;
		fibo[i].second=fibo[i-1].second+fibo[i-2].second;
		fibo[i].first%=MOD1; fibo[i].second%=MOD2;

		// �浹�� �Ͼ�ٸ� �� �κ��� ������ �� ���̴�
		// ������ �ѹ��� ������ �ȵȰ����� ���� �浹�� �Ͼ�� �ʴ´ٴ� ���� �� �� �ִ�
		if(HashTable.count(make_pair(fibo[i].first, fibo[i].second))) cout<<"Collision!!"<<endl;

		// �̷��� ������ �� �ؽ����� pair�� ���� �� key������ ����, value���� �Ǻ���ġ ���� ���� ������ �����Ѵ�
		HashTable[make_pair(fibo[i].first, fibo[i].second)]=i;
	}
}

// ����� �� ���� ������ ������ �����ϰ� �����͸� �Ľ����� �ʿ䰡 �ִ�
pair<ll, ll> getHashValue(const string& str)
{
	// ����ó���� �ϱ� �������Ƿ� ���ʿ� 11�ڸ� �̻��� 0�� �ٿ������� �Ѵ�
	string numString = "000000000000" + str;
	ll num=0;

	// �ڿ������� 12�ڸ� ���� ����� �ش�
	for(int i=numString.size()-12 ; i<numString.size() ; i++)
	{
		num*=10;
		num+=numString[i]-'0';
	}

	// �� ���� �� �ؽ����� ���� ��ȯ�Ѵ�
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

		// ���� 1�̶�� 2�� ����ϵ��� ����ó���� �� �ְ�
		// �ƴ϶�� �ؽ����� ã�� �Ǻ���ġ ���� ����ϵ��� �Ѵ�
		if(str=="1") cout<<2<<endl;
		else cout<<HashTable[getHashValue(str)]<<endl;
	}
}

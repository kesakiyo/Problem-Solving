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

	// �Է¹��� ũ�⸸ŭ ���͸� �������� �����ش�
	data.resize(n);
	for(int i=0 ; i<n ; i++) cin>>data[i];

	// ������ ���ڿ����� �����ִ� ���ڵ��� �ΰ� �̻����� Ȯ��
	for(int i=0 ; i<data[0].size() ; i++)
	{
		// STL set�� ����ϸ� ���� ���� ���� �� �ִ�
		// ������ ���Ұ� �ߺ��Ǽ� ������ ���� �ʾ� �ߺ��Ȱ��� �ɷ����µ� �����ϰ� ���
		// ������� cplusplus.com ���� ã�ƺ� �� �ִ�
		set<char> cnt;

		// ������ ���� ���� ���ڸ� �̾� set �� ���� �ִ´�
		for(int j=0 ; j<n ; j++) cnt.insert(data[j][i]);

		// ���� set�� ũ�Ⱑ 1�̶�� �� ���ڸ� ������ ���̹Ƿ� �ش� ���ڸ� ����ϰ�
		// �ƴ϶�� ����ǥ�� ����Ѵ�
		if(cnt.size()==1) cout<<*cnt.begin();
		else cout<<"?";
	}
	cout<<endl;
}
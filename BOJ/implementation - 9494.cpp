#include <string>
#include <iostream>
 
using namespace std;
 
int n;
 
int main(void)
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>n && n)
    {
        string str;
        int sol=0;
 
		// �Է� ���ۿ� ���� ���ڰ� �����ֱ� ������ �Է¹��۸� ����ش�
        cin.ignore(1, '\n');

        for(int i=0 ; i<n ; i++)
        {
			// �� �ٿ� ȭ��Ʈ �����̽��� ���� �� �����Ƿ� getline�� ���� ���ڿ��� �޾��ش�
            getline(cin, str);

			// ���������� ���� ������ ��ġ�� ���� ���� ���ڿ��� ���̺��� ũ�ٸ� continue
            if(sol>=str.size()) continue;

			// ���� ������ ��ġ�� ����, ������ ���鹮�ڰ� ���� ó�� �����ϴ��� ã�´�
            int s=str.find(' ', sol);

			// s�� ���� -1�̶�� ���鹮�ڰ� ���ٴ� ���̹Ƿ� ���� ���ڿ��� ���̸�, �ƴ϶�� s�� sol�� �����Ѵ�
            sol = s==-1 ? str.size() : s;
        }

		// ������ ����� 1�� ���ؼ� ����Ѵ�, ó�� ��ġ�� 0�� �ƴ϶� 1�̶�� �������� ��ð� �Ǿ��ֱ� ����
        cout<<sol+1<<endl;
    }
}
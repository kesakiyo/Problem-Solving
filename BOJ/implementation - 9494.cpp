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
 
		// 입력 버퍼에 개행 문자가 남아있기 때문에 입력버퍼를 비워준다
        cin.ignore(1, '\n');

        for(int i=0 ; i<n ; i++)
        {
			// 한 줄에 화이트 스페이스가 있을 수 있으므로 getline을 통해 문자열을 받아준다
            getline(cin, str);

			// 마지막으로 공이 떨어진 위치가 현재 받은 문자열의 길이보다 크다면 continue
            if(sol>=str.size()) continue;

			// 현재 떨어진 위치를 포함, 앞으로 공백문자가 언제 처음 등장하는지 찾는다
            int s=str.find(' ', sol);

			// s가 만약 -1이라면 공백문자가 없다는 뜻이므로 현재 문자열의 길이를, 아니라면 s를 sol에 대입한다
            sol = s==-1 ? str.size() : s;
        }

		// 마지막 출력은 1을 더해서 출력한다, 처음 위치가 0이 아니라 1이라고 문제에서 명시가 되어있기 때문
        cout<<sol+1<<endl;
    }
}